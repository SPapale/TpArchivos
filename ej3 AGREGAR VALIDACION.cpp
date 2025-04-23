#include <stdio.h>
#include <string.h>
main(){
		FILE *archivo;
		char nombre[30], apellido[30];
		char nombBusc[30], apellidoBusc[30];
		int dni,i, cantidad, dniBusc, dnis[100], j, dniDuplicado; 
		
		archivo = fopen("usuarios.txt", "w");
	
		printf("Ingrese la cantidad de usuarios:");
		scanf("%d", &cantidad);
		getchar();

		for(i=0; i<cantidad; i++){
		
		
		
		do{
			dniDuplicado=0;
		printf("\nIngrese el Nombre: ");
		fgets(nombre, sizeof(nombre), stdin);
		nombre[strcspn(nombre, "\n")] = '\0';
		
		printf("\nIngrese el Apellido: ");
		fgets(apellido, sizeof(apellido), stdin);
		apellido[strcspn(apellido, "\n")] = '\0';
		
		printf("\nIngrese el DNI: ");
		scanf("%d", &dni);
		getchar();
		
			for(j=0; j<i; j++){
				if (dnis[j] == dni) {
                printf("Ese DNI ya fue ingresado. Intente nuevamente.\n");
                dniDuplicado = 1;
                break;
				}
			}
		
		} while(dniDuplicado);
		
		dnis[i] = dni;
		fprintf(archivo, "Nombre %s\n", nombre);	
		fprintf(archivo, "Apellido %s\n", apellido);
		fprintf(archivo, "DNI %d\n", dni);
		
	
		}		
		fclose(archivo);
		
		archivo = fopen("usuarios.txt", "r");
		
		printf("Ingrese el nombre de la persona que quiere buscar \n");
		scanf("%s", nombBusc);
		printf("Ingrese el apellido de la persona que quiere buscar \n");
		scanf("%s", apellidoBusc);
		
		while (fscanf(archivo, "Nombre %s\nApellido %s\nDNI %d\n", nombre, apellido, &dni)==3){ 
		if(strcmp(nombBusc, nombre) == 0 && strcmp(apellidoBusc, apellido) == 0){
			printf("El nombre es %s y el apellido es %s, ", nombBusc, apellidoBusc);
			printf("dni es %d \n", dni);
		}
	}
		//printf("\nDatos guardados en el archivo usuario.txt");	
		fclose(archivo);
		
	
}