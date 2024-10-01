#include <stdio.h>
#include <stdlib.h>
#define size 10

int arr[size];
int rear = -1, front = -1;

void enqueueFront(int num) {
    if((rear + 1) % size == front) {
        printf("\nQueue full\n\n");
        return;
    }
    if(front == -1) {
        front = rear = 0;
    } else if(front == 0) {
        front = size - 1;
    } else {
        front--;
    }
    arr[front] = num;
    printf("\nElement entered successfully\n\n");
}

void enqueueRear(int num) {
    if((rear + 1) % size == front) {
        printf("\nQueue full\n\n");
        return;
    }
    if(front == -1) {
        front = rear = 0;
    } else if(rear == size - 1) {
        rear = 0;
    } else {
        rear++;
    }
    arr[rear] = num;
    printf("\nElement entered successfully\n\n");
}

void dequeueFront() {
    if(front == -1) {
        printf("\nQueue empty\n\n");
        return;
    }
    printf("\nElement deleted successfully: %d\n\n", arr[front]);
    if(front == rear) {
        front = rear = -1;
    } else if(front == size - 1) {
        front = 0;
    } else {
        front++;
    }
}

void dequeueRear() {
    if(front == -1) {
        printf("\nQueue empty\n\n");
        return;
    }
    printf("\nElement deleted successfully: %d\n\n", arr[rear]);
    if(front == rear) {
        front = rear = -1;
    } else if(rear == 0) {
        rear = size - 1;
    } else {
        rear--;
    }
}

void disp() {
    if(front == -1) {
        printf("\nQueue is empty\n");
        return;
    }
    int i = front;
    printf("Queue elements: ");
    while(1) {
        printf("%d ", arr[i]);
        if(i == rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n\n");
}

void dispFront() {    
    if(front == -1) {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nFront element: %d\n\n", arr[front]);      
}

void dispRear() {
    if(rear == -1) {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nRear element: %d\n\n", arr[rear]);
}

int main() {
    int flag = 1;
    while(flag == 1) {
        printf("Enter choice:");
        printf("\n1. Enqueue front");
        printf("\n2. Enqueue rear");
        printf("\n3. Dequeue front");
        printf("\n4. Dequeue rear");
        printf("\n5. Display");
        printf("\n6. Display front");
        printf("\n7. Display rear");
        printf("\n8. Exit\n"); 
        int choice, num;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter element to enqueue: ");
                scanf("%d", &num);
                enqueueFront(num);                                                          
                break;
            case 2:
                printf("\nEnter element to enqueue: ");
                scanf("%d", &num);
                enqueueRear(num);                                                          
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                disp();
                break;
            case 6:
                dispFront();
                break;
            case 7:
                dispRear();
                break;
            case 8:
                printf("\nGoodbye\n");
                flag = 0;
                break;
            default:
                printf("\nEnter valid choice\n\n");
                break;
        }
    }
    return 0;
}
