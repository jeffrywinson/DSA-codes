#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge_sort(int arr[],int p, int r){
    if(p<r){
        int q=(p+r)/2;
        merge_sort(arr,p,q);
        merge_sort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}

void merge(int arr[], int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1];
    int R[n2+1];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    for(int i=0;i<n1;i++){
        L[i] = arr[p+i];
    }
    for(int i=0;i<n2;i++){
        R[i] = arr[q+1+i];
    }
    int i=0, j=0;
    for(int k=p;k<=r;k++){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
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
    merge_sort(arr, 0, size-1);
    printf("\n\nThe sorted array is: \n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}