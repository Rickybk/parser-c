#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int TAMANO_MAX_LINE  = 300;
    const int TAMANO_MAX_ARRAY = 5000;
    int contador = 0;
    int i;
    //Definimos el arreglo donde se guardara todo el Log.
    char arregloLog[TAMANO_MAX_ARRAY][TAMANO_MAX_LINE];
    FILE *fileLog =fopen("vsftpd.log", "r");
    if(fileLog == NULL){
        perror("No se pudo abrir el archivo");
        exit(1);
    }
    //Aca es donde guardamos momentaneamente las lineas del Log.
    char line[TAMANO_MAX_LINE];
    while(fgets(line,sizeof(line),fileLog)){
        strcpy(arregloLog[contador],line);
        contador++;
        //print the line
        printf("%s", line);
    }
    printf("El tamano final de nuestro arreglo es: %d",sizeof(arregloLog));
    /*printf("Aca empezamos a mostrar el arreglo que guardamos");
    for(i = 0; i< sizeof(arregloLog); i++){
        if(i%2 == 0){
            printf("%s",arregloLog[i]);
        }
    }*/
    return 0;
}
