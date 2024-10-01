#include <stdio.h>
#include <stdlib.h>

void quick_sort(int arr[], int lb, int ub){
    if(lb<ub){
        int i = lb;
        int j = ub;
        int p = arr[i];
        int tmp;
        while(i<j){
            while (arr[i] <= p && i < ub) {
                i++;
            }
            while(arr[j]>p)
                j--;
            if(i<j){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        arr[lb] = arr[j];
        arr[j] = p;
        quick_sort(arr,lb,j-1);
        quick_sort(arr,j+1,ub);
    }
}

int main(){
    printf("Enter array size\n");
    int size;
    scanf("%d",&size);
    printf("Enter %d elements\n",size);
    int arr[size];
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    quick_sort(arr, 0, size-1);
    printf("\n\nThe sorted array is: \n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}