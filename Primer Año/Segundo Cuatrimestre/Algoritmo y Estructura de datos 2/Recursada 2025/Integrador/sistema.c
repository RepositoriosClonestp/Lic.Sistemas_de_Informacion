#include "biblioteca.h"

int main() {
    tNodoArbol* arbolLibros = NULL;
    tNodoUsuario* listaUsuarios = NULL;
    int opcion, idLibro, idUsuario;

    cargarTodo(&arbolLibros, &listaUsuarios);

    do {
        printf("\n=== SISTEMA DE BIBLIOTECA ===\n");
        printf("1. Agregar Usuario\n");
        printf("2. Agregar Libro\n");
        printf("3. Prestar Libro\n");
        printf("4. Devolver Libro\n");
        printf("5. Mostrar Catalogo\n");
        printf("6. Mostrar Usuarios\n");
        printf("7. Guardar y Salir\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: {
                tUsuario usuario;
                printf("ID Usuario: ");
                scanf("%d", &usuario.idUsuario);
                printf("Nombre: ");
                fflush(stdin);
                fgets(usuario.nombre, MAX, stdin);
                usuario.nombre[strcspn(usuario.nombre, "\n")] = 0;
                if(buscarUsuario(listaUsuarios,usuario.idUsuario) == NULL){
                    listaUsuarios = insertarUsuario(listaUsuarios, usuario);
                    printf("Usuario agregado con exito\n");
                }else{
                    printf("Error: ya existe un usuario con ese ID\n");
                }
                break;
            }
            case 2: {
                tLibro libro;
                printf("ID Libro: ");
                scanf("%d", &libro.idLibro);
                printf("Titulo: ");
                fflush(stdin);
                fgets(libro.titulo, MAX, stdin);
                libro.titulo[strcspn(libro.titulo, "\n")] = 0; 
                printf("Autor: ");
                fflush(stdin);
                fgets(libro.autor, MAX, stdin);
                libro.autor[strcspn(libro.autor, "\n")] = 0; 
                libro.disponible = 1;
                arbolLibros = insertarLibro(arbolLibros, libro);
                printf("Libro agregado\n");
                break;
            }
            case 3:
                printf("ID Libro a prestar: ");
                scanf("%d", &idLibro);
                printf("ID Usuario receptor: ");
                scanf("%d", &idUsuario);
                prestarLibro(arbolLibros, listaUsuarios, idLibro, idUsuario);
                break;
            case 4:
                printf("ID Libro a devolver: ");
                scanf("%d", &idLibro);
                printf("ID Usuario que devuelve: ");
                scanf("%d", &idUsuario);
                devolverLibro(arbolLibros, listaUsuarios, idLibro, idUsuario);
                break;
            case 5:
                printf("\n--- CATALOGO ---\n");
                mostrarCatalogo(arbolLibros);
                break;
            case 6:
                printf("\n--- USUARIOS ---\n");
                mostrarUsuarios(listaUsuarios);
                break;
            case 7:
                guardarTodo(arbolLibros, listaUsuarios);
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while(opcion != 7);

    return 0;
}
