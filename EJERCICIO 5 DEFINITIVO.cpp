#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdbool.h>


struct Usuario{
    char nombre[30];
    char apellido[30];
};

int main(){

    FILE *archivo, *archivo2;
    struct Usuario usuario;
    char linea[100];

    archivo = fopen("usuarios.txt", "r+");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo original\n");
        return 1;
    }

    fprintf(archivo, "Nombre: Juan\nApellido: Perez\n");

    printf("Ingrese el nombre: ");
    scanf("%29s", usuario.nombre);

    printf("Ingrese el apellido: ");
    scanf("%29s", usuario.apellido);

    archivo2 = fopen("usuarios2.txt", "w+");
    if (archivo2 == NULL) {
        printf("Error al crear el archivo");
        fclose(archivo);
        return 1;
    }

    while(fgets(linea, sizeof(linea), archivo) != NULL){
      fputs(linea, archivo2);
    }
    
    fprintf(archivo2, "Nombre: %s\nApellido: %s\n", usuario.nombre, usuario.apellido);

    fclose(archivo);
    fclose(archivo2);

    printf("\nArchivo 1:\n");
    
    archivo = fopen("usuarios.txt", "r");
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }
    fclose(archivo);

    printf("\nArchivo 2:\n");
    archivo2 = fopen("usuarios2.txt", "r");
    while (fgets(linea, sizeof(linea), archivo2) != NULL) {
        printf("%s", linea);
    }
    fclose(archivo2);

    return 0;
}