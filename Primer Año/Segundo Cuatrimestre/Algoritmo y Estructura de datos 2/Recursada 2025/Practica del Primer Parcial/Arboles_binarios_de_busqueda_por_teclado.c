#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char tString[50];

typedef struct {
    char codigo[16];    // código como cadena (permite 0398)
    tString nombre;
    tString marca;
    float precio;
    int stock;
} tPerfume;

typedef struct nodoArbol {
    tPerfume perfume;
    struct nodoArbol *izq;
    struct nodoArbol *der;
} tArbol;

tArbol* crearNodo(tPerfume p) {
    tArbol* n = (tArbol*) malloc(sizeof(tArbol));
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->perfume = p;
    n->izq = n->der = NULL;
    return n;
}

// Compara numéricamente los códigos (acepta ceros a la izquierda)
int compararCodigo(const char *a, const char *b) {
    long va = strtol(a, NULL, 10);
    long vb = strtol(b, NULL, 10);
    if (va < vb) return -1;
    if (va > vb) return 1;
    return 0;
}

tArbol* insertar(tArbol* raiz, tPerfume p) {
    if (raiz == NULL) return crearNodo(p);
    int cmp = compararCodigo(p.codigo, raiz->perfume.codigo);
    if (cmp < 0) raiz->izq = insertar(raiz->izq, p);
    else if (cmp > 0) raiz->der = insertar(raiz->der, p);
    else {
        // clave duplicada: aquí solo actualizamos datos (si se quisiera)
        raiz->perfume = p;
    }
    return raiz;
}

void imprimirNodo(const tPerfume *p) {
    printf("%s\t%-12s\t%-12s\t%.0f\t%d\n",
           p->codigo, p->nombre, p->marca, p->precio, p->stock);
}

void inOrder(tArbol* r) {
    if (!r) return;
    inOrder(r->izq);
    imprimirNodo(&r->perfume);
    inOrder(r->der);
}

void preOrder(tArbol* r) {
    if (!r) return;
    imprimirNodo(&r->perfume);
    preOrder(r->izq);
    preOrder(r->der);
}

void postOrder(tArbol* r) {
    if (!r) return;
    postOrder(r->izq);
    postOrder(r->der);
    imprimirNodo(&r->perfume);
}

void liberarArbol(tArbol* r) {
    if (!r) return;
    liberarArbol(r->izq);
    liberarArbol(r->der);
    free(r);
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    int n, i;
    tPerfume p;
    tArbol* raiz = NULL;

    printf("Ingrese la cantidad de perfumes a agregar: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Cantidad invalida.\n");
        return 1;
    }
    limpiarBuffer();

    for (i = 0; i < n; ++i) {
        printf("\nPerfume %d:\n", i + 1);

        printf("Codigo: ");
        fgets(p.codigo, sizeof(p.codigo), stdin);
        p.codigo[strcspn(p.codigo, "\n")] = '\0';  // eliminar salto de línea

        printf("Nombre: ");
        fgets(p.nombre, sizeof(p.nombre), stdin);
        p.nombre[strcspn(p.nombre, "\n")] = '\0';

        printf("Marca: ");
        fgets(p.marca, sizeof(p.marca), stdin);
        p.marca[strcspn(p.marca, "\n")] = '\0';

        printf("Precio: ");
        while (scanf("%f", &p.precio) != 1) {
            printf("Entrada invalida. Ingrese un numero para el precio: ");
            limpiarBuffer();
        }
        limpiarBuffer();

        printf("Stock: ");
        while (scanf("%d", &p.stock) != 1) {
            printf("Entrada invalida. Ingrese un entero para el stock: ");
            limpiarBuffer();
        }
        limpiarBuffer();

        raiz = insertar(raiz, p);
    }

    printf("\nFormato: Codigo\tNombre\t\tMarca\t\tPrecio\tStock\n\n");

    printf("== In-Order (ascendente por codigo) ==\n");
    inOrder(raiz);
    printf("\n== Pre-Order ==\n");
    preOrder(raiz);
    printf("\n== Post-Order ==\n");
    postOrder(raiz);

    liberarArbol(raiz);
    return 0;
}

