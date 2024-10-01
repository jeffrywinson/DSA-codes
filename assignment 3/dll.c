#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * prev;
    struct node *next;
}*list = 0;

void beginInsert(int val) {
    struct node *nnode = (struct node*)malloc(sizeof(struct node));
    nnode->data = val;
    nnode->prev = 0;
    nnode->next = 0;
    
    if(list == 0) {
        list = nnode;
    } else {
        nnode->next = list;
        list->prev = nnode;
        list = nnode;
    }
}


void endInsert(int val) {
    struct node *nnode = (struct node*)malloc(sizeof(struct node)), *t;
    nnode->data = val;
    nnode->prev = 0;
    nnode->next = 0;
    
    if(list == 0) {
        list = nnode;
    } else {
        t = list;
        while(t->next != 0) {  
            t = t->next;
        }
        t->next = nnode;
        nnode->prev = t; 
    }
}


void posInsert(int pos, int val) {
    struct node *nnode = (struct node*)malloc(sizeof(struct node)), *t;
    nnode->data = val;
    nnode->prev = 0;
    nnode->next = 0;
    int ctr = 1;

    if(pos == 1) { 
        beginInsert(val);
        return;
    }

    t = list;
    while(ctr < pos - 1 && t->next != 0) { 
        ctr++;
        t = t->next;
    }
    
    if(t->next != 0) { 
        nnode->next = t->next;
        (t->next)->prev = nnode;
    }
    
    t->next = nnode;
    nnode->prev = t;
}


void beginDelete() {
    struct node *temp;
    
    if(list == 0) { 
        printf("List is empty, no node to delete.\n");
        return;
    }
    
    temp = list;
    list = list->next; 
    
    if(list != 0) { 
        list->prev = 0;
    }
    
    free(temp); 
}

void endDelete() {
    struct node *t, *temp;
    
    if(list == 0) { 
        printf("List is empty, no node to delete.\n");
        return;
    }
    
    if(list->next == 0) {  
        free(list);
        list = 0;
        return;
    }
    
    t = list;
    
    while(t->next != 0) {
        t = t->next;
    }
    
    temp = t;
    (t->prev)->next = 0; 
    free(temp); 
}

void posDelete(int pos) {
    struct node *t, *temp;
    int ctr = 1;
    
    if(list == 0) { 
        printf("List is empty, no node to delete.\n");
        return;
    }
    
    if(pos == 1) { 
        beginDelete();
        return;
    }
    
    t = list;
    
    while(ctr < pos && t->next != 0) {
        ctr++;
        t = t->next;
    }
    
    if(ctr != pos) { 
        printf("Invalid position.\n");
        return;
    }
    
    temp = t;
    
    if(t->next != 0) { 
        (t->next)->prev = t->prev;
    }
    
    (t->prev)->next = t->next; 
    
    free(temp); 
}

void search(int val) {
    struct node *t = list;
    int pos = 1;  

    if(list == 0) { 
        printf("List is empty, cannot search for elements.\n");
        return;
    }

    while(t != 0) {
        if(t->data == val) {
            printf("Element %d found at position %d.\n", val, pos);
            return;
        }
        t = t->next;
        pos++;
    }

    printf("Element %d not found in the list.\n", val);
}

void display() {
    struct node *t = list;

    if(list == 0) { 
        printf("List is empty.\n");
        return;
    }

    printf("Elements in the list: ");
    
    while(t != 0) {
        printf("%d ", t->data); 
        t = t->next;
    }
    
    printf("\n"); 
}


int main(){
    int flag = 1;
    while(flag==1){
        printf("Enter choice: ");
        printf("\n1. Beginning insertion");
        printf("\n2. End insertion");
        printf("\n3. Position insertion");
        printf("\n4. Beginning deletion");
        printf("\n5. End deletion");
        printf("\n6. Position deletion");
        printf("\n7. Display");
        printf("\n8. Search");
        printf("\n9. Exit\n");
        int num, pos, choice;
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("\nEnter element to insert\n");
                    scanf("%d",&num);
                    beginInsert(num);
                    printf("\nElement entered successfully\n\n");
                    break;
            case 2: printf("\nEnter element to insert\n");
                    scanf("%d",&num);
                    endInsert(num);
                    printf("\nElement entered successfully\n\n");
                    break;
            case 3: printf("\nEnter element to insert\n");
                    scanf("%d",&num);
                    printf("\nEneter position to insert in\n");
                    scanf("%d",&pos);
                    posInsert(pos,num);
                    break;
            case 4: beginDelete();
                    break;
            case 5: endDelete();
                    break;
            case 6: printf("\nEnter position to delete\n");
                    scanf("%d",&pos);
                    posDelete(pos);
                    break;
            case 7: display();
                    break;
            case 8: printf("\nEnter number to search for\n");
                    scanf("%d",&num);
                    search(num);
                    break;
            case 9: printf("\nGoodbye!!");
                    flag = 0;
                    break;
            default: printf("\nEnter valid choice!!\n\n");
        }
    }
}