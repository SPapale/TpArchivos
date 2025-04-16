#include <stdio.h>
#include <strings.h>
main(){
		FILE *archivo;
		char nombre[30], apellido[30];
		int dni; 
		
		archivo = fopen("usuarios.txt", "w");
		
		printf("Ingrese el nombre: ");
		fgets(nombre, sizeof(nombre), stdin);
		
		printf("\nIngrese el Apellido: ");
		fgets(apellido, sizeof(apellido), stdin);
		
		printf("\nIngrese el DNI: ");
		scanf("%d", &dni);
			
		fprintf(archivo, "Nombre %s", nombre);	
		fprintf(archivo, "Apellido %s", apellido);
		fprintf(archivo, "DNI %d", dni);
			
		fclose(archivo);
		
		printf("\n Datos guardados en el archivo usuario.txt");	
		
	
}