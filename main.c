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
char estado[4];
char accion[10];
char ip[23];
char rutaFile[50];
int peso;
char velocidad[20];
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
    printf("Contador: %d\n",contador);
    printf("Prueba de impresion\n");
    //printf("[0]:%s\n",lineaLog[1]);
    separadorDeVariables(contador);
}

void separadorDeVariables(int contador)
{
    printf("contador:%d\n",contador);
    int i;
    for(i = 0; i< contador; i++){

        printf("%s\n", lineaLog[i]);
    }
    strcpy(dia,lineaLog[0]);
    strcpy(mes,lineaLog[1]);
    diaN = atoi(lineaLog[2]);
    strcpy(hora,lineaLog[3]);
    anio = atoi(lineaLog[4]);
    strcpy(usuario,lineaLog[7]);
    strcpy(estado,lineaLog[8]);
    strcpy(accion,lineaLog[9]);
    accion[strlen(accion)-1]= '\0';
    strcpy(ip,lineaLog[11]);
    ip[strlen(ip)-1] = '\0';
    strcpy(rutaFile,lineaLog[12]);
    rutaFile[strlen(rutaFile)-1]= '\0';
    peso = atoi(lineaLog[13]);
    strcpy(velocidad,lineaLog[15]);
    printf("dia = %s, mes = %s, diaN = %d, hora = %s, anio = %d, usuario = %s, estado = %s, accion = %s, ip = %s\n",dia,mes,diaN,hora,anio,usuario,estado,accion,ip);
    printf("Ruta = %s, Peso = %d, Velocidad = %s",rutaFile,peso,velocidad);
}
