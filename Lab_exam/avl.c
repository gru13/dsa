#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    int h;
    struct Node* ryt;
    struct Node* lft;
};
int max(int a,int b){
    return a<b?b:a;
}
int getHyt(struct Node* root){
    if(root == NULL){
        return 0;
    }
    return root->h;
}
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->lft = NULL;
    newNode->ryt = NULL;
    return newNode;
}

struct Node* LeftRotate(struct Node* x){
    struct Node* y = x->ryt;
    struct Node* T2 = y->lft;

    // Perform rotation
    y->lft = x;
    x->ryt = T2;

    // Update heights
    x->h = max(getHyt(x->lft), getHyt(x->ryt)) + 1;
    y->h = max(getHyt(y->lft), getHyt(y->ryt)) + 1;

    // Return the new root
    return y;
}

struct Node* RigthRotate(struct Node* y){
    struct Node* x = y->lft;
    struct Node* T2 = x->ryt;

    // Perform rotation
    x->ryt = y;
    y->lft = T2;

    // Update heights
    y->h = max(getHyt(y->lft), getHyt(y->ryt)) + 1;
    x->h = max(getHyt(x->lft), getHyt(x->ryt)) + 1;
    // Return the new root
    return x;
}

int balanceof(struct Node* root) {
    if (root == NULL)
        return 0;
    return getHyt(root->lft) - getHyt(root->ryt);
}
struct Node* balanceTheNode(struct Node* root){
    int balance = balanceof(root);
    if(-1<= balance && balance <= 1){
        return root;
    }
    // left based
    else if(balance > 1){
        // rigetHytt rotation
        if(balanceof(root->lft)<0){
            root->lft = LeftRotate(root->lft);
        }
        return RigthRotate(root);
    }
    // rigth
    else if(balance < -1){
        // left
        if(balanceof(root->ryt)>0){
            root->ryt = RigthRotate(root->ryt);
        }
        return LeftRotate(root);
    }
}
struct Node* insert(struct Node* root, int data){
    if(root == NULL){
        return createNode(data);
    }else if(data < root->data){
        root->lft = insert(root->lft, data);
    }else if(data > root->data){
        root->ryt = insert(root->ryt, data);
    }
    root->h = max(getHyt(root->lft), getHyt(root->ryt))+ 1;
    root = balanceTheNode(root);
    return root;
}

void inorder_traversal(struct Node* root){
    if(root == NULL){
        return;
    }
    inorder_traversal(root->lft);
    printf("%d -> ", root->data);
    inorder_traversal(root->ryt);
    return;
} 

int main(){
    struct Node* root = NULL;
    root = insert(root, 19);
    root = insert(root, 53);
    root = insert(root, 54);
    root = insert(root, 55);
    root = insert(root, 3);
    inorder_traversal(root);  
}