// common utilities used by paginas
// No dependencies. Vanilla JS.

// Get default branch of repo, then list contents of path
async function getRepoDefaultBranch(owner, repo) {
  const cacheKey = `gh_default_branch:${owner}/${repo}`;
  try {
    const cached = localStorage.getItem(cacheKey);
    if (cached) return cached;
  } catch (e) {}
  const res = await fetch(`https://api.github.com/repos/${owner}/${repo}`);
  if (!res.ok) throw new Error('No se pudo obtener información del repositorio. Comprueba owner/repo.');
  const data = await res.json();
  const branch = data.default_branch || 'main';
  try { localStorage.setItem(cacheKey, branch); } catch(e){}
  return branch;
}

async function listContents(owner, repo, path = '') {
  const branch = await getRepoDefaultBranch(owner, repo);
  const encoded = encodeURIComponent(path);
  // GitHub API contents endpoint
  const url = `https://api.github.com/repos/${owner}/${repo}/contents/${path}?ref=${branch}`;
  const res = await fetch(url);
  if (res.status === 404) throw new Error('Ruta no encontrada (404). Revisa owner/repo y estructura.');
  if (!res.ok) {
    const text = await res.text();
    throw new Error(`Error al obtener contenidos: ${res.status} ${text}`);
  }
  return res.json(); // array or file object
}

async function getRepoBranches(owner, repo) {
  const res = await fetch(`https://api.github.com/repos/${owner}/${repo}/branches`);
  if (!res.ok) throw new Error('No se pudo obtener la lista de ramas.');
  return res.json(); // array of branches
}

// Convenience: get human-friendly extension
function extOf(name) {
  const i = name.lastIndexOf('.');
  return i === -1 ? '' : name.slice(i+1).toLowerCase();
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
  
  // Archivos especiales de git (sin extensión o con punto al inicio)
  if (filename.startsWith('.git') || filename === 'LICENSE' || filename === 'README') {
    return true;
  }
  
  // Si no tiene punto, es archivo sin extensión (tratar como texto)
  if (!filename.includes('.')) {
    return true;
  }
  
  const ext = filename.split('.').pop().toLowerCase();
  return textExts.includes(ext);
}

function createEl(tag, props = {}, ...children) {
  const el = document.createElement(tag);
  for (const k in props) {
    if (k === 'class') el.className = props[k];
    else if (k === 'html') el.innerHTML = props[k];
    else el.setAttribute(k, props[k]);
  }
  for (const c of children) if (c !== undefined && c !== null) el.append(c);
  return el;
}