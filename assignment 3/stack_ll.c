#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*list = 0;

void push(int val){
    struct node *nnode;
    nnode = (struct node*)malloc(sizeof(struct node));
    nnode->data = val;
    nnode->next = 0;
    if(list==0)
        list = nnode;
    else
        nnode->next = list;
        list = nnode;
}

void pop(){
    if(list==0){
        printf("\nList is empty\n\n");
        return;
    }
    if(list->next==0){
        printf("\nElement deleted: %d\n\n",list->data);
        free(list);
        list = 0;
        return;
    }
    struct node *t = list;
    printf("\nElement deleted: %d\n\n",list->data);
    list = list->next;
    free(t);
}

void display(){
    if(list==0){
        printf("\nStack is empty\n\n");
        return;
    }
    struct node *t = list;
    printf("\nStack elements: \n");
    while(t!=0){
        printf("%d ",t->data);
        t = t->next;
    }
    printf("\n\n");
}

int main(){
    int flag = 1;
    while(flag==1){
        printf("Enter choice: ");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit\n");
        int num, pos, choice;
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("\nEnter element to insert\n");
                    scanf("%d",&num);
                    push(num);
                    printf("\nElement pushed successfully\n\n");
                    break;            
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: printf("\nGoodbye!!");
                    flag = 0;
                    break;
            default: printf("\nEnter valid choice!!\n\n");
        }
    }
}