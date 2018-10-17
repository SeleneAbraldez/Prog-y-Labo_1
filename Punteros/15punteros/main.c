#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, *b, *c, x, vec[5], *ptr, i;

    a = 15;
    x = a; //copia
    b = &a;
    c = b;

    printf("a: %d\nb: %d\nc: %d\nx: %d\n", a, *b, *c, x);

    *b = 13;

    printf("\n");

    printf("a: %d\nb: %d\nc: %d\nx: %d\n", a, *b, *c, x);

    ptr = vec; // ptr = &vec[0];

    printf("\n");

// puntero

    for(i=0; i<5; i++){
        *(ptr+i) = (i+5);
    }

    for(i=0; i<5; i++){
        printf("%d ", *(ptr+i));
    }

    printf("\n\n");

// vector como punt

    for(i=0; i<5; i++){
        *(vec+i) = (i+5);
    }

    for(i=0; i<5; i++){
        printf("%d ", *(vec+i));
    }

    printf("\n\n");

// vector

    for(i=0; i<5; i++){
        vec[i] = (i+5);
    }

    for(i=0; i<5; i++){
        printf("%d ", vec[i]);
    }

    printf("\n\n");

// puntero como vect

    for(i=0; i<5; i++){
        ptr[i] = (i+5);
    }

    for(i=0; i<5; i++){
        printf("%d ", ptr[i]);
    }

    printf("\n");
    return 0;
}
