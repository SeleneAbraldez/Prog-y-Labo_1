#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* vec;
    int* aux;

    vec = (int*) malloc(sizeof(int) * 5);

    if(vec == NULL){

        printf("No se consiguio memoria\n");
        exit(1);
    }

    for(int i=0; i<5; i++){


        printf("Ingrese un numero: ");
        scanf("%d", vec +i);
    }

    for(int i=0; i<5; i++){


        printf("%d ", *(vec + i));
    }

        printf("\n\n");



        aux = (int*)realloc(vec, sizeof(int)*10);

        if(aux == NULL){
            printf("No se pudo agrandar el array\n");
        }
        else{

            vec = aux;

            for(int i=5; i<10; i++){
                 printf("Ingrese un numero: ");
                scanf("%d", vec +i);

            }

        }

         for(int i=0; i<10; i++){


        printf("%d ", *(vec + i));
    }

        printf("\n\n");


    vec  = (int*) realloc(vec, sizeof(int)* 5);

  for(int i=0; i<10; i++){


        printf("%d ", *(vec + i));
    }

        printf("\n\n");


        free(vec);

    return 0;
}
