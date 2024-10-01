#include <stdio.h>
#include <stdlib.h>
#define size 10

int arr[size];
int rear = 0, front = 0;

void enqueue(int num){
    if(rear==size){
        printf("\nQueue full");
        printf("\n\n");
    }
    else{
        arr[rear++] = num;
        printf("\nElement entered successfully");
        printf("\n\n");
    }
}

void dequeue(){
    if(front==rear){
        printf("\nQueue empty");
        front = 0;
        rear = 0;
        printf("\n\n");
    }
    else{
        printf("\nElement deleted successfully");
        front++;
        printf("\n\n");
    }
}

void disp(){
    if(front==rear){
        printf("\nQueue is empty");
        return;
    }
    for(int i=front;i<rear;i++){
        printf("%d ", arr[i]);
    }    
}

void dispFront(){    
    if(front==rear){
        printf("\nQueue is empty");
        return;
    }
    printf("\nFront element:\n");
    printf("%d", arr[front]);      
}

void dispRear(){
    if(rear==0){
        printf("\nQueue is empty");
        return;
    }
    printf("\nRear element:\n");
    printf("%d", arr[rear-1]);
}

int main(){
    int flag = 1;
    while(flag==1){
        printf("Enter choice:");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Display front");
        printf("\n5. Display rear");
        printf("\n6. Exit\n");
        int choice, num, pos;
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("\nEnter element to enqueue: ");                    
                    scanf("%d", &num);
                    enqueue(num);                                                          
                    break;
            case 2: dequeue();
                    break;
            case 3: disp();
                    printf("\n\n");
                    break;
            case 4: dispFront();
                    printf("\n\n");
                    break;
            case 5: dispRear();
                    printf("\n\n");
                    break;
            case 6: printf("\nGoodbye");
                    flag = 0;
                    break;
            default: printf("\nEnter valid choice\n\n");
                     break;
        }
    }
}