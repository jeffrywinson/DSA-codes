#include <stdio.h>
#include <stdlib.h>

void selSort(int arr[], int size){
    int min, tmp;
    for(int i=0;i<size-1;i++){
        min = i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min])
                min = j;            
        }
        tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
}

void inSort(int arr[], int size) {
    int key, j;
    for (int i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void bubSort(int arr[], int size){
    int tmp;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

int main(){
    printf("Enter size of array\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter array elements\n");
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    printf("\n\nEnter choice");
    printf("\n1. Selection sort");
    printf("\n2. Insertion sort");
    printf("\n3. Bubble sort\n");
    int choice, num, ind;
    scanf("%d",&choice);
    switch(choice){
        case 1: selSort(arr, n);
                printf("\n\nArray after sorting: \n");
                for(int i=0;i<n;i++)
                    printf("%d ",arr[i]);
                break;
        case 2: inSort(arr, n);
                printf("\n\nArray after sorting: \n");
                for(int i=0;i<n;i++)
                    printf("%d ",arr[i]);
                break;        
        case 3: bubSort(arr, n);
                printf("\n\nArray after sorting: \n");
                for(int i=0;i<n;i++)
                    printf("%d ",arr[i]);                
                break;
        default: printf("\n\nEnter valid choice!");         
    }
}