#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int TAMANO_MAX_LINE  = 300;
    const int TAMANO_MAX_ARRAY = 5000;
    FILE *file =fopen("vsftpd.log", "r");
    if(file == NULL){
        perror("No se pudo abrir el archivo");
        exit(1);
    }
    char line[TAMANO_MAX_LINE];
    while(fgets(line,sizeof(line),file)){
        //print the line
        printf("%s", line);
    }
    return 0;
}
