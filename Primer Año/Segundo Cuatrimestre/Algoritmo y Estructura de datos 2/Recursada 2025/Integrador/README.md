<div align="center">
  <img src="https://www.unne.edu.ar/wp-content/uploads/Logo-UNNE-Angosto.png" width="150" />
  
  # Trabajo integrados | Sistema de gestion para Biblioteca
  
  ### Asignatura: Algoritos y Estructuras de datos II
  
  <br>
</div>

---

### Información del Equipo

| Rol | Nombre y Apellido | DNI/LU | DNI/LU |
| :--- | :--- | :--- | :--- |
| **Integrante 1** | Romani, Valentinoo| 46.881.963 | - |
| **Integrante 2** | Stoppello, M. Agustin | 46.316.920 | 60.122 |

### Docentes Responsables
| Rol | Nombre y Apellido |
| :--- | :--- |
| **Profesora** | Armana,Silvana 
| **Profesor** | Princich, Fernando

---

## 📑 Índice de Contenidos

1. [Información del Equipo](#información-del-equipo)
2. [Docentes Responsables](#docentes-responsables)
3. [1. Introducción](#1-introducción)
    - [Características del Sistema](#-características)
4. [2. Desarrollo y Decisiones de Diseño](#2-desarrollo-y-decisiones-de-diseño)

---
---


### 1. Introducción
El sistema permite administrar un catálogo de libros, registrar usuarios y gestionar el préstamo y la devolución de libros, utilizando múltiples estructuras de datos combinadas.

## 📚 Características

* **Gestión de Libros:** Agregar nuevos libros al catálogo.
* **Gestión de Usuarios:** Registrar nuevos usuarios en el sistema.
* **Préstamos:** Permitir a un usuario tomar prestado un libro. Si el libro no está disponible, el usuario se añade a una **lista de espera**.
* **Devoluciones:** Registrar la devolución de un libro. Si hay usuarios en lista de espera, el libro se asigna automáticamente al siguiente en la cola.
* **Consultas:** Mostrar el catálogo completo de libros y la lista de usuarios con sus préstamos actuales.
* **Persistencia:** Guardar y cargar automáticamente el estado de la biblioteca (libros y usuarios) en archivos binarios.

### 2. Desarrollo y Decisiones de Diseño


