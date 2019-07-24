#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

int menu(){
    int opcion;
    system("cls");
    printf("---Menu de Opciones---\n\n");
    printf("1- Alta juego\n");
    printf("2- Modificar juego\n");
    printf("3- Baja juego\n");
    printf("4- Listar juegos\n");

    printf("\n5- Alta cliente\n");
    printf("6- Modificar cliente\n");
    printf("7- Baja cliente\n");
    printf("8- Listar clientes\n");

    printf("\n9- Alta alquiler\n");

    printf("\n10- Promedio y total de juegos alquilados\n");
    printf("11- Cantidad de juegos cuyo importe NO supera el promedio\n");
    printf("12- Clientes x juego alquilado\n");
    printf("13- Juegos alquilado x cliente \n");
    printf("14- Juego/s menos alquilado/s\n");
    printf("15- Cliente/s que mas alquilan\n");
    printf("16- Juegos x fecha\n");
    printf("17- Clientes x fecha\n");
    printf("18- Juegos ordenados por Importe D (Bur)\n");
    printf("19- Clientes ordenados por Apellido A (Inser)\n");

    printf("\n0- Hardcodeo\n");
    printf("\n100- Salir\n\n");
    opcion = getValidInt("Ingrese opcion: ", "Opcion no valida", 0, 100);
    return opcion;
}


int getInt(char* mensaje){
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}
float getFloat(char* mensaje){
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}
char getChar(char* mensaje){
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

char getNumeroAleatorio(int desde , int hasta, int iniciar){
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

int esNumerico(char str[]){
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
int esSoloLetras(char str[]){
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}
int esAlfaNumerico(char str[]){
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}
int esNumericoFlotante(char str[]){
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
int esTelefono(char str[]){
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

int isSexCharacter(char caracter){
    int retorno = 0;
    if ((caracter == 'f') || (caracter == 'm'))
        retorno = 1;
    return retorno;
}

int isYesNoCharacter(char caracter){
    int retorno = 0;
    if ((caracter == 'y') || (caracter == 'n'))
        retorno = 1;
    return retorno;
}

void getString(char mensaje[],char input[]){
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}
int getStringLetras(char mensaje[],char input[]){
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        toCapsFirst(aux);
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int getStringNumeros(char mensaje[],char input[]){
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int getStringNumerosFlotantes(char mensaje[],char input[]){
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int getStringAlfaNumerico(char mensaje[], char input[]){
    char aux[256];
    getString(mensaje, aux);
    if(esAlfaNumerico(aux)){
        strcpy(input, aux);
        return 1;
    }
    return 0;
}


int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit){
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;

    }


}
float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit){
    char auxStr[256];
    float auxFloat;
    while(1)
    {
        if (!getStringNumerosFlotantes(requestMessage, auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxFloat = atof(auxStr);
        if(auxFloat < lowLimit || auxFloat > hiLimit)
        {
            printf ("El numero debe ser mayor o igual a %d y menor o igual a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxFloat;

    }


}
void getValidString(char requestMessage[],char errorMessage[], char input[]){

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }

}
int getValidSexChar(char mensaje[], char errorMensaje[]){
    char aux='f';
    do{
        if(isSexCharacter(aux)==0){
            aux = getChar(errorMensaje);
        }else{
            aux = getChar(mensaje);
        }
    }while (isSexCharacter(aux)==0);
    return aux;
}

int getValidYesNoChar(char mensaje[], char errorMensaje[]){
    char aux='n';
    do{
        if(isYesNoCharacter(aux)==0){
            aux = getChar(errorMensaje);
        }else{
            aux = getChar(mensaje);
        }
    }while (isYesNoCharacter(aux)==0);
    return aux;
}


int getValidStringAlfaNumericoLen(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght){
    int retorno = -1;
    char buffer[1024];
    while(1){
        if(!getStringAlfaNumerico(requestMessage, buffer)){
            printf("%s", errorMessage);
        }
        if(strlen(buffer)>= maxLenght){
            printf("%s", errorMessageLenght);
        }
        retorno = 0;
        strcpy(input, buffer);
        break;
    }
    return retorno;
}

void cleanStdin(void){
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void toCapsFirst(char cadena[]){
    int len = strlen(cadena);
    for (int i=0;i<len;i++){
         if (i==0 || isalpha(cadena[i]) && cadena[i-1] == ' '){
             cadena[i]= toupper(cadena[i]);
         }
    }
}




int getValidStringLen(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght){
    int retorno=-1;
    char buffer[1024];

    while(1){
        if (!getStringLetras(requestMessage,buffer))
        {
            printf ("%s",errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxLenght)
        {
            printf ("%s",errorMessageLenght);
            continue;
        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}


int getValidStringNumberLen(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght){
    int retorno=-1;
    char buffer[1024];

    while(1){
            if (!getStringNumeros(requestMessage,buffer))
        {
            printf ("%s",errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxLenght)
        {
            printf ("%s",errorMessageLenght);
            continue;
        }
        strcpy(input,buffer);
        break;
        retorno=0;
    }
    return retorno;
}


int getValidStringLenAtte(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps){
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<attemps;i++)
    {
        if (!getStringLetras(requestMessage,buffer))
        {
            printf ("%s",errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxLenght)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}


