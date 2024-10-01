#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*list = 0;

void beginInsert(int val){
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

void endInsert(int val){
    struct node *nnode;
    nnode = (struct node*)malloc(sizeof(struct node));
    nnode->data = val;
    nnode->next = 0;
    if(list==0)
        list = nnode;
    else{
        struct node *t = list;
        while(t->next!=0)
            t = t->next;
        t->next = nnode;
    }
}

void posInsert(int pos, int val){
    struct node *nnode, *t;
    nnode = (struct node*)malloc(sizeof(struct node));
    nnode->data = val;
    nnode->next = 0;
    if(pos==1){
        nnode->next = list;
        list = nnode;
        return;
    }
    t = list;
    int ctr = 1;
    while(ctr<pos-1&&t->next!=0){
        ctr++;
        t = t->next;
    }
    if(ctr<pos-1||t==0){
        printf("\nPosition out of bounds\n\n");
        free(nnode);
        return;
    }
    nnode->next = t->next;
    t->next = nnode;
    printf("\nElement entered successfully\n\n");
}

void beginDelete(){
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

void endDelete(){
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
    while((t->next)->next!=0){
        t = t->next;
    }
    printf("\nElement deleted: %d\n\n",(t->next)->data);
    free(t->next);
    t->next = 0;
}

void posDelete(int pos){
    if(list==0){
        printf("\nList is empty\n\n");
        return;
    }
    if(pos==1){
        struct node *t = list;
        printf("\nElement deleted: %d\n\n",list->data);
        list = list->next;
        free(t);        
        return;
    }
    struct node *t = list;
    int ctr = 1;
    while(ctr<pos-1&&t->next!=0){
        ctr++;
        t = t->next;
    }
    if (t->next == 0 || ctr < pos - 1) {
        printf("\nPosition out of bounds\n\n");
        return;
    }
    struct node *temp = t->next;
    printf("\nElement deleted: %d\n\n",temp->data);
    t->next = temp->next;
    free(temp);
}

void display(){
    if(list==0){
        printf("\nList is empty\n\n");
        return;
    }
    struct node *t = list;
    printf("\nList elements: \n");
    while(t!=0){
        printf("%d ",t->data);
        t = t->next;
    }
    printf("\n\n");
}

void search(int num){
    if(list==0){
        printf("\nList is empty\n\n");
        return;
    }
    struct node *t = list;
    int ctr = 1, pos = 0;
    while(t!=0){
        ctr++;
        if(t->data==num){
            pos = ctr-1;
            break;
        }
        t = t->next;
    }
    if(pos==0){
        printf("\nElement not found\n\n");
        return;
    }
    printf("\nElement found at position %d\n\n",pos);
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