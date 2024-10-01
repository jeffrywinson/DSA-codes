#include <stdio.h>
#include <stdlib.h>
#define size 10

int top = 0;
int arr[size];

void push(int num){
    if(top==size){
        printf("\nStack overflow");
        printf("\n\n");        
    }
    else{
        arr[top++] = num;
        printf("Element pushed successfully");
        printf("\n\n"); 
    }
}

void pop(){
    if(top==0){
        printf("\nStack underflow");
        printf("\n\n"); 
    }
    else{
        printf("Element deleted successfully");
        printf("\n\n"); 
        top--;
    }
}

void peek(){
    if(top==0){
        printf("\nStack underflow");
        printf("\n\n"); 
    }
    else
        printf("\nTop element %d", arr[top-1]);
}

void disp(){
    if(top==0){
        printf("\nStack is empty");
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
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit\n");
        int choice, num, pos;
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("\nEnter element to push: ");                    
                    scanf("%d", &num);
                    push(num);                                       
                    break;
            case 2: pop();
                    break;
            case 3: peek();
                    printf("\n\n");
                    break;
            case 4: printf("\nStack elements:\n");
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