#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int numero;
    char letra;
    float real;
    char palabra[51];
}eDato;

int main()
{
    printf("Dato tipo void: %d\n", sizeof(void));
    printf("Dato tipo char: %d\n", sizeof(char));
    printf("Dato tipo int: %d\n", sizeof(int));
    printf("Dato tipo float: %d\n", sizeof(float));
    printf("Dato tipo double: %d\n", sizeof(double));
    printf("Dato tipo eDato: %d\n", sizeof(eDato));

    return 0;
}
