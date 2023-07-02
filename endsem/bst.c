#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* ryt;
    struct Node* lft;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->ryt = NULL;
    newNode->lft = NULL;
    return newNode;
}

void inorderTraveral(struct Node* root){
    if(root == NULL){
        return;
    }
    inorderTraveral(root->lft);
    printf(" %d ->",root->data);
    inorderTraveral(root->ryt);
}

void postorderTraveral(struct Node* root){
    if(root == NULL){
        return;
    }
    postorderTraveral(root->lft);
    postorderTraveral(root->ryt);
    printf(" %d ->",root->data);
}

void preorderTraveral(struct Node* root){
    if(root == NULL){
        return;
    }
    printf(" %d ->",root->data);
    preorderTraveral(root->lft);
    preorderTraveral(root->ryt);
}

struct Node* inorderSuccessor(struct Node* root){
    while(root != NULL && root->lft != NULL){
        root = root->lft;
    }
    return root;
}
struct Node* inorderpredecessor(struct Node* root){
    while(root != NULL && root->ryt != NULL){
        root = root->ryt;
    }
    return root;
}
int noc(struct Node* root){
    int no = 0;
    if(root == NULL){
        return no;
    }
    if(root->lft != NULL){
        no++;
    }
    if(root->ryt != NULL){
        no++;
    }
    return no;
}

struct Node* insertNode(struct Node* root, int data){
    if(root==NULL){
        return createNode(data);
    }
    if(root->data < data){
        root->ryt = insertNode(root->ryt, data);
    }
    if(root->data > data){
        root->lft = insertNode(root->lft, data);
    }
    return root;
}
struct Node* deleteNode(struct Node* root, int data){
    if(root->data < data){
        root->ryt = deleteNode(root->ryt, data);
    }
    if(root->data > data){
        root->lft = deleteNode(root->lft, data);
    }
    if(root->data == data){
        
    }
    return root;
}
int main(){
    int arr[] = {9,4,5,7,10};
    int len = sizeof(arr)/sizeof(arr[0]);
    struct Node* root = NULL;
    for(int i =0;i<len;i++){
        root = insertNode(root, arr[i]);
    }
    root = deleteNode(root, 4);    
    inorderTraveral(root);
}