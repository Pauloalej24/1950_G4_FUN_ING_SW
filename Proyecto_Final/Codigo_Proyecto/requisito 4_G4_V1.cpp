#include <stdio.h>
#include <string.h>

// Estructura para representar un producto
struct Producto {
    int id;
    char nombre[50];
};

int main() {
    struct Producto producto;

    // Pedir al usuario que ingrese el ID y nombre del producto
    printf("Ingrese el ID del producto: ");
    scanf("%d", &producto.id);
    getchar();  // Para consumir el salto de l�nea despu�s de ingresar el ID

    printf("Ingrese el nombre del producto: ");
    fgets(producto.nombre, sizeof(producto.nombre), stdin);
    producto.nombre[strcspn(producto.nombre, "\n")] = '\0';  // Eliminar el salto de l�nea

    int opcion;
    printf("\n�Desea eliminar el producto?\n");
    printf("1. Eliminar producto\n");
    printf("2. No eliminar\n");
    printf("Seleccione una opci�n: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        // Eliminamos el producto (borramos los datos)
        producto.id = 0;
        strcpy(producto.nombre, "");
        
        printf("\nProducto eliminado.\n");
    } else {
        printf("\nEl producto no fue eliminado.\n");
    }

    // Mostrar los datos del producto (deber�an ser 0 o vac�os si se elimin�)
    printf("\nID: %d\n", producto.id);
    printf("Nombre: %s\n", producto.nombre);

    return 0;
}
