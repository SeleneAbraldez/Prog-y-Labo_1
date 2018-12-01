#include <stdio.h>
#include <stdlib.h>
#include "Person.h"

int main(){
    Person* personArray[50];
    int i;
    for(i = 0; i < 10; i++){
        personArray[i] = person_new(i,i);
    }
    for(i = 0; i < 10; i++){
        person_setAge(personArray[i],i-4);
    }
    for(i = 0; i < 10; i++){
        printf("\nAge: %2d",person_getAge(personArray[i]));
    }
    printf("\n\n");
    system("pause");
    return 0;
}

