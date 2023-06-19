#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* lft;
    struct Node* ryt;
};

int no_Of_Child(struct Node* root){
    int no_of_child = 0;
    if(root->lft != NULL){
        no_of_child++;
    }
    if(root->ryt != NULL ){
        no_of_child++;
    }
    return no_of_child;
}

struct Node* Create_Node(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->lft = NULL;
    newNode->ryt = NULL;
    newNode->data = data;
    return newNode;
}

struct Node* inorder_suc_Node(struct Node* root){
    struct Node* tmp = root;
    while(tmp->lft != NULL){
        tmp = tmp->lft;
    }
    return tmp;
}

struct Node* inorder_pre_Node(struct Node* root){
    struct Node* tmp = root;
    while(tmp->ryt != NULL){
        tmp = tmp->ryt;
    }
    return tmp;
}

struct Node* insert(struct Node* root,int data){
    if(root == NULL){
        return Create_Node(data);
    }else if(data<root->data){
        root->lft = insert(root->lft, data);
    }else if(data>root->data){
        root->ryt = insert(root->ryt, data);
    }
    return root;
}

struct Node* Delete(struct Node* root,int data){
    if(root == NULL){
        return NULL;
    }
    if(root->data != data){
        if(data < root->data){
            root->lft = Delete(root->lft, data);
        }else{
            root->ryt = Delete(root->ryt, data);
        }
        return root;
    }
    int noc = no_Of_Child(root);
    if(noc == 0){
        free(root);
        return NULL;  
    }else if(noc == 1){
        if(root->lft != NULL){
            root->data = root->lft->data;
            free(root->lft);
            root->lft = NULL;
            return root;
        }
        if(root->ryt != NULL){
            root->data = root->ryt->data;
            free(root->ryt);
            root->ryt = NULL;
            return root;
        }
    }else if(noc == 2){
        struct Node* inorder_suc = inorder_suc_Node(root->ryt);
        root->data = inorder_suc->data;
        root->ryt = Delete(root->ryt, root->data);
        return root;
    }
    return root;
}
void inOrder(struct Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->lft);
    printf("%d -> ",root->data);
    inOrder(root->ryt);
    return;
}
int main(){
    struct Node* root = NULL;
    
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 9);
    root = insert(root, 2);
    inOrder(root);
    printf("\n");
    root = Delete(root, 5);
    inOrder(root);
    printf("\n");
    printf("%d\n",root->data);
    root = insert(root, 5);
    inOrder(root);
}
