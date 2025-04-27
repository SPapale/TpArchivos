#include <stdio.h>
#include <string.h> 
#include <stdbool.h> 

int main() {
    FILE *archivo;
    char nombre[30], apellido[30];
    char nombreIngre[30], apellidoIngre[30];
    char apellidoBusc[30], nombBusc[30];
    int dni, op, dniIngre;
    bool seguir = true; 
    bool encontrado = false;
    bool dniRepe = false;

    do {
        printf("\nIngrese una opcion: \n");
        printf("1. Ingresar datos\n");
        printf("2. Buscar por Nombre y Apellido\n");
        printf("3. Salir\n");
        scanf("%d", &op);
        getchar(); 

        switch(op) {
        	
        	dniRepe = false;
            case 1:
                archivo = fopen("usuarios.txt", "r"); 
                

                printf("Ingrese el nombre: ");
                scanf("%s", nombreIngre); 

                printf("Ingrese el Apellido: ");
                scanf("%s", apellidoIngre);
                printf("Ingrese el DNI: ");
                scanf("%d", &dniIngre);

                if (archivo != NULL) {
                char nombreTemp[30], apellidoTemp[30];
                int dniTemp;

                while(fscanf(archivo, "%s %s %d", nombreTemp, apellidoTemp, &dniTemp) != EOF){
                    if(dniTemp == dni){
                        printf("El DNI ya existe\n");
                        dniRepe = true;
                        break;
                    }
                }
                fclose(archivo);
            }

            if (!dniRepe) {
                archivo = fopen("usuarios.txt", "a");
                if(archivo == NULL){
                    printf("No se pudo abrir el archivo\n");
                    return 1;
                }

                strcpy(nombre, nombreIngre);
                strcpy(apellido, apellidoIngre);
                dni = dniIngre;

                fprintf(archivo, "%s %s %d\n", nombre, apellido, dni);
                printf("Datos guardados correctamente.\n");
                fclose(archivo);
            }
        

            if(archivo == NULL){
                printf("No se pudo abrir el archivo\n");
                return 1;
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

               
                while(fscanf(archivo, "%s %s %d", nombre, apellido, &dni) != EOF){
                if(strcmp(apellido, apellidoBusc) == 0 && strcmp(nombre, nombBusc) == 0){
                    printf("Nombre: %s\n", nombre);
                    printf("Apellido: %s\n", apellido);
                    printf("DNI: %d\n", dni);
                }
            }

                fclose(archivo);

               
                break;

            case 3:
                seguir = false;
                printf("Saliendo del programa\n");
                break;

            
        }
    } while (seguir);

    return 0;
}
