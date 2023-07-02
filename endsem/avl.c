#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    int h;
    struct Node* ryt;
    struct Node* lft;
};

int hyt(struct Node* root){
    if(root == NULL){
        return 0;
    }
    return root->h;
}

int max(int a, int b){
    return a>b?a:b;
}

struct Node* inorderSuccessor(struct Node* root){
    while(root != NULL && root->lft != NULL){
        root = root->lft;
    }
    return root;
}

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->h = 1;
    newNode->lft = NULL;
    newNode->ryt = NULL;
    return newNode;
}

struct Node* RR(struct Node* x){
    struct Node* y = x->lft;
    struct Node* T1 = y->ryt;

    // rotation
    y->ryt = x;
    x->lft = T1;

    x->h = max(hyt(x->ryt), hyt(x->lft)) + 1;
    y->h = max(hyt(y->ryt), hyt(y->lft)) + 1;

    return y;
    
}
struct Node* LL(struct Node* x){
    struct Node* y = x->ryt;
    struct Node* T1 = y->lft;

    // rotation
    y->lft = x;
    x->ryt = T1;

    x->h = max(hyt(x->ryt), hyt(x->lft)) + 1;
    y->h = max(hyt(y->ryt), hyt(y->lft)) + 1;

    return y;
    
}

int getBalance(struct Node* root){
    return hyt(root->lft) - hyt(root->ryt);
}

struct Node* BalanceTheNode(struct Node* root){
    int balance = getBalance(root);
    if(balance >= -1 && balance <= 1){
        return root;
    }
    // left side tree
    if(balance > 1){
        if(getBalance(root->lft) < 0){
            root->lft = LL(root->lft);
        }
        return RR(root);
    }
    // rigth side tree
    if(balance < -1){
        if(getBalance(root->ryt) > 0){
            root->ryt = RR(root->ryt);
        }
        return LL(root);
    }
    return root;
}

struct Node* insertNode(struct Node* root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(root->data == data){
        return root;
    }
    if(root->data < data){
        root->ryt = insertNode(root->ryt, data);
    }
    if(root->data > data){
        root->lft = insertNode(root->lft, data);
    }

    root->h = max(hyt(root->lft), hyt(root->ryt))+1;
    root = BalanceTheNode(root);
    return root;
}
struct Node* deleteNode(struct Node* root, int data){
    if(root == NULL){
        return root;
    }
    if(root->data < data){
        root->ryt = deleteNode(root->ryt , data);
    }
    if(root->data > data){
        root->lft = deleteNode(root->lft , data);
    }if(root->data == data){
        
        if(root->lft == NULL && root->ryt == NULL){
            free(root);
            return NULL;
        }
        else if(root->lft == NULL || root->ryt == NULL){
            struct Node* temp;
            if(root->lft != NULL){
                temp = root->lft;
            }
            else{
                temp = root->ryt;
            }
            free(root);
            return temp;
        }
        else
        {
            struct Node* inoderSC = inorderSuccessor(root->ryt);
            root->data = inoderSC->data;
            root->ryt = deleteNode(root->ryt, root->data);
        }
        if(root == NULL){
            return NULL;
        }
        root->h = max(hyt(root->lft), hyt(root->ryt))+1;
        root = BalanceTheNode(root);
        return root;
    }
    return root;
}


void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->lft);
    postorderTraversal(root->ryt);
    printf("%d -> ", root->data);
}
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->lft);
    printf("%d -> ", root->data);
    inorderTraversal(root->ryt);
}
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d -> ", root->data);
    preorderTraversal(root->lft);
    preorderTraversal(root->ryt);
}
int main() {
    struct Node* root = NULL;
    // int arr[] = {21, 26, 30, 9, 4, 14, 28, 18, 15};
    // int arr[] = { 13, 8, 5, 9, 4, 6, 12, 2, 1,3};
    int arr[] = { 1,2,3,4,5,6,7,8,9};
    // int arr[] = {9,4,5,7,8,2,11,1};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++) {
        root = insertNode(root, arr[i]);
    }
    root = deleteNode(root,5);
    root = insertNode(root,0);
    root = insertNode(root,2);
    root = insertNode(root,3);
    root = deleteNode(root,3);
    // root = insertNode(root,);
    preorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    return 0;
}
