#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USUARIOS 100 // Número máximo de usuarios en el archivo

typedef struct {
    char nombre[30];
    char apellido[30];
    int dni;
} Usuario;
int compararPorNombre(const void *a, const void *b) {
    Usuario *usuarioA = (Usuario *)a;
    Usuario *usuarioB = (Usuario *)b;

    int cmpApellido = strcmp(usuarioA->apellido, usuarioB->apellido);
    if (cmpApellido == 0) {
        return strcmp(usuarioA->nombre, usuarioB->nombre);
    }
    return cmpApellido;
}

int compararPorDni(const void *a, const void *b) {
    Usuario *usuarioA = (Usuario *)a;
    Usuario *usuarioB = (Usuario *)b;
    return usuarioA->dni - usuarioB->dni;
}
int leerUsuarios(FILE *archivo, Usuario usuarios[]) {
    int count = 0;

    // Leer el archivo línea por línea
    while (fscanf(archivo, "%s %s %d", usuarios[count].nombre, usuarios[count].apellido, &usuarios[count].dni) != EOF) {
        count++;
        if (count >= MAX_USUARIOS) {
            break; // Limitar el número de usuarios al máximo permitido
        }
    }

    return count;
}
void mostrarUsuarios(Usuario usuarios[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("Nombre: %s\n", usuarios[i].nombre);
        printf("Apellido: %s\n", usuarios[i].apellido);
        printf("DNI: %d\n", usuarios[i].dni);
        printf("------------------------\n");
    }
}
int main() {
    FILE *archivo;
    Usuario usuarios[MAX_USUARIOS];
    int cantidadUsuarios, op, criterioOrdenar;
    bool seguir = true;

    do {
        printf("\nIngrese una opcion: \n");
        printf("1. Ingresar datos\n");
        printf("2. Buscar por Nombre y Apellido\n");
        printf("3. Mostrar usuarios ordenados\n");
        printf("4. Salir\n");
        scanf("%d", &op);
        getchar(); // Limpiar el buffer del teclado

        switch(op) {
            case 1:
                archivo = fopen("usuarios.txt", "a+");
                if (archivo == NULL) {
                    printf("Error al abrir el archivo.\n");
                    break;
                }

                char nombre[30], apellido[30];
                int dni;

                printf("Ingrese el nombre: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0'; // Eliminar salto de línea

                printf("Ingrese el Apellido: ");
                fgets(apellido, sizeof(apellido), stdin);
                apellido[strcspn(apellido, "\n")] = '\0'; // Eliminar salto de línea

                printf("Ingrese el DNI: ");
                scanf("%d", &dni);

                fprintf(archivo, "%s %s %d\n", nombre, apellido, dni);

                fclose(archivo);
                break;

            case 2:
                printf("Ingrese el nombre que desea buscar: ");
                char nombBusc[30];
                scanf("%s", nombBusc);
                printf("Ingrese el apellido que desea buscar: ");
                char apellidoBusc[30];
                scanf("%s", apellidoBusc);

                archivo = fopen("usuarios.txt", "r");
                if (archivo == NULL) {
                    printf("Error al abrir el archivo.\n");
                    break;
                }

                char nombreTemp[30], apellidoTemp[30];
                int dniTemp;
                bool encontrado = false;

                while(fscanf(archivo, "%s %s %d", nombreTemp, apellidoTemp, &dniTemp) != EOF) {
                    if (strcmp(apellidoTemp, apellidoBusc) == 0 && strcmp(nombreTemp, nombBusc) == 0) {
                        printf("Nombre: %s\n", nombreTemp);
                        printf("Apellido: %s\n", apellidoTemp);
                        printf("DNI: %d\n", dniTemp);
                        encontrado = true;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("No se encontró el usuario.\n");
                }

                fclose(archivo);
                break;

            case 3:
                // Leer usuarios desde el archivo
                archivo = fopen("usuarios.txt", "r");
                if (archivo == NULL) {
                    printf("Error al abrir el archivo.\n");
                    break;
                }

                cantidadUsuarios = leerUsuarios(archivo, usuarios);
                fclose(archivo);

                printf("\nSeleccione el criterio de ordenamiento:\n");
                printf("1. Ordenar por nombre y apellido\n");
                printf("2. Ordenar por DNI\n");
                scanf("%d", &criterioOrdenar);

                // Ordenar según el criterio seleccionado
                if (criterioOrdenar == 1) {
                    qsort(usuarios, cantidadUsuarios, sizeof(Usuario), compararPorNombre);
                } else if (criterioOrdenar == 2) {
                    qsort(usuarios, cantidadUsuarios, sizeof(Usuario), compararPorDni);
                } else {
                    printf("Criterio no válido.\n");
                    break;
                }

                // Mostrar los usuarios ordenados
                mostrarUsuarios(usuarios, cantidadUsuarios);
                break;

            case 4:
                seguir = false;
                printf("Saliendo del programa\n");
                break;
        }
    } while (seguir);

    return 0;
}
