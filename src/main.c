#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.c"

int main(){
    int arraysize = 0;
    int *myarray = upload("dados.txt", &arraysize);
    if(myarray != NULL){
        printf("%d Dados carregados!\n", arraysize);
        free(myarray);
    }
    return 0;
}