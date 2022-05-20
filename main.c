#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cantidad de variables extraidas de cada la linea Log.
static int NUMERO_VAR_LOG = 20;
//Tamano maximo de cada variable extraida de la linea Log.
static int NUMERO_TAM_VAR = 35;
//Definimos un arreglo donde guardaremos todas las variables extraidas de cada linea del Log.
char lineaLog[20][35];
char dia[3];
char mes[3];
int diaN;
char hora[8];
int anio;
char usuario[16];
char ip[23];
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
    //separador(arregloLog[0]);
    printf("\n");
    printf("Aca mostrare la segunda linea: \n");
    separadorDeLineas(arregloLog[2]);
    /*for(i = 0; i < contador; i++)
    {
        printf("%s",arregloLog[i]);
    }*/
    return 0;
}

void separadorDeLineas(char linea[])
{
    int contador = 0;
    char *token;
    token = strtok(linea," ");
    while(token != NULL)
    {
        printf(" %s\n",token);
        strcpy(lineaLog[contador],token);
        token = strtok(NULL," ");
        contador++;

    }
    printf("Termina de separar\n");
    printf("Probando el nuevo array separado\n");
    printf("Contador: %d",contador);
    printf("Prueba de impresion\n");
    printf("[0]:%s\n",lineaLog[1]);
    //separadorDeVariables(lineaLog,contador);
}

void separadorDeVariables(char linea[],int contador)
{
    printf("contador:%d\n",contador);
    int i;
    for(i = 0; i< contador; i++){
        printf("%c\n",linea[i]);
    }
}
