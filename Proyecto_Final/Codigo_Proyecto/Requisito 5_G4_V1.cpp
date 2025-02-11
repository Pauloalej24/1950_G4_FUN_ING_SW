#include <stdio.h>
#include <string.h>
struct Producto {
    int id;
    char nombre[50];
};
void buscar_por_id(struct Producto productos[], int n, int id) {
    int encontrado = 0;
    for (int i = 0; i < n; i++) {
        if (productos[i].id == id) {
            printf("Producto encontrado: %s (ID: %d)\n", productos[i].nombre, productos[i].id);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Producto con ID %d no encontrado.\n", id);
    }
}
void buscar_por_nombre(struct Producto productos[], int n, char nombre[]) {
    int encontrado = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(productos[i].nombre, nombre) != NULL) {
            printf("Producto encontrado: %s (ID: %d)\n", productos[i].nombre, productos[i].id);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("No se encontraron productos con el nombre \"%s\".\n", nombre);
    }
}
int main() {
    int n;
    struct Producto productos[n];
    int opcion, id;
    char nombre[50];
    printf("\nSeleccione una opción de búsqueda:\n");
    printf("1. Buscar por ID\n");
    printf("2. Buscar por Nombre\n");
    printf("Ingrese opción: ");
    scanf("%d", &opcion);   
    if (opcion == 1) {
        printf("Ingrese el ID del producto: ");
        scanf("%d", &id);
        buscar_por_id(productos, n, id);
    } else if (opcion == 2) {
        printf("Ingrese el nombre del producto: ");
        scanf(" %[^\n]s", nombre);  // Para leer el nombre con espacios
        buscar_por_nombre(productos, n, nombre);
    } else {
        printf("Opción no válida.\n");
    }
    return 0;
}

