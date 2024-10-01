#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct Node** poly, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        if (poly->next != NULL && poly->next->coeff >= 0)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            appendNode(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            appendNode(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) {
                appendNode(&result, sumCoeff, poly1->pow);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        appendNode(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        appendNode(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

void multiplyPolynomials(struct Node* poly1, struct Node* poly2, struct Node** result) {
    struct Node* ptr1 = poly1;
    struct Node* ptr2 = poly2;
    
    while (ptr1 != NULL) {
        ptr2 = poly2;
        while (ptr2 != NULL) {
            int coeff = ptr1->coeff * ptr2->coeff;
            int pow = ptr1->pow + ptr2->pow;
            struct Node* temp = *result;
            struct Node* prev = NULL;
            while (temp != NULL && temp->pow > pow) {
                prev = temp;
                temp = temp->next;
            }

            if (temp != NULL && temp->pow == pow) {
                temp->coeff += coeff;
            } else {
                struct Node* newNode = createNode(coeff, pow);
                if (prev == NULL) {
                    newNode->next = *result;
                    *result = newNode;
                } else {
                    newNode->next = prev->next;
                    prev->next = newNode;
                }
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

int main() {
    int flag = 1;
    while(flag==1){
        struct Node* poly1 = NULL;
        struct Node* poly2 = NULL;
        struct Node* result = NULL;
        printf("Enter choice:\n");
        printf("1. Polynomial addition\n");
        printf("2. Polynomial multiplication\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1: 
            case 2: printf("\nEnter polynomial 1, coeff and power respectively, enter 0 when you want to stop\n");
                    int coeff, pow;                    
                    while(1){
                        scanf("%d",&coeff);
                        if(coeff==0) break;
                        scanf("%d",&pow);
                        appendNode(&poly1, coeff, pow);
                        
                    }
                    printf("\nEnter polynomial 2, coeff and power respectively, enter 0 when you want to stop\n");
                    while(1){
                        scanf("%d",&coeff);
                        if(coeff==0) break;
                        scanf("%d",&pow);
                        appendNode(&poly2, coeff, pow);
                        
                    }
                    if(choice==1){
                        result = addPolynomials(poly1, poly2);
                        printf("\nSum: ");
                    }
                    else{
                        multiplyPolynomials(poly1, poly2, &result);
                        printf("\nProduct: ");
                    }
                    display(result);
                    break;
            case 3: flag = 0;
                    printf("\nGoodbye!!");
                    break;
            default: printf("\nEnter valid choice!!\n\n");
        }
    }
}
