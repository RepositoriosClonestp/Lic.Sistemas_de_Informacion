// Lógica pequeña para contacto: muestra aviso al enviar (no hace backend)
document.addEventListener('DOMContentLoaded', () => {
  const form = document.getElementById('contactForm');
  if (!form) return;
  form.addEventListener('submit', (e) => {
    // Let FormSubmit handle the submission. But we can show a brief confirmation before actual submit by letting the form proceed.
    // Alternatively, you can use AJAX to post to FormSubmit's endpoint. For simplicity we let default submit.
    alert('Se enviará el mensaje usando FormSubmit. Asegúrate de poner tu correo en action del formulario.');
  });
});