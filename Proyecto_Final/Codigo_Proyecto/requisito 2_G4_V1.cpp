n#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 100

typedef struct {
    int id;
    char nombre[50];
    char categoria[30];
    int cantidad;
} Producto;

void agregarProducto(Producto productos[], int *cantidadProductos) {
    if (*cantidadProductos >= MAX_PRODUCTOS) {
        printf("El inventario está lleno.\n");
        return;
    }

    Producto nuevoProducto;
    nuevoProducto.id = *cantidadProductos + 1;
    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]", nuevoProducto.nombre);
    printf("Ingrese la categoría del producto: ");
    scanf(" %[^\n]", nuevoProducto.categoria);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &nuevoProducto.cantidad);

    productos[*cantidadProductos] = nuevoProducto;
    (*cantidadProductos)++;
}

void listarProductos(Producto productos[], int cantidadProductos) {
    for (int i = 0; i < cantidadProductos; i++) {
        printf("ID: %d, Nombre: %s, Categoría: %s, Cantidad: %d\n",
               productos[i].id, productos[i].nombre, productos[i].categoria, productos[i].cantidad);
    }
}

void actualizarProducto(Producto productos[], int cantidadProductos) {
    int id;
    printf("Ingrese el ID del producto a actualizar: ");
    scanf("%d", &id);

    for (int i = 0; i < cantidadProductos; i++) {
        if (productos[i].id == id) {
            printf("Ingrese el nuevo nombre del producto: ");
            scanf(" %[^\n]", productos[i].nombre);
            printf("Ingrese la nueva categoría del producto: ");
            scanf(" %[^\n]", productos[i].categoria);
            printf("Ingrese la nueva cantidad del producto: ");
            scanf("%d", &productos[i].cantidad);
            printf("Producto actualizado con éxito.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

int main() {
    Producto productos[MAX_PRODUCTOS];
    int cantidadProductos = 0;
    int opcion;

    do {
        printf("1. Agregar Producto\n2. Listar Productos\n3. Actualizar Producto\n4. Salir\nIngrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarProducto(productos, &cantidadProductos);
                break;
            case 2:
                listarProductos(productos, cantidadProductos);
                break;
            case 3:
                actualizarProducto(productos, cantidadProductos);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 4);

    return 0;
}

