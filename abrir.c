//Llamada a librerías
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 
//Función principal
main(int argc, char **argv[])
{
//Declaramos variables
int fd;
char c;
//ABRIR ARCHIVO
//O_RDONLY abre el archivo salida.txt en modo lectura
fd = open("salida3.txt",O_RDONLY);
 
//CONTROLAR SI EXISTE ARCHIVO
if(fd!=-1)
{
//LEER EL ARCHIVO
//El archivo se lee caracter por caracter
while(read(fd,&c,sizeof(c)!=0)){
printf("%c",c);
}
//CERRAR ARCHIVO
close(fd);
}
 
else{
printf("\nEl archivo no existe \n");
}
 
}
