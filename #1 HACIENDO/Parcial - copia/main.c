#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "peliculas.h"
#include "directores.h"

#define CANTPEL 5
#define CANTDIR 3

int main()
{
    char seguir = 's';

    ePeliculas peliculas[CANTPEL];
    eDirectorx directores[CANTDIR];

    int contPelis = 0;
    int contDires = 0;

    inicializarPeliculas(peliculas, CANTPEL);

    do{
        switch(menu()){
        case 1:
            if(altaPelicula(peliculas, CANTPEL)==0){
                printf("Alta con exito. \n");
                contPelis++;
            }
            break;
        case 2:
             if(modificarPelicula(peliculas, CANTPEL)==0){
                printf("Modificacion con exito. \n");
            }
            break;
        case 3:
             if(bajaPelicula(peliculas, CANTPEL)==0){
                printf("Eliminacion hecha con exito. \n");
                contPelis--;
             }
            break;
        case 4:
             if(altaDirectorx(directores, CANTPEL)==0){
                printf("Alta con exito. \n");
                contDires++;
            }
            break;
        case 5:
            if(bajaDirectorx(directores, CANTPEL)==0){
                printf("Baja con exito. \n");
                contDires--;
            }
            break;
        case 6:
            printf("listar");
            imprimirPeliculas(peliculas, CANTPEL);
            imprimirDirectores(directores, CANTDIR);
            break;
        case 0:
            hardcodeoPeliculas(peliculas);
            hardcodeoDirectores(directores);
            break;
        case 10:
            seguir = 'n';
            break;
        }
        system("pause");
    }while(seguir == 's');
    return 0;
}
