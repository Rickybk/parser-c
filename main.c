#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file =fopen("vsftpd.log", "r");
    if(file == NULL){
        perror("No se pudo abrir el archivo");
        exit(1);
    }
    char line[100];
    while(fgets(line,sizeof(line),file)){
        //print the line
        printf("%s", line);
    }
    return 0;
}
