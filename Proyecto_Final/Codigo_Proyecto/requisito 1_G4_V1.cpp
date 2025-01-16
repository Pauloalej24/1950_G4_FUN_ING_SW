#include <stdio.h>
#include <string.h>

int main() {
    // Usuario y contraseña predefinidos
    char usuarioAdmin[]= "ChaskiBots1";
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
    if (strcmp(usuario, usuarioAdmin) == 0 && strcmp(contrasena, contrasenaAdmin) == 0) {
        printf("Inicio de sesión exitoso.\n");
    } else {
        printf("Usuario o contraseña incorrectos.\n");
    }
}
