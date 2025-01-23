#include <stdio.h>
#include <string.h>
int main() {
    int id;
    char nombre[50];
    int cantidad;
    printf("Ingrese el ID del producto: ");
    scanf("%d", &id);
    printf("Ingrese el nombre del producto: ");
    scanf("%s", &nombre);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &cantidad);
    int opcion; 
    do {
        printf("\n¿Desea agregar o disminuir la cantidad?\n");
        printf("1. Agregar cantidad\n");
        printf("2. Disminuir cantidad\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        if (opcion == 1) {
            printf("Ingrese la cantidad a agregar: ");
            scanf("%d", &cantidad);
            cantidad += cantidad;
            printf("Nueva cantidad: %d\n", cantidad);
        } else if (opcion == 2) {
            printf("Ingrese la cantidad a disminuir: ");
            scanf("%d", &cantidad);
            if (cantidad <= cantidad) {
                cantidad -= cantidad;
                printf("Nueva cantidad: %d\n",cantidad);
            } else {
                printf("No puedes reducir la cantidad a un valor negativo.\n");
            }
        } else if (opcion == 3) {
            printf("Saliendo...\n");
        } else {
            printf("Opción inválida. Intenta nuevamente.\n");
        }
    } while(opcion != 3);
    return 0;
}









