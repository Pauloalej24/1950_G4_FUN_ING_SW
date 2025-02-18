#include <stdio.h>
#include <string.h>

// Estructura para representar un producto
struct Producto {
    int id;
    char nombre[50];
    int cantidad;
};

// Función para guardar los productos en un archivo
void guardar_productos(struct Producto productos[], int n) {
    FILE *archivo = fopen("productos.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para guardar.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(archivo, "%d %s %d\n", productos[i].id, productos[i].nombre, productos[i].cantidad);
    }

    fclose(archivo);
}

// Función para cargar los productos desde un archivo
int cargar_productos(struct Producto productos[]) {
    FILE *archivo = fopen("productos.txt", "r");
    if (archivo == NULL) {
        printf("No se encontró el archivo de productos. Se creará uno nuevo.\n");
        return 0;
    }

    int n = 0;
    while (fscanf(archivo, "%d %s %d", &productos[n].id, productos[n].nombre, &productos[n].cantidad) == 3) {
        n++;
    }

    fclose(archivo);
    return n;
}

// Función para validar si una cadena contiene solo caracteres alfabéticos
int validarNombre(const char *nombre) {
    for (int i = 0; nombre[i] != '\0'; i++) {
        if (!((nombre[i] >= 'a' && nombre[i] <= 'z') || (nombre[i] >= 'A' && nombre[i] <= 'Z') || nombre[i] == ' ')) {
            return 0; // No es válido
        }
    }
    return 1; // Es válido
}

// Función para buscar un producto por ID
void buscar_por_id(struct Producto productos[], int n, int id) {
    int encontrado = 0;
    for (int i = 0; i < n; i++) {
        if (productos[i].id == id) {
            printf("Producto encontrado: %s (ID: %d, Cantidad: %d)\n", productos[i].nombre, productos[i].id, productos[i].cantidad);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Producto con ID %d no encontrado.\n", id);
    }
}

// Función para buscar un producto por nombre
void buscar_por_nombre(struct Producto productos[], int n, char nombre[]) {
    int encontrado = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(productos[i].nombre, nombre) != NULL) {
            printf("Producto encontrado: %s (ID: %d, Cantidad: %d)\n", productos[i].nombre, productos[i].id, productos[i].cantidad);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("No se encontraron productos con el nombre \"%s\".\n", nombre);
    }
}

int main() {
    // Usuario y contraseña predefinidos
    char usuarioAdmin[] = "ChaskiBots1";
    char contrasenaAdmin[] = "ChaskiBots1";

    // Variables para ingresar datos
    char usuario[20];
    char contrasena[20];

    printf("Inicio de sesión\n");
    printf("Usuario: ");
    scanf("%s", usuario);
    printf("Contraseña: ");
    scanf("%s", contrasena);

    // Verificar credenciales
    if (strcmp(usuario, usuarioAdmin) != 0 || strcmp(contrasena, contrasenaAdmin) != 0) {
        printf("Usuario o contraseña incorrectos.\n");
        return 1; // Salir del programa si las credenciales son incorrectas
    }

    printf("Inicio de sesión exitoso.\n");

    struct Producto productos[100]; // Array para almacenar productos
    int n = cargar_productos(productos); // Cargar productos desde el archivo

    int opcionPrincipal;
    do {
        printf("\nMenú Principal:\n");
        printf("1. Agregar producto\n");
        printf("2. Modificar cantidad de producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Buscar producto\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcionPrincipal);

        switch (opcionPrincipal) {
            case 1: {
                // Validar ID (solo números enteros)
                printf("Ingrese el ID del producto: ");
                int id;
                if (scanf("%d", &id) != 1) {
                    printf("Error en el ID. Debe ser un número entero.\n");
                    while (getchar() != '\n'); // Limpiar el buffer de entrada
                    break;
                }
                productos[n].id = id;

                // Validar Nombre (solo caracteres alfabéticos)
                printf("Ingrese el nombre del producto: ");
                char nombre[50];
                scanf(" %[^\n]s", nombre); // Leer el nombre con espacios
                if (!validarNombre(nombre)) {
                    printf("Error en el Nombre. Solo se permiten caracteres alfabéticos.\n");
                    break;
                }
                strcpy(productos[n].nombre, nombre);

                // Validar Cantidad (solo números enteros)
                printf("Ingrese la cantidad del producto: ");
                int cantidad;
                if (scanf("%d", &cantidad) != 1) {
                    printf("Error: Introduzca un número entero.\n");
                    while (getchar() != '\n'); // Limpiar el buffer de entrada
                    break;
                }
                productos[n].cantidad = cantidad;

                printf("\nProducto agregado:\n");
                printf("ID: %d\n", productos[n].id);
                printf("Nombre: %s\n", productos[n].nombre);
                printf("Cantidad: %d\n", productos[n].cantidad);

                n++; // Incrementar el contador de productos
                guardar_productos(productos, n); // Guardar los productos en el archivo
                break;
            }
          case 2: {
    // Modificar cantidad de producto
    int id, cantidad, opcionCantidad;
    printf("Ingrese el ID del producto a modificar: ");
    scanf("%d", &id);

    int encontrado = 0;
    for (int i = 0; i < n; i++) {
        if (productos[i].id == id) {
            encontrado = 1;
            do {
                printf("\n¿Desea agregar o disminuir la cantidad?\n");
                printf("1. Agregar cantidad\n");
                printf("2. Disminuir cantidad\n");
                printf("3. Salir\n");
                printf("Seleccione una opción: ");
                scanf("%d", &opcionCantidad);

                if (opcionCantidad == 1) {
                    printf("Ingrese la cantidad a agregar: ");
                    if (scanf("%d", &cantidad) != 1 || cantidad < 0) {
                        printf("Error: Introduzca un número entero no negativo.\n");
                        while (getchar() != '\n'); // Limpiar el buffer de entrada
                        continue;
                    }
                    productos[i].cantidad += cantidad;
                    printf("Nueva cantidad: %d\n", productos[i].cantidad);
                } else if (opcionCantidad == 2) {
                    printf("Ingrese la cantidad a disminuir: ");
                    if (scanf("%d", &cantidad) != 1 || cantidad < 0) {
                        printf("Error: Introduzca un número entero no negativo.\n");
                        while (getchar() != '\n'); // Limpiar el buffer de entrada
                        continue;
                    }
                    if (cantidad <= productos[i].cantidad) {
                        productos[i].cantidad -= cantidad;
                        printf("Nueva cantidad: %d\n", productos[i].cantidad);
                    } else {
                        printf("No puedes reducir la cantidad a un valor negativo.\n");
                    }
                } else if (opcionCantidad == 3) {
                    printf("Saliendo...\n");
                } else {
                    printf("Opción inválida. Intenta nuevamente.\n");
                }
            } while (opcionCantidad != 3);
            guardar_productos(productos, n); // Guardar los productos en el archivo
            break;
        }
    }
    if (!encontrado) {
        printf("Producto con ID %d no encontrado.\n", id);
    }
    break;
}
case 3: {
    // Eliminar producto
    int opcionEliminar;
    printf("¿Desea buscar el producto por ID o por Nombre?\n");
    printf("1. ID\n");
    printf("2. Nombre\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcionEliminar);

    if (opcionEliminar == 1 || opcionEliminar == 2) {
        int id;
        char nombre[50];
        int encontrado = 0;

        if (opcionEliminar == 1) {
            // Buscar por ID
            printf("Ingrese el ID del producto a eliminar: ");
            if (scanf("%d", &id) != 1) {
                printf("Error: Introduzca un número entero.\n");
                while (getchar() != '\n'); // Limpiar el buffer de entrada
                break;
            }
        } else {
            // Buscar por nombre
            printf("Ingrese el nombre del producto a eliminar: ");
            scanf(" %[^\n]s", nombre);
        }

        // Buscar el producto
        for (int i = 0; i < n; i++) {
            if ((opcionEliminar == 1 && productos[i].id == id) || 
                (opcionEliminar == 2 && strstr(productos[i].nombre, nombre) != NULL)) {
                encontrado = 1;
                printf("Producto encontrado: %s (ID: %d, Cantidad: %d)\n", 
                       productos[i].nombre, productos[i].id, productos[i].cantidad);

                // Confirmar eliminación
                printf("¿Desea eliminar el producto?\n");
                printf("1: Eliminar producto\n");
                printf("2: No eliminar\n");
                int confirmar;
                printf("Seleccione una opción: ");
                scanf("%d", &confirmar);

                if (confirmar == 1) {
                    // Eliminar el producto (desplazar los elementos restantes)
                    for (int j = i; j < n - 1; j++) {
                        productos[j] = productos[j + 1];
                    }
                    n--; // Decrementar el contador de productos
                    printf("Producto eliminado.\n");
                    guardar_productos(productos, n); // Guardar los productos en el archivo
                } else {
                    printf("El producto no fue eliminado.\n");
                }
                break;
            }
        }

        if (!encontrado) {
            if (opcionEliminar == 1) {
                printf("Producto con ID %d no encontrado.\n", id);
            } else {
                printf("No se encontraron productos con el nombre \"%s\".\n", nombre);
            }
        }
    } else {
        printf("Opción no válida.\n");
    }
    break;
}            case 4: {
                // Buscar producto
                int opcionBusqueda, id;
                char nombre[50];
                printf("\nSeleccione una opción de búsqueda:\n");
                printf("1. Buscar por ID\n");
                printf("2. Buscar por Nombre\n");
                printf("Ingrese opción: ");
                scanf("%d", &opcionBusqueda);

                if (opcionBusqueda == 1) {
                    printf("Ingrese el ID del producto: ");
                    if (scanf("%d", &id) != 1) {
                        printf("Ingrese el ID correcto (número entero).\n");
                        while (getchar() != '\n'); // Limpiar el buffer de entrada
                        break;
                    }
                    buscar_por_id(productos, n, id);
                } else if (opcionBusqueda == 2) {
                    printf("Ingrese el nombre del producto: ");
                    scanf(" %[^\n]s", nombre);  // Para leer el nombre con espacios
                    if (!validarNombre(nombre)) {
                        printf("Error: Solo se permiten caracteres alfabéticos.\n");
                        break;
                    }
                    buscar_por_nombre(productos, n, nombre);
                } else {
                    printf("Opción no válida.\n");
                }
                break;
            }
            case 5: {
                printf("Saliendo...\n");
                break;
            }
            default: {
                printf("Opción no válida. Intente nuevamente.\n");
                break;
            }
        }
    } while (opcionPrincipal != 5);

    return 0;
}
