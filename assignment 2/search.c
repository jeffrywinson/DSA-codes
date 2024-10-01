#include <stdio.h>
#include <stdlib.h>

int linSearch(int key, int arr[], int size){
    for(int i=0;i<size;i++){
        if(key==arr[i])
            return i;
    }
    return -1;
}

int binSearch(int ll, int ul, int key, int arr[], int size){
    int mid = (ll+ul)/2;
    while(ll<=ul){
        if(arr[mid]==key)
            return mid;
        else if(key<arr[mid])
            ul = mid-1;
        else
            ll = mid+1;
        mid = (ll+ul)/2;
    }
    return -1;
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
    int flag = 1;
    while(flag==1){
        printf("\n\nEnter choice");
        printf("\n1. Linear search");
        printf("\n2. Binary search");
        printf("\n3. Exit\n");
        int choice, num, ind;
        scanf("%d",&choice);    
        switch(choice){
            case 1: printf("\n\nEnter the number you want to search for\n");                
                    scanf("%d",&num);
                    ind = linSearch(num, arr, n);
                    if(ind!=-1)
                        printf("\n\nElement found at index %d", ind);
                    else    
                        printf("\n\nElement not found");
                    break;
            case 2: printf("\n\nEnter the number you want to search for\n");
                    scanf("%d",&num);
                    bubSort(arr, n);
                    printf("\n\nArray after sorting: \n");
                    for(int i=0;i<n;i++)
                        printf("%d ",arr[i]);
                    ind = binSearch(0,n-1,num,arr,n);
                    if(ind!=-1)
                        printf("\n\nElement found at index %d", ind);
                    else    
                        printf("\n\nElement not found");
                    break;
            case 3: flag = 0;
                    break;
            default: printf("\n\nEnter valid choice!"); 
        }        
    }
}