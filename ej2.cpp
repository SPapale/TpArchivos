#include <stdio.h>
#include <string.h>
main(){
		FILE *archivo;
		char nombre[30], apellido[30];
		char nombBusc[30], apellidoBusc[30];
		int dni,i, cantidad, dniBusc; 
		
		archivo = fopen("usuarios.txt", "w");
	
		printf("Ingrese la cantidad de usuarios:");
		scanf("%d", &cantidad);
		getchar();

		for(i=0; i<cantidad; i++){
		printf("\nIngrese el Nombre: ");
		fgets(nombre, sizeof(nombre), stdin);
		nombre[strcspn(nombre, "\n")] = '\0';
		printf("\nIngrese el Apellido: ");
		fgets(apellido, sizeof(apellido), stdin);
		apellido[strcspn(apellido, "\n")] = '\0';
		printf("\nIngrese el DNI: ");
		scanf("%d", &dni);
		getchar();
		fprintf(archivo, "Nombre %s", nombre);	
		fprintf(archivo, "Apellido %s", apellido);
		fprintf(archivo, "DNI %d", dni);
		}
		
			
		fclose(archivo);
		
		printf("Ingrese el DNI de la persona que quiere buscar \n");
		scanf("%d", &dniBusc);
		if(dni == dniBusc){
			strcpy(nombBusc, nombre);
			strcpy(apellidoBusc, apellido);
			printf("El nombre es %s y el apellido es %s", nombBusc, apellidoBusc);
		}
		
		//printf("\nDatos guardados en el archivo usuario.txt");	
		
	
}