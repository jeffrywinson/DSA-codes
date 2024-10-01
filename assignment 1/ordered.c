#include <stdio.h>
#include <stdlib.h>
#define size 10

int top = 0;
int arr[size];

void insert(int n){    
    int pos = top;
    for(int i=0;i<top;i++){
        if(arr[i]>n){
            pos = i;
            break;
        }
    }
    for(int i=top;i>pos;i--)
        arr[i] = arr[i-1];
    arr[pos] = n;
    printf("\nElement entered successfully");
    top++;    
}

void del(int n){
    
    int res = binSearch(0, top, n);
    if(res==-1)
        printf("\nElement not found");
    else{
        for(int i=res;i<top;i++)
            arr[i]=arr[i+1];
        printf("\nElement successfully deleted");
        top--;
    } 
}

int binSearch(int ll, int ul, int key){
    int mid = (ll + ul) / 2;
    while(ll<=ul && arr[mid]!=key){
        if(arr[mid]>key)
            ul = mid-1;
        else
            ll = mid+1;
        mid = (ll + ul) / 2;            
    }
    if(arr[mid]==key)
        return mid;
    else    
        return -1;
}

void disp(){
    if(top==0){
        printf("\nList is empty");
        return;
    }
    for(int i=0;i<top;i++){
        printf("%d ", arr[i]);
    }    
}

int main(){
    int flag = 1;
    while(flag==1){
        printf("Enter choice:");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Display");
        printf("\n5. Exit\n");
        int choice, num, pos;
        scanf("%d", &choice);
        switch(choice){
            case 1: if(top==size){
                        printf("\nList is full");
                        printf("\n\n");
                        continue;
                    }       
                    printf("\nEnter element to insert: ");                    
                    scanf("%d", &num);
                    insert(num);
                    printf("\n\n");                    
                    break;
            case 2: if(top==0){
                        printf("\nList is empty");
                        printf("\n\n");
                        continue;
                    }
                    printf("Enter element to delete: ");
                    scanf("%d", &num);
                    del(num);         
                    printf("\n\n");
                    break;
            case 3: printf("\nEnter element to search: ");
                    scanf("%d", &num);
                    int res = binSearch(0, top, num);
                    if(res==-1)
                        printf("\nElement not found");
                    else    
                        printf("\nElement found at position %d", res+1);
                    printf("\n\n");
                    break;
            case 4: printf("\nList elements:\n");
                    disp();
                    printf("\n\n");
                    break;
            case 5: printf("\nGoodbye");
                    flag = 0;
                    break;
            default: printf("\nEnter valid choice\n\n");
                     break;
        }
    }
}