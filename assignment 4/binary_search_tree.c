#include <stdio.h>
#include <stdlib.h>

struct tree_node{
    int data;
    struct tree_node *left;
    struct tree_node *right;
}*root = 0;

void insert(int val){
    struct tree_node *nnode = (struct tree_node*)malloc(sizeof(struct tree_node));
    nnode->data = val;
    nnode->left = NULL;
    nnode->right = NULL;
    if(root==0){
        root = nnode;
    }
    else{
        struct tree_node *tmp = root;
        struct tree_node *parent = NULL;
        while(tmp!=NULL){
            parent = tmp;
            if(val<tmp->data){
                tmp = tmp->left;
            }
            else{
                tmp = tmp->right;
            }
        }
        if(val<parent->data)
            parent->left = nnode;
        else    
            parent->right = nnode;
    }
}

struct tree_node* getSuccessor(struct tree_node* curr) {
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

struct tree_node* delNode(struct tree_node* root, int x) {
  
    if (root == NULL)
        return root;

    if (root->data > x)
        root->left = delNode(root->left, x);
    else if (root->data < x)
        root->right = delNode(root->right, x);
    else {
        if (root->left == NULL) {
            struct tree_node* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            struct tree_node* temp = root->left;
            free(root);
            return temp;
        }
        struct tree_node* succ = getSuccessor(root);
        root->data = succ->data;
        root->right = delNode(root->right, succ->data);
    }
    return root;
}

void preorder(struct tree_node* node){
    if(node==NULL)
        return;
    printf("%d ",node->data);
    preorder(node->left);
    preorder(node->right);    
}

void inorder(struct tree_node* node){
    if(node==NULL)
        return;
    inorder(node->left);
    printf("%d ",node->data);
    inorder(node->right);    
}

void postorder(struct tree_node* node){
    if(node==NULL)
        return;        
    postorder(node->left);
    postorder(node->right);
    printf("%d ",node->data);    
}

int main(){
    int flag = 1;
    while(flag==1){
        printf("Enter choice: ");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Preorder Traversal");
        printf("\n4. Inorder Traversal");
        printf("\n5. Postorder Traversal");
        printf("\n6. Exit\n");
        int num, pos, choice;
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("\nEnter element to insert\n");
                    scanf("%d",&num);
                    insert(num);
                    printf("\nElement inserted successfully\n\n");
                    break;            
            case 2: printf("\nEnter element to delete\n");
                    scanf("%d",&num);
                    root = delNode(root,num);
                    printf("\nElement deleted\n\n");
                    break;
            case 3: printf("\nPreorder traversal: \n");
                    preorder(root);
                    printf("\n\n");
                    break;
            case 4: printf("\nInorder traversal: \n");
                    inorder(root);
                    printf("\n\n");
                    break;
            case 5: printf("\nPostorder traversal: \n");
                    postorder(root);
                    printf("\n\n");
                    break;
            case 6: printf("\nGoodbye!!");
                    flag = 0;
                    break;
            default: printf("\nEnter valid choice!!\n\n");
        }
    }
}