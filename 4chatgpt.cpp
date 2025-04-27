#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int validarArchivo(FILE *ar);
bool validarDniRepetido(FILE *archivo, int dni);
void guardarDatos(FILE *archivo, char *nombre, char *apellido, int dni);
void buscarPorNombreYApellido(FILE *archivo, char *nombBusc, char *apellidoBusc);
void mostrarOrdenado(FILE *ar, int opc);
int main() {
    FILE *archivo;
    char nombre[30], apellido[30];
    char nombBusc[30], apellidoBusc[30];
    int dni, op, opcOrdenado;
    bool seguir = true;

    do {
        printf("\nIngrese una opcion: \n");
        printf("1. Ingresar datos\n");
        printf("2. Buscar por Nombre y Apellido\n");
        printf("3. Salir\n");
        printf("4. Mostrar ordenado\n");
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

                // Cierra el archivo antes de volver a abrirlo en modo lectura
                fclose(archivo);

                archivo = fopen("usuarios.txt", "r");
                if (archivo == NULL) {
                    printf("Error al abrir el archivo.\n");
                    break;
                }

                if (validarDniRepetido(archivo, dni)) {
                    printf("El DNI ya existe.\n");
                } else {
                    guardarDatos(archivo, nombre, apellido, dni);
                }

                fclose(archivo);
                break;

            case 2:
                printf("Ingrese el nombre que desea buscar: ");
                scanf("%s", nombBusc);
                printf("Ingrese el apellido que desea buscar: ");
                scanf("%s", apellidoBusc);

                archivo = fopen("usuarios.txt", "r");
                if (archivo == NULL) {
                    printf("Error al abrir el archivo.\n");
                    break;
                }

                buscarPorNombreYApellido(archivo, nombBusc, apellidoBusc);

                fclose(archivo);
                break;

            case 3:
                seguir = false;
                printf("Saliendo del programa\n");
                break;

            case 4:
                archivo = fopen("usuarios.txt", "r");
                if (validarArchivo(archivo) != 0) {
                    break;
                }

                printf("\tIngrese 5 para ordenar por nombre primero.\n");
                printf("\tIngrese 6 para ordenar por apellido primero.\n");
                printf("\tIngrese 7 para ordenar por DNI primero.\n");
                printf("\tIngrese opcion: ");
                scanf("%d", &opcOrdenado);
                
                mostrarOrdenado(archivo, opcOrdenado);

                fclose(archivo);
                break;
        }
    } while (seguir);

    return 0;
}


int validarArchivo(FILE *ar){
    if (ar == NULL) {
        printf("\nError al abrir el archivo\n\n");
        return 1;
    } else {
        return 0;
    }
}

bool validarDniRepetido(FILE *archivo, int dni) {
    char nombre[30], apellido[30];
    int dniTemp;
    
    while (fscanf(archivo, "%s %s %d", nombre, apellido, &dniTemp) != EOF) {
        if (dniTemp == dni) {
            return true;  
        }
    }
    return false;  
}

void guardarDatos(FILE *archivo, char *nombre, char *apellido, int dni) {
    fprintf(archivo, "%s %s %d\n", nombre, apellido, dni);
    printf("Datos guardados correctamente.\n");
}

void buscarPorNombreYApellido(FILE *archivo, char *nombBusc, char *apellidoBusc) {
    char nombre[30], apellido[30];
    int dni;
    bool encontrado = false;

    while (fscanf(archivo, "%s %s %d", nombre, apellido, &dni) != EOF) {
        if (strcmp(apellido, apellidoBusc) == 0 && strcmp(nombre, nombBusc) == 0) {
            printf("Nombre: %s\n", nombre);
            printf("Apellido: %s\n", apellido);
            printf("DNI: %d\n", dni);
            encontrado = true;
            break;
        }
    }
    
    if (!encontrado) {
        printf("No se encontró al usuario.\n");
    }
}

void mostrarOrdenado(FILE *ar, int opc){
    char nombre[50], apellido[50];
    int DNI, DNIs[50];    
    char nombres[50][50], apellidos[50][50];
    int N = 0, i = 0, j = 0;
    
    while (fscanf(ar, "%s %s %d", nombre, apellido, &DNI) == 3) {
        strcpy(nombres[i], nombre);
        strcpy(apellidos[i], apellido);
        DNIs[i] = DNI;
        i++;
        N++;
    }
    
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - i - 1; j++) {
            int cmp = 0;
            
            if (opc == 5) {
                cmp = strcmp(nombres[j], nombres[j + 1]) > 0;
            } else if (opc == 6) {
                cmp = strcmp(apellidos[j], apellidos[j + 1]) > 0;
            } else if (opc == 7) {
                cmp = DNIs[j] > DNIs[j + 1];
            }
            
            if (cmp == 1) {
                char temp[50];
                strcpy(temp, nombres[j]);
                strcpy(nombres[j], nombres[j + 1]);
                strcpy(nombres[j + 1], temp);
                
                strcpy(temp, apellidos[j]);
                strcpy(apellidos[j], apellidos[j + 1]);
                strcpy(apellidos[j + 1], temp);

                int tempDNIs = DNIs[j];
                DNIs[j] = DNIs[j + 1];
                DNIs[j + 1] = tempDNIs;
            }
        }
    }    
    
    for (i = 0; i < N; i++) {
        printf("\nPersona numero %d:\n", i + 1);
        printf("Nombre: %s\nApellido: %s\nDNI: %d\n\n", nombres[i], apellidos[i], DNIs[i]);
    }    
}

