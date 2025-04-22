#include <stdio.h>
#include <string.h>
main(){
		FILE *archivo;
		char nombre[30], apellido[30];
		char nombBusc[30], apellidoBusc[30];
		int dni,i, cantidad, dniBusc; 
		int dnis[100];
		archivo = fopen("usuarios.txt", "w");
		if(archivo == NULL){
			printf("No se encontro el archivo");
		}
	
		printf("Ingrese la cantidad de usuarios:");
		scanf("%d", &cantidad);
		getchar();


		for(i=0; i<cantidad; i++){
		int dniDos;
		do{
		
		printf("\nIngrese el Nombre: ");
		fgets(nombre, sizeof(nombre), stdin);
		nombre[strcspn(nombre, "\n")] = '\0';
		
		printf("\nIngrese el Apellido: ");
		fgets(apellido, sizeof(apellido), stdin);
		apellido[strcspn(apellido, "\n")] = '\0';
		
		printf("\nIngrese el DNI: ");
		scanf("%d", &dni);
		getchar();
		
		for(int j=0; j<i; j++){
			if (dnis[j] == dni) {
                printf("Ese DNI ya fue ingresado\n");
                dniDos = 1;
		}
	}
} while(dniDos);
	 dnis[i] = dni;


        fprintf(archivo, "%s %s %d\n", nombre, apellido, dni);	
}
		fclose(archivo);
		
		printf("Ingrese el DNI de la persona que quiere buscar \n");
		scanf("%d", &dniBusc);
		if(dniBusc == dni){
			strcpy(nombBusc, nombre);
			strcpy(apellidoBusc, apellido);
			printf("El nombre es %s y el apellido es %s", nombBusc, apellidoBusc);
		}
		
		//printf("\nDatos guardados en el archivo usuario.txt");	
		

}