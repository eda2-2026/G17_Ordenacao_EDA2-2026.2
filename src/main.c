#include "algoritmos.c"
#include "raylib.h"
#define SCREEN_W 1200
#define SCREEN_H 800
#define REC_SPACE_Y 600

typedef enum {
        SHELL_BTN,
        INSERTION_BTN,
        SELECTION_BTN,
        BUBBLE_BTN,
        QUICK_BTN,
        BUCKET_BTN,
        RADIX_BTN,
        MERGE_BTN,
        HEAP_BTN,
        COUNTING_BTN
} SortButton;

/*
void RenderOrderedList(int index, Rectangle recs[1000], Color color)
{

        DrawRectangleV((Vector2){ recs[i].x, recs[i].y }, (Vector2){ recs[i].width, recs[i].height }, RAYWHITE);
}
*/

int GetButtonIndex(Rectangle rec[3][4])
{
        int i, j;
        int buttonId = 1; 
        for (i = 0; i < 3; i++)
        {
                for (j = 0; j < 4; j++)
                {
                        if (CheckCollisionPointRec(GetMousePosition(), rec[i][j]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                        {
                                return buttonId; 
                        }
                        buttonId++;
                }
        }
        return -1;
}

void runSort (int index, int array[1000])
{
        switch (index)
        {
                case 1:
                insertionsort(array, 1000); break;
                case 2:
                selectionsort(array, 1000); break;
                case 3:
                bubblesort(array, 1000); break;
                case 4:
                quicksort(array, 0, 999); break;
                case 5:
                bucketsortTRANSLATE(array, 1000); break;
                case 6:
                shellsort(array, 1000); break;
                case 7:
                heapsort(array, 1000); break;
                case 8:
                radixsort(array, 1000); break;
                case 9:
                mergesort(array, 0, 999); break;
                case 10:
                countingsort(array, 1000); break;
                default:
                printf("error");
        }
}

void DrawRecs(Rectangle recs[3][4], Color color)
{
        int i, j;
        for (i = 0; i < 3; i++)
        {
                for (j = 0; j < 4; j++)
                {
                        DrawRectangleRec(recs[i][j], color);
                }

        }
}

void DrawSortText(const char *text[3][4], Rectangle rec[3][4], int offX, int offY, int fontSize, Color color)
{
        int i, j;
        int posX, posY;
        for (i = 0; i < 3; i++)
        {
                for (j = 0; j < 4; j++)
                {
                        posX = rec[i][j].x + offX;
                        posY = rec[i][j].y + offY;
                        DrawText(text[i][j], posX, posY, fontSize, color); 
                }
        }
}

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

int *genVectorRep() 
{
        int i;
        int vetor[1000];
        int *vector = malloc(sizeof(vetor));
        for (i = 0; i < 1000; i++)
        {
                vector[i] = GetRandomValue(1, 1000);
        }

        return vector;
}

int *genVector() 
{
        int i;
        int rand;
        int temp;
        int vetor[1000];
        int *vector = malloc(sizeof(vetor));
        for (i = 1; i <= 1000; i++)
        {
                vector[i - 1] = i;
        }
        for (i = 0; i < 1000; i++)
        {
                rand = GetRandomValue(0, 999);
                temp = vector[i];
                vector[i] = vector[rand];
                vector[rand] = temp;
                
        }
        return vector;
}


void RenderStableArray(int array[1000], Color color)
{
        int i;
        float posX = 0;
        float recSpace = 1.2f;
        for (i = 0; i < 1000; i++) 
        {
                float height = array[i] / 2.0f;
                float posY = SCREEN_H - height;
                DrawRectangleV((Vector2){ posX, posY }, (Vector2){ recSpace, height }, color);
                posX += recSpace;
        }
}

void AtualizaEcraOrdenacao(int array[1000]) {
    if (WindowShouldClose()) {
        CloseWindow();
        exit(0); 
    }
    static int contador = 0;
    contador++;
    if (contador % 15 != 0) {
        return; 
    }
    BeginDrawing();
    ClearBackground(BLACK);
    RenderStableArray(array, RAYWHITE);
    EndDrawing();
}

int main()
{
        InitWindow(SCREEN_W, SCREEN_H, "Algoritmos de ordenaçao");

        int sortButtons[3][4] = {
        { SELECTION_BTN, INSERTION_BTN, BUBBLE_BTN, QUICK_BTN },
        { BUCKET_BTN, SHELL_BTN, HEAP_BTN, RADIX_BTN },
        { MERGE_BTN, COUNTING_BTN, 0, 0 }
        }; 

        Rectangle sortRecs[3][4] = {
        { { 40, 15, 250, 80 }, { 330, 15, 250, 80 }, { 620, 15, 250, 80 }, { 910, 15, 250, 80 } },
        { { 40, 110, 250, 80 }, { 330, 110, 250, 80 }, { 620, 110, 250, 80 }, { 910, 110, 250, 80 } },
        { { 40, 205, 250, 80 }, { 330, 205, 250, 80 }, { 0 }, { 0 } } 
        };

        const char *sortText[3][4] = {
        {"Selection","Insertion","Bubble","Quick"},
        {"Bucket","Shell","Heap","Radix"},
        {"Merge","Counting","",""}
        }; 

        int sortIndex = -1;
        
        int *array = genVector(); 
        SetTargetFPS(60);
        
        while (!WindowShouldClose())
        {
                sortIndex = GetButtonIndex(sortRecs);
                
                if (sortIndex >= 1 && sortIndex <= 10) 
                {
                        runSort(sortIndex, array);
                        BeginDrawing();
                        ClearBackground(BLACK);
                        DrawRecs(sortRecs, RAYWHITE);
                        DrawSortText(sortText, sortRecs, 20, 20, 40, BLACK);
                        RenderStableArray(array, RAYWHITE);
                        EndDrawing();
                        WaitTime(2.0); 
                        free(array);
                        array = genVector();
                }

                BeginDrawing();
                ClearBackground(BLACK);
                DrawRecs(sortRecs, RAYWHITE);
                DrawSortText(sortText, sortRecs, 20, 20, 40, BLACK);
                RenderStableArray(array, RAYWHITE);
                EndDrawing();
        }

        free(array);
        CloseWindow();

        return 0;
}
