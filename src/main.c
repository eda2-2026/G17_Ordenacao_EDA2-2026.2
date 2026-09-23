#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.c"

void copy(int original[], int copia[], int size) {
    for(int i = 0; i < size; i++) {
        copia[i] = original[i];
    }
}

void printAR(int array[], int size)
{
    for(int i = 0; i<size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int size = 0;
    int opt = 0;
    const char *filename = "dados.txt";
    int *myarray = upload(filename, &size);
    if(myarray == NULL){
        return 1;
    }
    printf("Array original:\n");
    printAR(myarray, size);
    printf("Qual algoritmo voce quer utilizar para ordenacao?\n");
    printf("1 - Shell Sort\n2 - Insertion Sort\n3 - Selection Sort\n4 - Quick Sort\n5 - Bubblesort\n6 - Couting Sort\n7 - Bucket Sort\n8 - Radix Sort\n9 - Merge Sort\n10 - Heap Sort\n11 - Todos\n");
    scanf("%d", &opt);
    switch(opt){
        case 1:
            printf("Voce escolheu Shell Sort\n");
            shellsort(myarray, size);
            break;
        case 2:
            printf("Voce escolheu Insertion Sort\n");
            insertionsort(myarray, size);
            break;
        case 3:
            printf("Voce escolheu Selection Sort\n");
            selectionsort(myarray, size);
            break;
        case 4:
            printf("Voce escolheu Quick Sort\n");
            quicksort(myarray, 0, size-1);
            break;
        case 5:
            printf("Voce escolheu Bubble Sort\n");
            bubblesort(myarray, size);
            break;
        case 6:
            printf("Voce escolheu Counting Sort\n");
            countingsort(myarray, size);
            break;
        case 7:
            printf("Voce escolheu Bucket Sort\n");
            bucketsortTRANSLATE(myarray, size);
            break;
        case 8:
            printf("Voce escolheu Radix Sort\n");
            radixsort(myarray, size);
            break;
        case 9:
            printf("Voce escolheu Merge Sort\n");
            mergesort(myarray, 0, size-1);
            break;
        case 10:
            printf("Voce escolheu Heap Sort\n");
            heapsort(myarray, size);
            break;
        case 11:
            printf("Voce escolheu todos\n");
            int *temp = (int*)malloc(size * sizeof(int));
            copy(myarray, temp, size);
            printf("Shell Sort\n");
            shellsort(temp, size);
            copy(myarray, temp, size);
            printf("Insertion Sort\n");
            insertionsort(temp, size);
            copy(myarray, temp, size);
            printf("Selection Sort\n");
            selectionsort(temp, size); 
            copy(myarray, temp, size);
            printf("Quick Sort\n");
            quicksort(temp, 0, size-1);
            copy(myarray, temp, size);
            printf("Bubblesort Sort\n");
            bubblesort(temp, size);  
            copy(myarray, temp, size);
            printf("Counting Sort\n");
            countingsort(temp, size);
            copy(myarray, temp, size);
            printf("Bucket Sort\n");
            bucketsortTRANSLATE(temp, size);
            copy(myarray, temp, size);
            printf("Radix Sort\n");
            radixsort(temp, size);
            copy(myarray, temp, size);
            printf("Merge Sort\n");
            mergesort(temp, 0, size-1);
            copy(myarray, temp, size);
            printf("Heap Sort\n");
            heapsort(temp, size);
            printf("Array final ordenado por todos os metodos:\n");
            printAR(temp, size);
            free(temp);
            break;
        default:
            printf("Ops!\n");
            break;
    }
    if(opt >= 1 && opt <= 10){
        printf("Array final ordenado:\n");
        printAR(myarray, size);
    }
    free(myarray);
    return 0;
}