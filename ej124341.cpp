#include <stdio.h>
#include <string.h>



int main() {
    FILE *archivo;
    char nombre[30], apellido[30];
    int dni, dniBusc;
    int i, cantidad;
    int dnis[100]; 

    archivo = fopen("usuarios.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    printf("Ingrese la cantidad de usuarios: ");
    scanf("%d", &cantidad);
    getchar(); 

    for (i = 0; i < cantidad; i++) {
        int dniDuplicado;
        
        do {
            dniDuplicado = 0;
            printf("\nIngrese el Nombre: ");
            fgets(nombre, sizeof(nombre), stdin);
            nombre[strcspn(nombre, "\n")] = '\0'; 

            printf("Ingrese el Apellido: ");
            fgets(apellido, sizeof(apellido), stdin);
            apellido[strcspn(apellido, "\n")] = '\0'; 

            printf("Ingrese el DNI: ");
            scanf("%d", &dni);
            getchar(); 

          
            for (int j = 0; j < i; j++) {
                if (dnis[j] == dni) {
                    printf("Ese DNI ya fue ingresado. Intente nuevamente.\n");
                    dniDuplicado = 1;
                    break;
                }
            }

        } while (dniDuplicado);

        dnis[i] = dni;

        fprintf(archivo, "%s %s %d\n", nombre, apellido, dni);
    }

    fclose(archivo);


    archivo = fopen("usuarios.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return 1;
    }

    printf("\nIngrese el DNI de la persona que quiere buscar: ");
    scanf("%d", &dniBusc);

    int encontrado = 0;
        if (dni == dniBusc) {
            printf("El nombre es %s y el apellido es %s\n", nombre, apellido);
            encontrado = 1;
            
        }
    

    if (!encontrado) {
        printf("DNI no encontrado.\n");
    }

    fclose(archivo);
    
}
