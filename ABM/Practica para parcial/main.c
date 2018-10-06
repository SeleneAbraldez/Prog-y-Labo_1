#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "peliculas.h"

#define CANTPEL 7 // 1000
#define CANTDIR 5 // 500

int main()
{
    char seguir = 's';

    ePeliculas peliculas[CANTPEL];
    eDirectorx directores[CANTDIR];

    int contPelis = 0;
    int contDires = 0;

    inicializarPeliculas(peliculas, CANTPEL);
    inicializarDirectores(directores, CANTPEL);

    do{
        switch(menu()){
        case 1:
            if(contDires==0){
                printf("No hay directores cargadxs, ingrese para cargar peliculas\n");
            }else {
                if(altaPelicula(peliculas, CANTPEL, directores, CANTDIR)==0){
                printf("Alta con exito. \n");
                contPelis++;
                }
            }
            break;
        case 2:
            if(contDires==0){
                printf("No hay directores cargadxs, ingrese para modificar peliculas\n");
            }else {
                if(modificarPelicula(peliculas, CANTPEL, directores, CANTDIR)==0){
                    printf("Modificacion con exito. \n");
                }
            }
            break;
        case 3:
            if(contDires==0){
                printf("No hay directores cargadxs\n");
            }else {
                if(bajaPelicula(peliculas, CANTPEL, directores, CANTDIR)==0){
                    printf("Eliminacion hecha con exito. \n");
                    contPelis--;
                }
            }
            break;
        case 4:
             if(altaDirectorx(directores, CANTPEL)==0){
                printf("Alta con exito. \n");
                contDires++;
            }
            break;
        case 5:
            if(contDires<1){
                printf("No hay directores cargadxs.\n");
            }else{
                if(bajaDirectorx(directores, CANTPEL)==0){
                    printf("Baja con exito. \n");
                    contDires--;
                }
            }
            break;
        case 6:
            if(contPelis == 0){
                printf("No hay peliculas cargadas.\n");
            }else{
                imprimirPeliculas(peliculas, CANTPEL, directores, CANTDIR);
            }
            if(contDires == 0){
                printf("No hay directores cargadxs.\n");
            }else{
                imprimirDirectores(directores, CANTDIR);
            }
            break;
        case 0:
            hardcodeoPeliculas(peliculas);
            contPelis = contPelis + 5;
            hardcodeoDirectores(directores);
            contDires = contDires + 3;
            break;
        case 10:
            seguir = 'n';
            break;
        }
        system("pause");
    }while(seguir == 's');
    return 0;
}
