#include <stdio.h>
#include <stdlib.h>
#define size 10

int arr[size];
int rear = -1, front = -1;

void enqueue(int num){
    if((rear+1)%size==front){
        printf("\nQueue full");
        printf("\n\n");
        return;
    }
    if(front==-1)
        front = rear = 0;
    else    
        rear = (rear+1)%size;
    arr[rear] = num;
    printf("\nElement entered successfully");
    printf("\n\n");    
}

void dequeue(){
    if(front==-1){
        printf("\nQueue empty");
        printf("\n\n");
        return;
    }
    else if(front==rear){
        front = rear = -1;
    }    
    else{
        front = (front+1)%size;
    }
    printf("\nElement deleted successfully");
    printf("\n\n");
}

void disp(){
    if(front==-1){
        printf("\nQueue is empty");
        return;
    }
    int i = front;
    while(1){
        printf("%d ",arr[i]);
        if(i==rear)
            break;
        i = (i+1)%size;
    }  
}

void dispFront(){    
    if(front==-1){
        printf("\nQueue is empty");
        return;
    }
    printf("\nFront element:\n");
    printf("%d", arr[front]);      
}

void dispRear(){
    if(rear==-1){
        printf("\nQueue is empty");
        return;
    }
    printf("\nRear element:\n");
    printf("%d", arr[rear]);
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