// Correlativas: muestra materias desde Planes Vigentes y permite marcar estado
// Estados: 0 = No Aprobado (gris), 1 = Regular (amarillo), 2 = Promocionado (verde)

const DEFAULT_REPO_CORR = 'RepositoriosClonestp/Lic.Sistemas_de_Informacion';
const PLANES_PATH = 'Planes%20Vigentes'; // URL encoded para espacios

document.addEventListener('DOMContentLoaded', () => {
  const corrList = document.getElementById('corrList');
  const planSelect = document.getElementById('planSelect');
  const planSelectContainer = document.getElementById('planSelectContainer');

  // Cargar planes disponibles automáticamente
  loadPlanes();

  async function loadPlanes() {
    planSelectContainer.innerHTML = '<p class="muted">Cargando planes disponibles…</p>';
    try {
      const [owner, repo] = DEFAULT_REPO_CORR.split('/');
      
      // Primero verificar la estructura del repositorio
      console.log('Buscando en:', owner, repo);
      
      // Intentar con diferentes variaciones de la ruta
      let items;
      try {
        items = await listContents(owner, repo, 'Planes Vigentes');
      } catch (e) {
        console.error('Error con "Planes Vigentes":', e);
        try {
          items = await listContents(owner, repo, 'Planes_Vigentes');
        } catch (e2) {
          console.error('Error con "Planes_Vigentes":', e2);
          // Listar el root para ver qué carpetas existen
          const rootItems = await listContents(owner, repo, '');
          console.log('Carpetas en root:', rootItems.filter(x => x.type === 'dir').map(x => x.name));
          throw new Error('No se encontró la carpeta de planes. Carpetas disponibles: ' + rootItems.filter(x => x.type === 'dir').map(x => x.name).join(', '));
        }
      }
      
      // Filtrar solo archivos .md
      const planes = Array.isArray(items) 
        ? items.filter(x => x.type === 'file' && x.name.toLowerCase().endsWith('.md')) 
        : [];
      
      if (planes.length === 0) {
        planSelectContainer.innerHTML = '<p class="muted">No se encontraron archivos de planes en la carpeta.</p>';
        return;
      }

      planSelectContainer.innerHTML = '<label>Selecciona tu plan de estudios:</label>';
      const select = document.createElement('select');
      select.id = 'planSelect';
      const defaultOpt = new Option('-- Selecciona un plan --', '');
      select.add(defaultOpt);
      
      planes.forEach(plan => {
        const opt = new Option(plan.name, plan.path);
        select.add(opt);
      });

      select.addEventListener('change', () => {
        if (select.value) {
          const selectedPlan = planes.find(p => p.path === select.value);
          loadPlanContent(owner, repo, selectedPlan);
        } else {
          corrList.innerHTML = '<p class="muted">Selecciona un plan para ver las materias.</p>';
        }
      });

      planSelectContainer.appendChild(select);
      corrList.innerHTML = '<p class="muted">Selecciona un plan para ver las materias.</p>';

    } catch (err) {
      planSelectContainer.innerHTML = `<p class="muted">Error al cargar planes: ${err.message}</p>`;
      console.error('Error detallado:', err);
    }
  }

  // helper: key for storage
  function storageKey(owner, repo, planName) {
    return `correlativas:${owner}/${repo}:${planName}`;
  }

  async function loadPlanContent(owner, repo, plan) {
    corrList.innerHTML = '<p class="muted">Cargando contenido del plan…</p>';
    try {
      // Obtener el contenido del archivo de plan
      const res = await fetch(plan.url);
      if (!res.ok) throw new Error(`HTTP ${res.status}`);
      const data = await res.json();
      
      // El contenido viene en base64, decodificarlo
      const content = data.encoding === 'base64' 
        ? atob(data.content.replace(/\n/g, ''))
        : data.content;

      // Parsear el contenido (asumiendo que es texto estructurado)
      parseAndDisplayPlan(owner, repo, plan.name, content);

    } catch (err) {
      corrList.innerHTML = `<p class="muted">Error al cargar el plan: ${err.message}</p>`;
    }
  }

  function parseAndDisplayPlan(owner, repo, planName, content) {
    corrList.innerHTML = '';
    const savedRaw = localStorage.getItem(storageKey(owner, repo, planName));
    const saved = savedRaw ? JSON.parse(savedRaw) : {};

    // Dividir por líneas y procesar
    const lines = content.split('\n');
    
    let currentYear = null;
    let currentCuat = null;
    let yearBlock = null;
    let cuatDiv = null;

    lines.forEach(line => {
      const trimmed = line.trim();
      
      // Ignorar líneas vacías y comentarios HTML
      if (!trimmed || trimmed.startsWith('<!--') || trimmed.startsWith('-->')) return;
      
      // Detectar títulos de año (## o ###)
      if (trimmed.match(/^##+ /) && 
          (trimmed.toLowerCase().includes('año') || 
           trimmed.toLowerCase().match(/\d+(er|do|to|º)/))) {
        if (yearBlock) corrList.appendChild(yearBlock);
        yearBlock = document.createElement('div');
        yearBlock.className = 'year-block';
        const yearTitle = document.createElement('h3');
        yearTitle.textContent = trimmed.replace(/^#+\s*/, '');
        yearBlock.appendChild(yearTitle);
        currentYear = trimmed.replace(/^#+\s*/, '');
        currentCuat = null;
      }
      // Detectar cuatrimestres (### o ####)
      else if (trimmed.match(/^###+ /) && trimmed.toLowerCase().includes('cuatrimestre')) {
        if (cuatDiv && yearBlock) yearBlock.appendChild(cuatDiv);
        cuatDiv = document.createElement('div');
        cuatDiv.className = 'cuatrimestre';
        const cuatTitle = document.createElement('h4');
        cuatTitle.textContent = trimmed.replace(/^#+\s*/, '');
        cuatDiv.appendChild(cuatTitle);
        currentCuat = trimmed.replace(/^#+\s*/, '');
      }
      // Detectar materias (líneas con - o * de markdown)
      else if (trimmed.match(/^[-*]\s+/) && currentYear && currentCuat) {
        if (!cuatDiv) {
          cuatDiv = document.createElement('div');
          cuatDiv.className = 'cuatrimestre';
        }
        
        // Limpiar el nombre de la materia
        const materiaName = trimmed.replace(/^[-*]\s+/, '').trim();
        if (!materiaName) return;
        
        const row = document.createElement('div');
        row.className = 'materia-row';
        const name = document.createElement('div');
        name.textContent = materiaName;
        const controls = document.createElement('div');

        const select = document.createElement('select');
        const opt0 = new Option('No Aprobado','0');
        const opt1 = new Option('Regular','1');
        const opt2 = new Option('Promocionado','2');
        select.add(opt0); select.add(opt1); select.add(opt2);

        // key per materia
        const matKey = `${currentYear}::${currentCuat}::${materiaName}`;
        const value = saved[matKey] !== undefined ? saved[matKey] : 0;
        select.value = String(value);

        const badge = document.createElement('span');
        badge.className = `status-badge status-${value}`;
        badge.textContent = select.options[select.selectedIndex].text;

        select.addEventListener('change', () => {
          const v = Number(select.value);
          saved[matKey] = v;
          try { localStorage.setItem(storageKey(owner, repo, planName), JSON.stringify(saved)); } catch(e){}
          badge.className = `status-badge status-${v}`;
          badge.textContent = select.options[select.selectedIndex].text;
        });

        controls.appendChild(select);
        controls.appendChild(badge);
        row.appendChild(name);
        row.appendChild(controls);
        cuatDiv.appendChild(row);
      }
    });

    // Agregar el último cuatrimestre y año
    if (cuatDiv && yearBlock) yearBlock.appendChild(cuatDiv);
    if (yearBlock) corrList.appendChild(yearBlock);

    if (!corrList.children.length) {
      corrList.innerHTML = '<p class="muted">No se pudieron procesar las materias del plan seleccionado. Revisa la consola para más detalles.</p>';
      console.log('Contenido del archivo:', content);
    }
  }
});