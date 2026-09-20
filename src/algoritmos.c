#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

int* upload(const *char filename, int *size)
{
    FILE *file = fopen(filename, "r");
    if(file == NULL){
        *size = 0;
        printf("Erro ao ler o arquivo!\size");
        return NULL
    }
    int cap = 0;
    int amount = 0;
    int *array = (int*)malloc(cap*sizeof(int));
    if(array == NULL){
        return NULL;
    }
    int temp;
    while(fscanf(file, %d, &temp) == 1){
        if(amount >= cap){
            cap *= 2;
            int* temparray = (int*)realloc(array, cap*sizeof(int));
            if(temparray == NULL){
                free(array);
                fclose(file);
                return NULL;
            }
            array = temparray;
        }
        array[amout] = temp;
        amount++;
    }
    fclose(file);
    *sizeout = amount;
    return (int*)realloc(array, amount*sizeof(int));
}


void shellsort(array[], int size)
{
    for(int gap = size / 2; gap > 0; gap /= 2){
        for(int i = gap; i<size; i++){
            int temp = array[i];
            int j;
            for(j = i; j>=gap && array[j - gap] > temp; j-= gap){
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

void insertionsort(array[], int size)
{
    for(int i = 1; i<size; i++){
        int key = array[i];
        int j = i-1;
        while(j>=0 && array[j]>key){
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = key;
    }
}

void selectionsort(array[], int size)
{
    for(int i = 0; i<(size-1); i++){
        int min_idx = i;
        for(int j = i+1; j<size; j++){
            if (array[j] < array[min_idx]){
                min_idx = j;
            }
        }
        int temp = array[i];
        array[i] = array[min_idx];
        array[min_idx] = temp;
    }
}

void swapping(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubblesort(array[], int size)
{
    int i, j;
    bool swap;
    for(i = 0; i<(size-1); i++){
        swap = false;
        for(j = 0; j<(size-i-1); j++){
            if(array[j] > array[j + 1]){
                swapping(&array[j], &array[j+1]);
                swap = true;
            }
        }
        if(swap == false)
            break;
    }
}

int partition(int array[], int low, int high){
    int pivot = array[high];
    int i = low-1;
    for(int j = low; j <=(high-1); j++){
        if (array[j] < pivot) {
            i++;
            swapping(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[high]);  
    return i+1;
}

void quicksort(int array[], int low, int high) {
    if(low < high){
        int pi = partition(array, low, high);
        quickSort(array, low, (pi-1));
        quickSort(array, (pi+1), high);
    }
}

void countingsort(int array[], int size) 
{
    int valuemax = 0;
    for (int i = 0; i < size; i++){
        if (array[i] > valuemax){
            valuemax = array[i];
        }
    }
    int* now = (int*)calloc(valuemax+1, sizeof(int));
    for(int i = 0; i < size; i++){
        now[array[i]]++;
    }
    for(int i = 1; i <= valuemax; i++){
        now[i] += now[i-1];
    }
    int* ans = (int*)malloc(size * sizeof(int));
    for(int i = (size-1); i >= 0; i--){
        ans[now[array[i]]-1] = array[i];
        now[array[i]]--;
    }
    for(int i = 0; i < size; i++){
        array[i] = ans[i];
    }
    free(now);
    free(ans);
}

void insert(Bucket** head, Bucket* now) 
{
    if(*head == NULL || (*head)->valor >= now->valor){
        now->prox = *head;
        *head = now;
    }else{
        Bucket* charger = *head;
        while(charger->prox != NULL && charger->prox->valor < now->valor){
            charger = charger->prox;
        }
        now->prox = charger->prox;
        charger->prox = now;
    }
}

void bucketSortListaDinamica(Bucket** head) 
{
    if(*head == NULL || (*head)->prox == NULL) return;
    int high = (*head)->valor;
    int amount = 0;
    Bucket* temp = *head;
    while(temp != NULL){
        if(temp->valor > high){
            high = temp->valor;
        }
        amount++;
        temp = temp->prox;
    }
    int bucketnum = amount; 
    Bucket** buckets = (Bucket**)calloc(bucketnum, sizeof(Bucket*));
    Bucket* now = *head;
    Bucket* next;

    while(now != NULL){
        next = now->prox; 
        int indice_balde = (now->valor * bucketnum) / (high+1);
        inserirNoOrdenado(&buckets[indice_balde], now);
        now = next;
    }
    Bucket* newhead = NULL;
    Bucket* last = NULL;
    for(int i = 0; i < bucketnum; i++){
        if(buckets[i] != NULL){
            if (newhead == NULL){
                newhead = buckets[i];
                last = newhead;
            }else{
                last->prox = buckets[i];
            }
            while(last->prox != NULL){
                last = last->prox;
            }
        }
    }
    free(buckets); 
    *head = newhead; 
}

int getMax(int array[], int size) 
{
    int mx = array[0];
    for(int i = 1; i < size; i++)
        if(array[i] > mx)
            mx = array[i];
    return mx;
}

void radixsort(int array[], int size) {
    int m = getMax(array, size); 
    for(int exp = 1; m / exp > 0; exp *= 10){
        countingsort(array, size, exp);
    }
}

void merge(int array[], int l, int m, int r)
{    
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    for(i = 0; i < n1; i++){
        L[i] = array[l+i];
    }
    for(j = 0; j < n2; j++){
        R[j] = array[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2){
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }else{
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        array[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int array[], int l, int r)
{    
    if(l < r){
        int m = l + (r-l)/2;
        mergesort(array, l, m);
        mergesort(array, m + 1, r);
        merge(array, l, m, r);
    }
}

void heapify(int array[], int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest]){
        largest = l;
    }
    if (r < size && array[r] > array[largest]){
        largest = r;
    }
    if (largest != i){
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        heapify(array, size, largest);
    }
}

void heapsort(int array[], int size){
    for(int i = size/2 - 1; i >= 0; i--){
        heapify(array, size, i);
    }
    for(int i = size-1; i > 0; i--){
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(array, i, 0);
    }
}