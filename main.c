#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test = 10;
int main()
{
    //Tamano max de la linea que almacenemos
    const int TAMANO_MAX_LINE  = 300;
    //Tamano max del numero de lineas que podamos almacenar
    const int TAMANO_MAX_ARRAY = 5000;
    //Contador ayuda a saber cuantas lineas tenemos almacenadas
    int contador = 0;
    int i;
    //Definimos el arreglo donde se guardara todo el Log.
    char arregloLog[TAMANO_MAX_ARRAY][TAMANO_MAX_LINE];
    FILE *fileLog =fopen("vsftpd.log", "r");
    if(fileLog == NULL)
    {
        perror("No se pudo abrir el archivo");
        exit(1);
    }
    //Aca es donde guardamos momentaneamente las lineas del Log.
    char line[TAMANO_MAX_LINE];
    while(fgets(line,sizeof(line),fileLog))
    {
        strcpy(arregloLog[contador],line);
        contador++;
        //print the line
        printf("%s", line);
    }
    printf("El numero total de lineas es: %d\n",contador);
    printf("Aca empezamos a mostrar el arreglo que guardamos\n");
    printf("Aca mostrare una linea separada: \n");
    separador(arregloLog[0]);
    printf("\n");
    for(i = 0; i < contador; i++)
    {
        printf("%s",arregloLog[i]);
    }
    return 0;
}

void separador(char linea[]){
    char *token;
    token = strtok(linea," ");
    while(token != NULL){
        printf(" %s\n",token);
        token = strtok(NULL," ");
    }
    printf("Termina de separar\n");
}
