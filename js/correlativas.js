// Correlativas: muestra materias desde el repo y permite marcar estado, guardando en localStorage
// Estados: 0 = No Aprobado (gris), 1 = Regular (amarillo), 2 = Promocionado (verde)

const DEFAULT_REPO_CORR = 'RepositoriosClonestp/Lic.Sistemas_de_Informacion';

document.addEventListener('DOMContentLoaded', () => {
  const repoInput = document.getElementById('repoInputCorr');
  const loadBtn = document.getElementById('loadCorrBtn');
  const corrList = document.getElementById('corrList');

  repoInput.value = DEFAULT_REPO_CORR;

  loadBtn.addEventListener('click', () => {
    const val = repoInput.value.trim();
    if (!val || !val.includes('/')) return alert('Indica owner/repo válido.');
    const [owner, repo] = val.split('/');
    loadCorrelativas(owner, repo);
  });

  // helper: key for storage
  function storageKey(owner, repo) {
    return `correlativas:${owner}/${repo}`;
  }

  async function loadCorrelativas(owner, repo) {
    corrList.innerHTML = '<p class="muted">Cargando materias…</p>';
    try {
      // 1) listar AÑOS: root dirs
      const years = await listContents(owner, repo, '');
      if (!Array.isArray(years)) { corrList.innerHTML = '<p class="muted">Repositorio vacío o no estructurado.</p>'; return; }
      const dirs = years.filter(x => x.type === 'dir');
      corrList.innerHTML = '';
      const savedRaw = localStorage.getItem(storageKey(owner, repo));
      const saved = savedRaw ? JSON.parse(savedRaw) : {};

      for (const year of dirs) {
        const yearBlock = document.createElement('div');
        yearBlock.className = 'year-block';
        const yearTitle = document.createElement('h3');
        yearTitle.textContent = year.name;
        yearBlock.appendChild(yearTitle);

        // load cuatrimestres (subdirs)
        const cuatArr = await listContents(owner, repo, year.path);
        const cuatDirs = cuatArr.filter(x => x.type === 'dir');
        for (const cuat of cuatDirs) {
          const cuatDiv = document.createElement('div');
          cuatDiv.className = 'cuatrimestre';
          const cuatTitle = document.createElement('h4');
          cuatTitle.textContent = cuat.name;
          cuatDiv.appendChild(cuatTitle);

          // materias (subdirs)
          const mtArr = await listContents(owner, repo, cuat.path);
          const matDirs = mtArr.filter(x => x.type === 'dir');
          for (const mat of matDirs) {
            const row = document.createElement('div');
            row.className = 'materia-row';
            const name = document.createElement('div');
            name.textContent = mat.name;
            const controls = document.createElement('div');

            const select = document.createElement('select');
            const opt0 = new Option('No Aprobado','0');
            const opt1 = new Option('Regular','1');
            const opt2 = new Option('Promocionado','2');
            select.add(opt0); select.add(opt1); select.add(opt2);

            // key per materia path
            const matKey = mat.path;
            const value = saved[matKey] !== undefined ? saved[matKey] : 0;
            select.value = String(value);

            const badge = document.createElement('span');
            badge.className = `status-badge status-${value}`;
            badge.textContent = select.options[select.selectedIndex].text;

            select.addEventListener('change', () => {
              const v = Number(select.value);
              saved[matKey] = v;
              try { localStorage.setItem(storageKey(owner, repo), JSON.stringify(saved)); } catch(e){}
              badge.className = `status-badge status-${v}`;
              badge.textContent = select.options[select.selectedIndex].text;
            });

            controls.appendChild(select);
            controls.appendChild(badge);
            row.appendChild(name);
            row.appendChild(controls);
            cuatDiv.appendChild(row);
          }

          yearBlock.appendChild(cuatDiv);
        }

        corrList.appendChild(yearBlock);
      }

      if (dirs.length === 0) corrList.innerHTML = '<p class="muted">No se encontraron carpetas (Años) en el repositorio.</p>';

    } catch (err) {
      corrList.innerHTML = `<p class="muted">Error: ${err.message}</p>`;
    }
  }
});