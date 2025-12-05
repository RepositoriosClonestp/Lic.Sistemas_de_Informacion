// Correlativas: muestra materias desde Planes Vigentes y permite marcar estado
// Estados: 0 = No Cursada, 1 = En Curso, 2 = Regular, 3 = Aprobada

const DEFAULT_REPO_CORR = 'RepositoriosClonestp/Lic.Sistemas_de_Informacion';
const CORRELATIVAS_FILE = 'correlativas.json';

let correlativasConfig = {};
const DEBUG_PARSE = false; // pon true para ver logs de parseo en consola

document.addEventListener('DOMContentLoaded', () => {
  const corrList = document.getElementById('corrList');
  const planSelectContainer = document.getElementById('planSelectContainer');
  const statsContainer = document.getElementById('statsContainer');
  const filterContainer = document.getElementById('filterContainer');
  const actionButtons = document.getElementById('actionButtons');

  let currentPlan = null;
  let allMaterias = [];

  // Cargar planes disponibles automáticamente
  loadPlanes();

  async function loadPlanes() {
    planSelectContainer.innerHTML = '<p class="muted">Cargando planes disponibles…</p>';
    try {
      const [owner, repo] = DEFAULT_REPO_CORR.split('/');
      
      let items;
      try {
        items = await listContents(owner, repo, 'Planes Vigentes');
      } catch (e) {
        try {
          items = await listContents(owner, repo, 'Planes_Vigentes');
        } catch (e2) {
          const rootItems = await listContents(owner, repo, '');
          throw new Error('No se encontró la carpeta de planes. Carpetas disponibles: ' + rootItems.filter(x => x.type === 'dir').map(x => x.name).join(', '));
        }
      }
      
      const planes = Array.isArray(items) 
        ? items.filter(x => x.type === 'file' && x.name.toLowerCase().endsWith('.md')) 
        : [];
      
      if (planes.length === 0) {
        planSelectContainer.innerHTML = '<p class="muted">No se encontraron archivos de planes (.md) en la carpeta.</p>';
        return;
      }

      planSelectContainer.innerHTML = '';
      const wrapper = createEl('div', {class: 'plan-select-wrapper'});
      const label = createEl('label', {}, 'Plan de estudios:');
      const select = createEl('select', {id: 'planSelect', class: 'plan-select'});
      const defaultOpt = new Option('-- Selecciona un plan --', '');
      select.add(defaultOpt);
      
      planes.forEach(plan => {
        const opt = new Option(plan.name.replace('.md', ''), plan.path);
        // guardamos también el objeto plan en dataset para poder recuperar url más adelante
        opt.dataset.apiUrl = plan.url || plan.download_url || '';
        select.add(opt);
      });

      select.addEventListener('change', () => {
        if (select.value) {
          const selected = Array.from(select.options).find(o => o.value === select.value);
          const selectedPlan = { name: select.options[select.selectedIndex].text + '.md', url: selected.dataset.apiUrl, path: select.value };
          loadPlanContent(DEFAULT_REPO_CORR.split('/')[0], DEFAULT_REPO_CORR.split('/')[1], selectedPlan);
        } else {
          corrList.innerHTML = '<p class="muted">Selecciona un plan para ver las materias.</p>';
          hideControls();
        }
      });

      wrapper.append(label, select);
      planSelectContainer.appendChild(wrapper);
      corrList.innerHTML = '<p class="muted">Selecciona un plan para ver las materias.</p>';

    } catch (err) {
      planSelectContainer.innerHTML = `<p class="muted">Error al cargar planes: ${err.message}</p>`;
      console.error('Error detallado:', err);
    }
  }

  function storageKey(owner, repo, planName) {
    return `correlativas:${owner}/${repo}:${planName}`;
  }

  async function loadPlanContent(owner, repo, plan) {
    corrList.innerHTML = '<p class="muted">Cargando contenido del plan…</p>';
    try {
      // Cargar markdown del plan
      let content = '';
      if (plan.url) {
        const res = await fetch(plan.url);
        if (!res.ok) throw new Error(`HTTP ${res.status}`);
        const data = await res.json();
        content = data.encoding === 'base64' ? atob(data.content.replace(/\n/g, '')) : data.content;
      } else {
        throw new Error('URL del plan no disponible (recarga la página).');
      }

      // Cargar correlativas.json (opcional)
      correlativasConfig = await loadCorrelativasConfig(owner, repo).catch(() => ({}));

      currentPlan = {owner, repo, name: plan.name};
      parseAndDisplayPlan(owner, repo, plan.name, content);
      showControls();

    } catch (err) {
      corrList.innerHTML = `<p class="muted">Error al cargar el plan: ${err.message}</p>`;
    }
  }

  async function loadCorrelativasConfig(owner, repo) {
    const url = `https://api.github.com/repos/${owner}/${repo}/contents/${CORRELATIVAS_FILE}`;
    const res = await fetch(url);
    if (!res.ok) throw new Error('Sin correlativas.json');
    const data = await res.json();
    const raw = data.encoding === 'base64' ? atob(data.content.replace(/\n/g,'')) : data.content;
    return JSON.parse(raw);
  }

  function parseAndDisplayPlan(owner, repo, planName, content) {
    corrList.innerHTML = '';
    allMaterias = [];
    const savedRaw = localStorage.getItem(storageKey(owner, repo, planName));
    const saved = savedRaw ? JSON.parse(savedRaw) : {};

    const lines = content.split('\n');
    let currentYear = null;
    let currentCuat = null;
    let yearBlock = null;
    let cuatDiv = null;

    function flushCuatToYear() {
      if (cuatDiv && yearBlock) {
        yearBlock.appendChild(cuatDiv);
        cuatDiv = null;
      }
    }
    function flushYearToList() {
      if (yearBlock) {
        corrList.appendChild(yearBlock);
        yearBlock = null;
      }
    }

    for (let i = 0; i < lines.length; i++) {
      let line = lines[i];
      let trimmed = line.trim();
      if (!trimmed || trimmed.startsWith('<!--') || trimmed.startsWith('-->')) continue;

      // Detect headings (flexible): '#', or lines that contain 'Año' or 'Cuatrimestre' even without '#'
      const isHashHeading = /^#{1,6}\s+/.test(trimmed);
      if (isHashHeading) {
        const plain = trimmed.replace(/^#{1,6}\s+/, '');
        if (/año/i.test(plain) || /\b\d+\s*[º°]?\b/.test(plain) && /año/i.test(plain.toLowerCase()) ) {
          // Año heading
          flushCuatToYear();
          flushYearToList();
          yearBlock = createEl('div', {class:'year-block'});
          const yearTitle = createEl('h3', {}, plain);
          yearBlock.appendChild(yearTitle);
          currentYear = plain;
          currentCuat = null;
          if (DEBUG_PARSE) console.log('Detected year (hash):', plain);
          continue;
        }
        if (/cuatrimestre/i.test(plain) || /cuatri/i.test(plain)) {
          // Cuatrimestre heading
          flushCuatToYear();
          if (!yearBlock) yearBlock = createEl('div', {class:'year-block'});
          cuatDiv = createEl('div', {class:'cuatrimestre'});
          const cuatTitle = createEl('h4', {}, plain);
          cuatDiv.appendChild(cuatTitle);
          currentCuat = plain;
          if (DEBUG_PARSE) console.log('Detected cuat (hash):', plain);
          continue;
        }
      }

      // Non-hash headings: loose detection like "1° Año" or "Año 1" or "1° Cuatrimestre"
      if (!isHashHeading) {
        if (/^\d+\s*[º°]?\s*(año|Año)\b|^Año\b/i.test(trimmed) || (/año/i.test(trimmed) && trimmed.length < 40)) {
          // Año detected
          flushCuatToYear();
          flushYearToList();
          yearBlock = createEl('div', {class:'year-block'});
          const yearTitle = createEl('h3', {}, trimmed);
          yearBlock.appendChild(yearTitle);
          currentYear = trimmed;
          currentCuat = null;
          if (DEBUG_PARSE) console.log('Detected year (loose):', trimmed);
          continue;
        }
        if (/cuatrimestre|cuatri|cuatrim/i.test(trimmed) && trimmed.length < 40) {
          // Cuatrimestre detected
          flushCuatToYear();
          if (!yearBlock) yearBlock = createEl('div', {class:'year-block'});
          cuatDiv = createEl('div', {class:'cuatrimestre'});
          const cuatTitle = createEl('h4', {}, trimmed);
          cuatDiv.appendChild(cuatTitle);
          currentCuat = trimmed;
          if (DEBUG_PARSE) console.log('Detected cuat (loose):', trimmed);
          continue;
        }
      }

      // Try to detect materia lines:
      // bullets: - *, +, •, –, — or numbered lists "1." "1)"
      let materiaName = null;
      let m;
      m = trimmed.match(/^[-*+\u2022\u2013\u2014]\s+(.+)$/); // - * + • – —
      if (!m) m = trimmed.match(/^\d+[\.\)]\s+(.+)$/); // 1. or 1)
      if (!m) m = trimmed.match(/^\*\*(.+?)\*\*$/); // **Nombre**
      if (m) materiaName = m[1].trim();
      else {
        // If inside a cuatrimestre block and the line looks like a title (not metadata), accept it.
        // Heuristic: starts with letter (may be uppercase) and length between 3 and 120 and doesn't contain ':' alone
        if (currentYear && currentCuat && /^[A-Za-zÁÉÍÓÚÜÑáéíóúñ0-9].{2,120}$/.test(trimmed) && !/^[-*_]{3,}/.test(trimmed)) {
          // Avoid lines that look like "Cuatrimestral · 128h" by checking for keywords
          if (!/cuatrimestral|cuatrimestral|128h|horas|h\b|prerrequisito|correlativa/i.test(trimmed)) {
            materiaName = trimmed;
          } else if (DEBUG_PARSE) {
            if (DEBUG_PARSE) console.log('Skipped probable metadata line:', trimmed);
          }
        }
      }

      if (materiaName && currentYear && currentCuat) {
        materiaName = cleanMateriaName(materiaName);
        const matKey = `${currentYear}::${currentCuat}::${materiaName}`;
        const value = saved[matKey] !== undefined ? saved[matKey] : 0;

        if (!yearBlock) yearBlock = createEl('div', {class:'year-block'});
        if (!cuatDiv) {
          cuatDiv = createEl('div', {class:'cuatrimestre'});
          const cuatTitle = createEl('h4', {}, currentCuat);
          cuatDiv.appendChild(cuatTitle);
        }

        allMaterias.push({
          year: currentYear,
          cuatrimestre: currentCuat,
          name: materiaName,
          key: matKey,
          status: value
        });

        const row = createMateriaRow(materiaName, matKey, value, saved, owner, repo, planName);
        cuatDiv.appendChild(row);
        if (DEBUG_PARSE) console.log('Added materia:', materiaName, 'key:', matKey);
        continue;
      }

      // If we reach here and DEBUG_PARSE true, log the line so you can inspect what wasn't matched
      if (DEBUG_PARSE) console.log('Unmatched line:', trimmed);
    } // end for

    // flush last blocks
    if (cuatDiv && yearBlock) yearBlock.appendChild(cuatDiv);
    if (yearBlock) corrList.appendChild(yearBlock);

    if (!corrList.children.length) {
      corrList.innerHTML = '<p class="muted">No se pudieron procesar las materias del plan seleccionado.</p>';
      if (DEBUG_PARSE) console.warn('parseAndDisplayPlan: no children appended. Revisa el formato del markdown.');
    }

    updateStats();
  }

  function cleanMateriaName(name) {
    // remove markdown emphasis and trailing metadata separators
    let s = name.replace(/[_*~`]+/g, '').trim();
    // remove content after separators like " - ", " — ", " – ", " | ", " · "
    s = s.replace(/\s*[–—|-]\s*.+$/,'');
    s = s.replace(/\s*\|\s*.+$/,'');
    s = s.replace(/\s*·\s*.+$/,'');
    // remove trailing parenthesized metadata like "(128h)"
    s = s.replace(/\s*\(.*?\)\s*$/,'').trim();
    return s;
  }

  function createMateriaRow(materiaName, matKey, value, saved, owner, repo, planName) {
    const row = createEl('div', {class:'materia-card', 'data-status': value});
    const header = createEl('div', {class:'materia-header'});
    const title = createEl('h5', {class:'materia-title'}, materiaName);

    // Badges Año / Cuatrimestre (derivadas de key)
    const [year, cuat] = matKey.split('::');
    const badgesRow = createEl('div', {class:'badges-row'});
    badgesRow.append(
      createEl('span', {class:'badge year-badge'}, year),
      createEl('span', {class:'badge cuat-badge'}, cuat)
    );

    // Horas (si definidas)
    const horas = correlativasConfig[materiaName]?.horas;
    if (horas) badgesRow.append(createEl('span', {class:'badge horas-badge'}, `${horas}h`));

    header.append(title, badgesRow);

    const body = createEl('div', {class:'materia-body'});

    // Bloques de correlativas
    const prereqBlock = createEl('div', {class:'prereq-blocks'});

    const cursarReqs = correlativasConfig[materiaName]?.cursar || [];
    const rendirReqs = correlativasConfig[materiaName]?.rendir || [];

    const cursarDiv = buildPrereqGroup('Cursar', cursarReqs);
    const rendirDiv = buildPrereqGroup('Rendir', rendirReqs);

    if (cursarReqs.length) prereqBlock.appendChild(cursarDiv);
    if (rendirReqs.length) prereqBlock.appendChild(rendirDiv);

    body.appendChild(prereqBlock);

    const controls = createEl('div', {class: 'materia-controls'});
    const buttonGroup = createEl('div', {class: 'status-buttons'});

    const states = [
      {value: 0, label: 'No', class: 'no-cursada'},
      {value: 1, label: 'Curso', class: 'en-curso'},
      {value: 2, label: 'Reg', class: 'regular'},
      {value: 3, label: 'Apro', class: 'aprobada'}
    ];

    states.forEach(state => {
      const btn = createEl('button', {
        class: `status-btn ${state.class} ${value === state.value ? 'active' : ''}`,
        title: state.label
      }, state.label);

      btn.addEventListener('click', () => {
        // Validación de correlativas
        if (state.value === 1 && !canCursar(materiaName)) {
          alert('No habilitada para cursar: falta correlativa.');
          return;
        }
        if ((state.value === 2 || state.value === 3) && !canRendir(materiaName)) {
          alert('No habilitada para rendir: falta correlativa.');
          return;
        }

        saved[matKey] = state.value;
        try { localStorage.setItem(storageKey(owner, repo, planName), JSON.stringify(saved)); } catch(e){}
        row.querySelectorAll('.status-btn').forEach(b => b.classList.remove('active'));
        btn.classList.add('active');
        row.setAttribute('data-status', state.value);
        const materia = allMaterias.find(m => m.key === matKey);
        if (materia) materia.status = state.value;
        refreshPrereqLocks(row, materiaName);
        updateStats();
        applyFilters();
      });

      buttonGroup.appendChild(btn);
    });

    controls.appendChild(buttonGroup);

    // Campo notas (opcional)
    const note = createEl('input', {
      type:'text',
      class:'nota-input',
      placeholder:'Notas/fecha de examen'
    });
    controls.appendChild(note);

    row.append(header, body, controls);

    // Inicializar estado de candados
    refreshPrereqLocks(row, materiaName);

    return row;
  }

  function buildPrereqGroup(label, reqs) {
    const wrapper = createEl('div', {class:'prereq-group'});
    const title = createEl('div', {class:'prereq-title'}, label + ':');
    const list = createEl('div', {class:'prereq-list'});
    reqs.forEach(r => {
      const item = createEl('span', {
        class:'prereq-item locked',
        'data-materia': r.materia,
        'data-estado': r.estado
      }, `${r.materia} (${r.estado})`);
      list.appendChild(item);
    });
    wrapper.append(title, list);
    return wrapper;
  }

  function estadoNumericoToNombre(num) {
    switch(num){
      case 0: return 'no';
      case 1: return 'en curso';
      case 2: return 'regular';
      case 3: return 'aprobada';
      default: return '';
    }
  }

  function getStatusOf(materiaName) {
    const found = allMaterias.find(m => m.name === materiaName);
    return found ? found.status : 0;
  }

  function canCursar(materiaName) {
    const reqs = correlativasConfig[materiaName]?.cursar || [];
    return reqs.every(r => checkReq(r));
  }

  function canRendir(materiaName) {
    const reqs = correlativasConfig[materiaName]?.rendir || [];
    return reqs.every(r => checkReq(r));
  }

  function checkReq(req) {
    const st = getStatusOf(req.materia);
    // Map texto a mínimo numérico requerido
    const needed = req.estado === 'regular' ? 2
                 : req.estado === 'aprobada' ? 3
                 : req.estado === 'en curso' ? 1
                 : 0;
    return st >= needed;
  }

  function refreshPrereqLocks(row, materiaName) {
    const items = row.querySelectorAll('.prereq-item');
    items.forEach(it => {
      const mat = it.getAttribute('data-materia');
      const est = it.getAttribute('data-estado');
      const ok = checkReq({materia: mat, estado: est});
      it.classList.toggle('locked', !ok);
      it.classList.toggle('unlocked', ok);
    });
  }

  function showControls() {
    // Filtros
    if (!filterContainer.querySelector('.filter-wrapper')) {
      const filterWrapper = createEl('div', {class: 'filter-wrapper'});
      const filterLabel = createEl('label', {}, 'Filtrar por estado:');
      const filterCheckbox = createEl('input', {type: 'checkbox', id: 'soloHabilitadas'});
      const filterLabelText = createEl('label', {for: 'soloHabilitadas'}, ' Solo materias habilitadas');
      
      filterCheckbox.addEventListener('change', applyFilters);
      
      filterWrapper.append(filterLabel, filterCheckbox, filterLabelText);
      filterContainer.appendChild(filterWrapper);
    }

    // Botones de acción
    if (!actionButtons.querySelector('.action-buttons')) {
      const btnWrapper = createEl('div', {class: 'action-buttons'});
      
      const btnGuardar = createEl('button', {class: 'btn primary'}, '💾 Guardar');
      const btnReiniciar = createEl('button', {class: 'btn'}, '🔄 Reiniciar');
      const btnExportar = createEl('button', {class: 'btn'}, '📥 Exportar JSON');
      const btnImportar = createEl('button', {class: 'btn'}, '📤 Importar JSON');
      
      btnGuardar.addEventListener('click', () => alert('Los cambios se guardan automáticamente en localStorage'));
      btnReiniciar.addEventListener('click', reiniciarPlan);
      btnExportar.addEventListener('click', exportarJSON);
      btnImportar.addEventListener('click', importarJSON);
      
      btnWrapper.append(btnGuardar, btnReiniciar, btnExportar, btnImportar);
      actionButtons.appendChild(btnWrapper);
    }

    filterContainer.style.display = 'block';
    actionButtons.style.display = 'block';
    statsContainer.style.display = 'block';
  }

  function hideControls() {
    filterContainer.style.display = 'none';
    actionButtons.style.display = 'none';
    statsContainer.style.display = 'none';
  }

  function updateStats() {
    if (!allMaterias.length) return;

    const stats = {
      total: allMaterias.length,
      noCursada: allMaterias.filter(m => m.status === 0).length,
      enCurso: allMaterias.filter(m => m.status === 1).length,
      regular: allMaterias.filter(m => m.status === 2).length,
      aprobada: allMaterias.filter(m => m.status === 3).length
    };

    const porcentaje = ((stats.aprobada / stats.total) * 100).toFixed(0);

    statsContainer.innerHTML = `
      <div class="stats-grid">
        <div class="stat-item">
          <span class="stat-label">Aprobadas:</span>
          <span class="stat-value status-3">${stats.aprobada}</span>
        </div>
        <div class="stat-item">
          <span class="stat-label">Regulares:</span>
          <span class="stat-value status-2">${stats.regular}</span>
        </div>
        <div class="stat-item">
          <span class="stat-label">En curso:</span>
          <span class="stat-value status-1">${stats.enCurso}</span>
        </div>
        <div class="stat-item">
          <span class="stat-label">No cursadas:</span>
          <span class="stat-value status-0">${stats.noCursada}</span>
        </div>
        <div class="stat-item total">
          <span class="stat-label">Total:</span>
          <span class="stat-value">${stats.total}</span>
        </div>
        <div class="stat-item progress">
          <span class="stat-label">Progreso:</span>
          <span class="stat-value">${porcentaje}%</span>
        </div>
      </div>
    `;
  }

  function applyFilters() {
    const soloHabilitadas = document.getElementById('soloHabilitadas')?.checked;
    const rows = corrList.querySelectorAll('.materia-card');
    rows.forEach(row => {
      if (!soloHabilitadas) {
        row.style.display = 'flex';
        return;
      }
      const nombre = row.querySelector('.materia-title')?.textContent.trim();
      const visible = canCursar(nombre) || getStatusOf(nombre) > 0;
      row.style.display = visible ? 'flex' : 'none';
    });
  }

  function reiniciarPlan() {
    if (!currentPlan || !confirm('¿Seguro que quieres reiniciar todas las materias? Esta acción no se puede deshacer.')) return;
    
    const key = storageKey(currentPlan.owner, currentPlan.repo, currentPlan.name);
    localStorage.removeItem(key);
    loadPlanContent(currentPlan.owner, currentPlan.repo, {name: currentPlan.name, url: null});
    location.reload();
  }

  function exportarJSON() {
    if (!currentPlan) return;
    
    const key = storageKey(currentPlan.owner, currentPlan.repo, currentPlan.name);
    const data = localStorage.getItem(key) || '{}';
    
    const blob = new Blob([data], {type: 'application/json'});
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = `${currentPlan.name.replace('.md', '')}_${new Date().toISOString().split('T')[0]}.json`;
    a.click();
    URL.revokeObjectURL(url);
  }

  function importarJSON() {
    if (!currentPlan) return;
    
    const input = document.createElement('input');
    input.type = 'file';
    input.accept = 'application/json';
    
    input.addEventListener('change', (e) => {
      const file = e.target.files[0];
      if (!file) return;
      
      const reader = new FileReader();
      reader.onload = (event) => {
        try {
          const data = JSON.parse(event.target.result);
          const key = storageKey(currentPlan.owner, currentPlan.repo, currentPlan.name);
          localStorage.setItem(key, JSON.stringify(data));
          alert('Datos importados correctamente. Recargando...');
          location.reload();
        } catch (err) {
          alert('Error al importar: archivo JSON inválido');
        }
      };
      reader.readAsText(file);
    });
    
    input.click();
  }
});