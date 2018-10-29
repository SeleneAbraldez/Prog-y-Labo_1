#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

typedef struct{
    int idM;
    char descripcion[20];
    int isEmpty;
}eMenu;

void inicializarMenu(eMenu* comis, int lenMen);

int lugarLibreMenu(eMenu* comis, int lenMen);

int encontrarMenuxID(eMenu* comis, int lenMen);

int imprimirComida(eMenu comis, int lenMen);

int imprimirMenu(eMenu comis, int lenMen);


int altaMenu(eMenu* comis, int lenMen);

int bajaMenu(eMenu* comis, int lenMen);

void hardcodeoMenu(eMenu* comis);







#endif // MENU_H_INCLUDED

