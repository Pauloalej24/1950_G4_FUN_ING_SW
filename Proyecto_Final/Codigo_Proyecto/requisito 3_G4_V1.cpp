#include <stdio.h>
#include <string.h>

// Estructura para representar un producto
struct Producto {
    int id;
    char nombre[50];
    int cantidad;
};

int main() {
    struct Producto producto;

    // Pedir al usuario que ingrese el ID, nombre y cantidad del producto
    printf("Ingrese el ID del producto: ");
    scanf("%d", &producto.id);
    getchar();  // Para consumir el salto de línea después de ingresar el ID

    printf("Ingrese el nombre del producto: ");
    fgets(producto.nombre, sizeof(producto.nombre), stdin);
    producto.nombre[strcspn(producto.nombre, "\n")] = '\0';  // Eliminar el salto de línea

    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &producto.cantidad);

    int opcion, cantidad;
    do {
        printf("\n¿Desea agregar o disminuir la cantidad?\n");
        printf("1. Agregar cantidad\n");
        printf("2. Disminuir cantidad\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Ingrese la cantidad a agregar: ");
                scanf("%d", &cantidad);
                producto.cantidad += cantidad;
                printf("Nueva cantidad: %d\n", producto.cantidad);
                break;
            case 2:
                printf("Ingrese la cantidad a disminuir: ");
                scanf("%d", &cantidad);
                if (cantidad <= producto.cantidad) {
                    producto.cantidad -= cantidad;
                    printf("Nueva cantidad: %d\n", producto.cantidad);
                } else {
                    printf("No puedes reducir la cantidad a un valor negativo.\n");
                }
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida. Intenta nuevamente.\n");
        }
    } while(opcion != 3);

    return 0;
}
