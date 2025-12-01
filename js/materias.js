// Lógica de materias: navegación del repo y visualización de archivos
const DEFAULT_REPO = 'RepositoriosClonestp/Lic.Sistemas_de_Informacion';
const DEFAULT_PATH = 'Materias_por_Año';

document.addEventListener('DOMContentLoaded', () => {
  const repoInput = document.getElementById('repoInput');
  const loadBtn = document.getElementById('loadRepoBtn');
  const directoryList = document.getElementById('directoryList');
  const viewerBody = document.getElementById('viewerBody');
  const repoLabel = document.getElementById('repoLabel');
  const breadcrumb = document.getElementById('breadcrumb');

  let current = { owner:'', repo:'', path: '' };
  let stack = []; // breadcrumb stack

  repoInput.value = DEFAULT_REPO;
  loadBtn.addEventListener('click', async () => {
    const val = repoInput.value.trim();
    if (!val || !val.includes('/')) return alert('Indica owner/repo válido.');
    const [owner, repo] = val.split('/');
    current.owner = owner;
    current.repo = repo;
    current.path = DEFAULT_PATH;
    stack = [{name: 'Materias_por_Año', path: DEFAULT_PATH}];
    repoLabel.textContent = `${owner}/${repo}`;
    
    // Cargar ramas
    try {
      const branches = await getRepoBranches(owner, repo);
      console.log('Ramas disponibles:', branches);
    } catch (err) {
      alert(err.message);
    }
    
    loadDirectory(DEFAULT_PATH);
  });

  // initial load
  repoInput.dispatchEvent(new Event('input'));
  loadBtn.click();

  async function loadDirectory(path) {
    directoryList.innerHTML = '<p class="muted">Cargando...</p>';
    viewerBody.innerHTML = '<p class="muted">Selecciona un archivo o carpeta.</p>';
    try {
      const items = await listContents(current.owner, current.repo, path);
      // items might be a single file (object) if path points to file
      const arr = Array.isArray(items) ? items : [items];
      // sort: dirs first
      arr.sort((a,b) => (a.type === b.type) ? a.name.localeCompare(b.name) : (a.type==='dir' ? -1 : 1));
      directoryList.innerHTML = '';
      arr.forEach(item => {
        const el = createEl('div', {class:'dir-item'});
        const left = createEl('div', {}, createEl('div',{class:'name'}, item.name), createEl('div',{class:'dir-meta'}, item.type === 'dir' ? 'Carpeta' : (item.size ? `${(item.size/1024).toFixed(1)} KB` : 'Archivo')));
        const right = createEl('div', {}, createEl('button',{class:'btn small'}, item.type === 'dir' ? 'Abrir' : 'Ver'));
        el.append(left, right);
        directoryList.appendChild(el);

        el.addEventListener('click', (e) => {
          if (item.type === 'dir') {
            // update path and breadcrumb stack
            current.path = item.path;
            stack.push({name:item.name, path:item.path});
            renderBreadcrumb();
            loadDirectory(item.path);
          } else {
            // file selected
            showFile(item);
          }
        });
      });
    } catch (err) {
      directoryList.innerHTML = `<p class="muted">Error: ${err.message}</p>`;
    }
  }

  function renderBreadcrumb() {
    const parts = [{name: `${current.owner}/${current.repo}`, path: ''}, ...stack];
    breadcrumb.innerHTML = 'Repositorio: ';
    parts.forEach((p, idx) => {
      const a = createEl('a', {href:'#'}, p.name);
      a.addEventListener('click', (e) => {
        e.preventDefault();
        if (idx === 0) {
          stack = [{name: 'Materias_por_Año', path: DEFAULT_PATH}];
          current.path = DEFAULT_PATH;
          loadDirectory(DEFAULT_PATH);
        } else {
          stack = stack.slice(0, idx);
          current.path = parts[idx].path;
          loadDirectory(parts[idx].path);
        }
      });
      breadcrumb.appendChild(a);
      if (idx < parts.length-1) breadcrumb.appendChild(document.createTextNode(' / '));
    });
  }

  async function showFile(file) {
    viewerBody.innerHTML = '<p class="muted">Cargando vista previa…</p>';
    const name = file.name;
    const download = file.download_url;
    const githubUrl = file.html_url;

    // build header with actions
    const header = createEl('div', {style:'margin-bottom:12px;'}, 
      createEl('strong', {}, name),
      createEl('div', {style:'margin-top:6px; display:flex; gap:8px;'}, 
        createEl('a', {href:download, target:'_blank', class:'btn'}, 'Descargar'),
        createEl('a', {href:githubUrl, target:'_blank', class:'btn'}, 'Abrir en GitHub')
      )
    );
    viewerBody.innerHTML = '';
    viewerBody.appendChild(header);

    if (isImage(name)) {
      const img = createEl('img', {class:'preview-img', src:download, alt:name});
      viewerBody.appendChild(img);
    } else if (isPDF(name)) {
      const iframe = createEl('iframe', {class:'preview-iframe', src:download});
      viewerBody.appendChild(iframe);
    } else if (isTextlike(name)) {
      // Usar la API de GitHub para obtener el contenido
      try {
        const res = await fetch(file.url); // Usar file.url en lugar de download_url
        if (!res.ok) throw new Error(`HTTP ${res.status}`);
        const data = await res.json();
        
        // El contenido viene en base64, decodificarlo
        const content = data.encoding === 'base64' 
          ? atob(data.content.replace(/\n/g, ''))
          : data.content;
        
        const pre = createEl('pre', {
          style:'white-space:pre-wrap; max-height:520px; overflow:auto; background:#f5f5f5; padding:12px; border-radius:4px; font-size:13px; line-height:1.5;'
        }, content);
        viewerBody.appendChild(pre);
      } catch (e) {
        viewerBody.appendChild(createEl('p', {class:'muted'}, `No se pudo cargar el archivo: ${e.message}`));
        console.error('Error loading file:', e);
      }
    } else {
      viewerBody.appendChild(createEl('p', {class:'muted'}, 'Vista previa no disponible para este tipo de archivo. Usa "Descargar" o "Abrir en GitHub".'));
    }
  }

  // Helper: detecta si es imagen soportada
  function isImage(filename) {
    const imgExts = ['png', 'jpg', 'jpeg', 'gif', 'svg', 'webp', 'bmp', 'ico'];
    const ext = filename.split('.').pop().toLowerCase();
    return imgExts.includes(ext);
  }

  // Helper: detecta si es PDF
  function isPDF(filename) {
    return filename.toLowerCase().endsWith('.pdf');
  }

  // Helper: detecta archivos de texto y código soportados
  function isTextlike(filename) {
    const textExts = [
      'txt', 'md', 'html', 'htm', 'xml', 'json', 'csv',
      'css', 'js', 'ts', 'jsx', 'tsx',
      'java', 'c', 'h', 'cpp', 'cxx', 'cc', 'hpp', 'hxx',
      'sql', 'rtf', 'py', 'rb', 'php', 'sh', 'bat', 'ps1',
      'yaml', 'yml', 'toml', 'ini', 'cfg', 'log'
    ];
    const ext = filename.split('.').pop().toLowerCase();
    // Archivos sin extensión o .gitattributes, etc.
    if (!filename.includes('.') || filename.startsWith('.git')) return true;
    return textExts.includes(ext);
  }
});