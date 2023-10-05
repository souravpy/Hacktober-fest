#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include<math.h>

int arr1[]={5,10,3,2,18,12,9,7,16,19,1,4,11,14,6,15,8,10,13,17,20};
char ch;
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
// void gotoxy(int x,int y)
// {
//     COORD c;
//     c.X=x;
//     c.Y=y;
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
// }
void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
void tree_from_array(int arr[], int n)
{
    int index = 0, num = 100;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < num; j++){
            printf(" ");
        }
        if (index >= n){
            break;
        }
        for (int k = 0; k < pow(2,i); k++){
            if (index >= n)
                break;
            printf("%d",arr[index]);
            index++;
            for (int l = 0; l < 2*num; l++){
                printf(" ");
            }
        }
        printf("\n");
        //---------------
        for (int j = 0; j < num/2; j++){
            printf(" ");
        }
        if (index >= n){
            break;
        }
        for (int k = 0; k < pow(2,i+1); k++){
            if (index >= n)
                break;
            printf(" ");
            //index++;
            for (int l = 0; l < num; l++){
                if (k%2 == 0){
                    if (l == num/2)
                        printf("|");
                    else
                        printf("_");
                }
                else
                    printf(" ");
            }
        }
        //---------------
        printf("\n");
        //---------------
        for (int j = 0; j < num/2; j++){
            printf(" ");
        }
        if (index >= n){
            break;
        }
        for (int k = 0; k < pow(2,i+1); k++){
            if (index >= n)
                break;
            printf("|");
            //index++;
            for (int l = 0; l < num; l++){
                printf(" ");
            }
        }
        //---------------
        num /= 2;
        printf("\n");
    }
}





void swap(int* a, int* b)
{
 
    int temp = *a;
 
    *a = *b;
 
    *b = temp;
}
void heapify(int arr[], int N, int i)
{
    // Find largest among root, left child and right child
 
    // Initialize largest as root
    int largest = i;
    
 
    // left = 2*i + 1
    int left = 2 * i + 1;
 
    // right = 2*i + 2
    int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])
 
        largest = left;
 
    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest])
 
        largest = right;
 
    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {
 
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N)
{
 
    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--){
            tree_from_array(arr,N);
            delay(1);
            // system("cls");
            printf("|------------------------------------------------------------------------------------------------------------------------|");
            printf("\n\n");
            //goto label;
        heapify(arr, N, i);
    }
 
        
 
    // Heap sort
    for (int i = N - 1; i >= 0; i--) {
 
        swap(&arr[0], &arr[i]);
 
        // Heapify root element to get highest element at
        // root again
            tree_from_array(arr,N);
            delay(1);
             printf("|------------------------------------------------------------------------------------------------------------------------|");
             printf("\n\n");
           // goto label;
        heapify(arr, i, 0);
    }
}
void main(){
    SetColor(6);
    heapSort(arr1,20);
    tree_from_array(arr1,20);
}