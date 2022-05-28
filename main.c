#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cantidad de variables extraidas de cada la linea Log.
static int NUMERO_VAR_LOG = 20;
//Tamano maximo de cada variable extraida de la linea Log.
static int NUMERO_TAM_VAR = 35;
//Definimos un arreglo donde guardaremos todas las variables extraidas de cada linea del Log.
char lineaLog[20][35];
char sqlConsulta[100];
char dia[3];
char mes[3];
int diaN;
char hora[5];
int anio;
char usuario[16];
char estado[4];
char descripcion[23];
char ip[23];
char rutaFile[50];
int peso;
char velocidad[20];
int test = 10;
char anios[25];
char mesN[3] = "05";
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
    printf("\n");
    //printf("Aca mostrare la consulta final: \n");
    printf("Procedere a iterar todas las lineas y mostrarlas con formato para consulta Sqlite : \n");
    //separadorDeLineas(arregloLog[0]);

    for(int i = 0; i<contador; i++){
        separadorDeLineas(arregloLog[i]);
    }
    return 0;
}

void separadorDeLineas(char linea[])
{
    int contador = 0;
    char *token;
    token = strtok(linea," ");
    while(token != NULL)
    {
        //printf(" %s\n",token);
        strcpy(lineaLog[contador],token);
        token = strtok(NULL," ");
        contador++;

    }
    //printf("Termina de separar\n");
    //printf("Probando el nuevo array separado\n");
    //printf("Contador: %d\n",contador);
    //printf("Prueba de impresion\n");
    //printf("[0]:%s\n",lineaLog[1]);
    separadorDeVariables(contador);
}

void separadorDeVariables(int contador)
{
    //printf("Contador:%d\n",contador);
    int i;
    for(i = 0; i< contador; i++){

        //printf("%s\n", lineaLog[i]);
    }
    //itoa(mes,)
    printf("\n");
    strcpy(dia,lineaLog[0]);
    strcpy(mes,lineaLog[1]);
    strcpy(hora,lineaLog[3]);
    anio = atoi(lineaLog[4]);
    strcpy(anios,lineaLog[4]);
    strcpy(usuario,lineaLog[7]);
    if(usuario[strlen(usuario)-1]==':'){
        usuario[strlen(usuario)-1]= '\0';
    }
    strcpy(estado,lineaLog[8]);
    strcpy(descripcion,lineaLog[9]);
    descripcion[strlen(descripcion)-1]= '\0';
    strcpy(ip,lineaLog[11]);
    ip[strlen(ip)-1] = '\0';
    strcpy(rutaFile,lineaLog[12]);
    rutaFile[strlen(rutaFile)-1]= '\0';
    peso = atoi(lineaLog[13]);
    strcpy(velocidad,lineaLog[15]);
    velocidad[strlen(velocidad)-1] = '\0';
    diaN = atoi(lineaLog[2]);
    strcat(anios,"-");
    strcat(anios,"05");
    strcat(anios,"-");
    strcat(anios,lineaLog[2]);
    strcat(anios," ");
    strcat(anios,lineaLog[3]);

    //printf("Prueba usuario : %c",usuario[strlen(usuario)-1]);

    contador = 0;
    //char *sql = sqlConsulta;
    sprintf(sqlConsulta,"INSERT INTO Registro VALUES ('%s', '%s', '%s', '%s', '%s', %d, '%s');",anios,usuario,estado,descripcion,rutaFile,peso,velocidad);
    printf("Prueba consulta: %s",sqlConsulta);

}
