#include <stdio.h>
#include <string.h>

int main() {
    int id;
    char nombre[50];

    // Pedir al usuario que ingrese el nombre y el ID del producto
    printf("Ingrese el ID del producto: ");
    scanf("%d", &id);

    printf("Ingrese el nombre del producto: ");
    scanf("%s", &nombre);
    // Mostrar los datos ingresados
    printf("\nProducto agregado:\n");
    printf("ID: %d\n", id);
    printf("Nombre: %s\n", nombre);
    return 0;
}
