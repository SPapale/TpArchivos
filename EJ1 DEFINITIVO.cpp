#include <stdio.h>
#include <string.h> 
#include <stdbool.h> 

int main() {
    FILE *archivo;
    char nombre[30], apellido[30];
    int dni, op, dniBusc;
    bool seguir = true; 
     bool encontrado = false;

    do {
        printf("\nIngrese una opcion: \n");
        printf("1. Ingresar datos\n");
        printf("2. Buscar por DNI\n");
        printf("3. Salir\n");
        scanf("%d", &op);
        getchar(); 

        switch(op) {
            case 1:
                archivo = fopen("usuarios.txt", "a+"); 
                if (archivo == NULL) {
                    printf("Error al abrir el archivo.\n");
                    break;
                }

                printf("Ingrese el nombre: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0'; 

                printf("Ingrese el Apellido: ");
                fgets(apellido, sizeof(apellido), stdin);
                apellido[strcspn(apellido, "\n")] = '\0'; 

                printf("Ingrese el DNI: ");
                scanf("%d", &dni);

                fprintf(archivo, "%s %s %d\n", nombre, apellido, dni);

                fclose(archivo);
                
                break;

            case 2:
                printf("Ingrese el DNI de la persona que quiere buscar: ");
                scanf("%d", &dniBusc);

                archivo = fopen("usuarios.txt", "r");
                if (archivo == NULL) {
                    printf("Error al abrir el archivo.\n");
                    break;
                }

               
                while (fscanf(archivo, "%s %s %d", nombre, apellido, &dni) == 3) {
                    if (dni == dniBusc) {
                        printf("Nombre: %s\n", nombre);
                        printf("Apellido: %s\n", apellido);
                        printf("DNI: %d\n", dni);
                        encontrado = true;
                        break;
                    }
                }

                fclose(archivo);

                if (!encontrado) {
                    printf("No se encontró el DNI ingresado.\n");
                }
                break;

            case 3:
                seguir = false;
                printf("Saliendo del programa.\n");
                break;

            
        }
    } while (seguir);

    return 0;
}
