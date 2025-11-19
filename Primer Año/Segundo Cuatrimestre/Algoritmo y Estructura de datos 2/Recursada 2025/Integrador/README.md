# Sistema de Gestión de Biblioteca en C v2.0

Sistema completo de gestión bibliotecaria implementado en C utilizando estructuras de datos avanzadas (Árbol AVL, Colas, Listas Enlazadas) para optimizar búsquedas y mantener el equilibrio del catálogo.

## 📚 Características Principales

### **Gestión Avanzada de Libros**
* ✅ Agregar nuevos libros al catálogo con ISBN único
* ✅ Buscar libros por ISBN (búsqueda optimizada con AVL)
* ✅ Actualizar información (título, autor) de libros existentes
* ✅ Eliminar libros (con validaciones de estado)
* ✅ Visualizar catálogo completo ordenado por ISBN

### **Gestión de Usuarios**
* ✅ Registrar nuevos usuarios con ID único
* ✅ Eliminar usuarios (solo si no tienen préstamos activos)
* ✅ Ver lista completa de usuarios con sus préstamos actuales
* ✅ Límite configurable de préstamos por usuario (5 por defecto)

### **Sistema de Préstamos Inteligente**
* ✅ Prestar libros con validación automática de disponibilidad
* ✅ **Lista de espera automática:** Si el libro está prestado, el usuario se encola
* ✅ **Asignación automática:** Al devolver un libro, se asigna al siguiente en la cola
* ✅ Validación de límite de préstamos por usuario
* ✅ Control de usuarios duplicados en lista de espera

### **Persistencia Completa**
* ✅ Guardar catálogo de libros en `libros.dat`
* ✅ Guardar usuarios y sus préstamos en `usuarios.dat`
* ✅ **NUEVA:** Guardar listas de espera en `colas_espera.dat`
* ✅ Carga automática al iniciar el sistema
* ✅ Preservación del estado completo del sistema

### **Estadísticas y Reportes**
* ✅ Total de libros en catálogo
* ✅ Total de usuarios registrados
* ✅ Libros disponibles vs prestados
* ✅ Contador de usuarios en espera por libro

---

## 🏗️ Arquitectura del Sistema

### **Estructuras de Datos Implementadas**

#### 1. **Árbol AVL (Catálogo de Libros)**
```c
typedef struct NodoArbol {
    Libro libro;
    struct NodoArbol *izq, *der;
    int altura;  // Para balanceo automático
} NodoArbol;
```
**Ventajas:**
- 🚀 Búsqueda O(log n) garantizada
- ⚖️ Auto-balanceo tras inserciones/eliminaciones
- 📊 Catálogo siempre ordenado por ISBN

#### 2. **Cola FIFO (Listas de Espera)**
```c
typedef struct {
    NodoCola *frente, *final;
} Cola;
```
**Uso:** Gestionar usuarios esperando por libros prestados

#### 3. **Listas Enlazadas**
- **Libros por usuario:** Registro de préstamos activos
- **Lista de usuarios:** Gestión completa de usuarios del sistema

---

## 🔧 Mejoras Implementadas (v2.0)

### ✨ **Optimizaciones de Rendimiento**
| Versión Anterior | Versión 2.0 | Mejora |
|-----------------|-------------|--------|
| BST (desbalanceado) | **Árbol AVL** | Búsquedas O(log n) garantizadas |
| Sin límite de préstamos | **Límite configurable** | Control de inventario |
| Colas perdidas al reiniciar | **Persistencia de colas** | Estado completo preservado |

### 🛡️ **Seguridad y Validaciones**
```c
✓ Validación de ISBN duplicados
✓ Control de límite de préstamos (MAX_PRESTAMOS_POR_USUARIO)
✓ Verificación de estado antes de eliminar libros
✓ Validación de existencia de usuarios en colas
✓ Manejo robusto de errores con códigos de retorno
```

### 🆕 **Nuevas Funcionalidades**

#### **Eliminación Segura de Libros**
- Solo permite eliminar libros disponibles
- Verifica que no haya usuarios en lista de espera
- Requiere confirmación del usuario

#### **Actualización de Información**
```c
int actualizarLibro(NodoArbol* raiz, long long isbn, 
                    const char* nuevoTitulo, const char* nuevoAutor);
```

#### **Estadísticas del Sistema**
```
========================================
      ESTADISTICAS DEL SISTEMA
========================================
Total de libros en catalogo: 15
Total de usuarios registrados: 8
Libros disponibles: 10
Libros prestados: 5
Limite de prestamos por usuario: 5
========================================
```

---

## 📂 Archivos del Proyecto

```
sistema_de_gestion_de_Biblioteca/
│
├── Sistema_de_gestion_de_Biblioteca.c  # Implementación completa v2.0 ⭐
├── biblioteca.h                         # Cabecera con definiciones
├── TrabajoIntegrador.c                  # Versión original (BST)
├── sistema.c                            # Implementación parcial AVL
├── README.md                            # Esta documentación
│
└── Archivos de datos (generados automáticamente):
    ├── libros.dat          # Catálogo de libros
    ├── usuarios.dat        # Usuarios y préstamos
    └── colas_espera.dat    # Listas de espera (NUEVO)
```

---

## 🚀 Compilación y Uso

### **Compilar el Programa**
```powershell
# Con GCC
gcc Sistema_de_gestion_de_Biblioteca.c -o biblioteca.exe

# Con MinGW
mingw32-gcc Sistema_de_gestion_de_Biblioteca.c -o biblioteca.exe

# Con optimización
gcc -O2 Sistema_de_gestion_de_Biblioteca.c -o biblioteca.exe
```

### **Ejecutar**
```powershell
.\biblioteca.exe
```

### **Configuración Personalizada**
Editar las constantes en el archivo fuente:
```c
#define MAX_PRESTAMOS_POR_USUARIO 5    // Límite de préstamos
#define MAX_TITULO 100                  // Longitud máxima título
#define MAX_AUTOR 100                   // Longitud máxima autor
#define MAX_NOMBRE_USUARIO 100          // Longitud máxima nombre
```

---

## 📖 Guía de Uso - Menú Principal

```
--- MENU PRINCIPAL ---
1.  Agregar nuevo libro al catalogo
2.  Buscar libro por ISBN
3.  Actualizar informacion de libro
4.  Eliminar libro del catalogo
5.  Mostrar catalogo completo
6.  Agregar nuevo usuario
7.  Eliminar usuario
8.  Mostrar lista de usuarios
9.  Prestar libro
10. Devolver libro
11. Mostrar estadisticas
12. Guardar y Salir
```

### **Flujo de Trabajo Típico**

#### 📚 **1. Agregar Libros al Catálogo**
```
Seleccione opcion: 1
Ingrese ISBN: 9788478886456
Ingrese Titulo: Don Quijote de la Mancha
Ingrese Autor: Miguel de Cervantes
> Exito: Libro agregado al catalogo.
```

#### 👤 **2. Registrar Usuarios**
```
Seleccione opcion: 6
Ingrese ID del nuevo usuario: 101
Ingrese Nombre: Juan Perez
> Exito: Usuario agregado al sistema.
```

#### 📤 **3. Prestar un Libro**
```
Seleccione opcion: 9
Ingrese ID del usuario: 101
Ingrese ISBN del libro: 9788478886456
> Exito: Libro 'Don Quijote de la Mancha' prestado al usuario 'Juan Perez'.
```

#### 📥 **4. Devolver un Libro**
```
Seleccione opcion: 10
Ingrese ID del usuario: 101
Ingrese ISBN del libro: 9788478886456
> Exito: Libro 'Don Quijote de la Mancha' devuelto por Juan Perez. 
  El libro esta ahora disponible.
```

---

## 🧮 Complejidad Algorítmica

| Operación | Complejidad | Estructura |
|-----------|-------------|------------|
| Buscar libro | **O(log n)** | Árbol AVL |
| Insertar libro | **O(log n)** | Árbol AVL |
| Eliminar libro | **O(log n)** | Árbol AVL |
| Buscar usuario | **O(n)** | Lista enlazada |
| Encolar/Desencolar | **O(1)** | Cola |
| Contar préstamos | **O(m)** | Lista (m = préstamos) |

---

## 🧪 Casos de Uso Avanzados

### **Escenario 1: Lista de Espera Automática**
```
Usuario A presta "El Principito" → Disponible = NO
Usuario B solicita "El Principito" → Se añade a cola
Usuario C solicita "El Principito" → Se añade a cola
Usuario A devuelve → Se asigna automáticamente a Usuario B
Usuario B devuelve → Se asigna automáticamente a Usuario C
```

### **Escenario 2: Límite de Préstamos**
```
Usuario D tiene 5 libros prestados (límite alcanzado)
Usuario D solicita 1 libro más → RECHAZADO
Usuario D devuelve 1 libro → Ahora puede solicitar otro
```

### **Escenario 3: Eliminación Segura**
```
Intento eliminar libro prestado → BLOQUEADO
Intento eliminar libro con cola → BLOQUEADO
Intento eliminar libro disponible sin cola → PERMITIDO (con confirmación)
```

---

## 🔍 Funciones Clave del Sistema

### **Gestión del Árbol AVL**

#### **Inserción con Auto-balanceo**
```c
NodoArbol* insertarLibroAVL(NodoArbol* nodo, Libro libro, int* codigo);
```
- Inserta libro manteniendo propiedad AVL
- Realiza rotaciones simples/dobles según sea necesario
- Retorna código de error (0=éxito, 1=duplicado)

#### **Eliminación Balanceada**
```c
NodoArbol* eliminarLibroAVL(NodoArbol* raiz, long long isbn, int* codigo);
```
- Elimina nodo y re-balancea el árbol
- Maneja 3 casos: sin hijos, 1 hijo, 2 hijos
- Libera memoria de la cola asociada

### **Lógica de Préstamos**

#### **Préstamo Inteligente**
```c
int prestarLibro(NodoArbol* raizArbol, NodoUsuario* listaUsuarios, 
                 long long isbn, int idUsuario);
```
**Validaciones:**
1. ✓ Libro existe
2. ✓ Usuario existe
3. ✓ Usuario no superó límite de préstamos
4. ✓ Usuario no está ya en la cola

**Comportamiento:**
- Si disponible → Asignar inmediatamente
- Si prestado → Agregar a lista de espera

#### **Devolución con Reasignación**
```c
int devolverLibro(NodoArbol* raizArbol, NodoUsuario* listaUsuarios,
                  long long isbn, int idUsuario);
```
**Lógica:**
1. Verifica que el usuario tenga el libro
2. Elimina el libro de la lista del usuario
3. Si hay cola:
   - Desencola siguiente usuario
   - Verifica límite del siguiente
   - Asigna automáticamente o marca disponible
4. Si no hay cola: Marca como disponible

---

## 💾 Formato de Persistencia

### **libros.dat** (Binario)
```
[Libro1][Libro2][Libro3]...
```
Cada `Libro` contiene: ISBN, Título, Autor, Disponible

### **usuarios.dat** (Binario)
```
[Usuario1][NumLibros1][ISBN1][ISBN2]...[Usuario2][NumLibros2]...
```

### **colas_espera.dat** (Binario) - NUEVO
```
[TotalLibros]
[ISBN1][NumEnEspera1][ID1][ID2]...
[ISBN2][NumEnEspera2][ID3][ID4]...
```

---

## 🐛 Manejo de Errores

| Código | Significado | Acción |
|--------|-------------|--------|
| 0 | Operación exitosa | Continuar |
| 1 | Elemento no encontrado | Mostrar error |
| 2 | Elemento duplicado | Rechazar operación |
| 3 | Límite alcanzado | Informar al usuario |
| 4 | Ya en lista de espera | Evitar duplicado |

---

## 🔮 Mejoras Futuras Sugeridas

### **Funcionalidades**
- [ ] Búsqueda por título/autor (índices secundarios)
- [ ] Sistema de multas por retraso
- [ ] Historial de préstamos por usuario
- [ ] Reservas anticipadas
- [ ] Categorías/géneros de libros
- [ ] Calificaciones y reseñas

### **Optimizaciones**
- [ ] Tabla hash para usuarios (búsqueda O(1))
- [ ] Índice B-Tree para grandes volúmenes
- [ ] Compresión de archivos de datos
- [ ] Exportación a JSON/XML
- [ ] Interfaz gráfica (GUI)

### **Arquitectura**
- [ ] Separar en módulos (.h/.c)
- [ ] Sistema de logs
- [ ] Configuración externa (config.ini)
- [ ] Tests unitarios
- [ ] Documentación Doxygen

---

## 📊 Ejemplo de Sesión Completa

```powershell
PS> .\biblioteca.exe

===========================================
  SISTEMA DE GESTION DE BIBLIOTECA v2.0
===========================================

Info: No se encontro libros.dat. Se iniciara con un catalogo vacio.
Info: No se encontro usuarios.dat. Se iniciara sin usuarios.
Info: No se encontro colas_espera.dat. Las listas de espera estaran vacias.

--- MENU PRINCIPAL ---
Seleccione una opcion: 1
Ingrese ISBN: 9780345391803
Ingrese Titulo: 1984
Ingrese Autor: George Orwell
Exito: Libro agregado al catalogo.

Seleccione una opcion: 6
Ingrese ID del nuevo usuario: 1
Ingrese Nombre: Ana Garcia
Exito: Usuario agregado al sistema.

Seleccione una opcion: 9
Ingrese ID del usuario: 1
Ingrese ISBN del libro: 9780345391803
Exito: Libro '1984' prestado al usuario 'Ana Garcia'.

Seleccione una opcion: 11

========================================
      ESTADISTICAS DEL SISTEMA
========================================
Total de libros en catalogo: 1
Total de usuarios registrados: 1
Libros disponibles: 0
Libros prestados: 1
Limite de prestamos por usuario: 5
========================================

Seleccione una opcion: 12
Guardando datos...
Catalogo de libros guardado en libros.dat.
Lista de usuarios guardada en usuarios.dat.
Listas de espera guardadas en colas_espera.dat.

¡Gracias por usar el Sistema de Gestion de Biblioteca!
Saliendo...
```

---

## 👨‍💻 Autor y Contribuciones

**Versión Original (TrabajoIntegrador.c):** Implementación BST básica  
**Versión 2.0 (Sistema_de_gestion_de_Biblioteca.c):** Mejoras con AVL, límites, persistencia completa

### **Cómo Contribuir**
1. Fork el repositorio
2. Crea una rama para tu feature (`git checkout -b feature/mejora`)
3. Commit tus cambios (`git commit -am 'Agregar nueva funcionalidad'`)
4. Push a la rama (`git push origin feature/mejora`)
5. Abre un Pull Request

---

## 📜 Licencia

Este proyecto es de código abierto y está disponible bajo la licencia MIT.

---

## 📞 Soporte

Para reportar bugs o sugerir mejoras, por favor abre un **Issue** en el repositorio.

**¡Gracias por usar el Sistema de Gestión de Biblioteca! 📚✨**

