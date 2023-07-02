#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int h;
    struct Node* ryt;
    struct Node* lft;
};

int max(int a, int b) {
    return a < b ? b : a;
}

int getHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->h;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->lft = NULL;
    newNode->ryt = NULL;
    newNode->h = 1;
    return newNode;
}

struct Node* leftRotate(struct Node* x) {
    /**
    
           x              y
          / \            / \
             y   -->    x
            / \        / \ 
           T2             T2

    */
    struct Node* y = x->ryt;
    struct Node* T2 = y->lft;

    // Perform rotation
    y->lft = x;
    x->ryt = T2;

    // Update heights
    x->h = max(getHeight(x->lft), getHeight(x->ryt)) + 1;
    y->h = max(getHeight(y->lft), getHeight(y->ryt)) + 1;

    // Return the new root
    return y;
}

struct Node* rightRotate(struct Node* y) {
    /**
    
          x                      y
         / \                    / \
        y        ---->             x
       / \                        / \
          T2                     T2

    */
    struct Node* x = y->lft;
    struct Node* T2 = x->ryt;

    // Perform rotation
    x->ryt = y;
    y->lft = T2;

    // Update heights
    y->h = max(getHeight(y->lft), getHeight(y->ryt)) + 1;
    x->h = max(getHeight(x->lft), getHeight(x->ryt)) + 1;

    // Return the new root
    return y;
}

int getBalance(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return getHeight(root->lft) - getHeight(root->ryt);
}

struct Node* balanceTheNode(struct Node* root) {
    int balance = getBalance(root);
    if (-1 <= balance && balance <= 1) {
        return root;
    }
    // Left-based
    else if (balance > 1) {
        // Right rotation
        if (getBalance(root->lft) < 0) {
            root->lft = leftRotate(root->lft);
        }
        return rightRotate(root);
    }
    // Right-based
    else if (balance < -1) {
        // Left rotation
        if (getBalance(root->ryt) > 0) {
            root->ryt = rightRotate(root->ryt);
        }
        return leftRotate(root);
    }
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->lft = insert(root->lft, data);
    } else if (data > root->data) {
        root->ryt = insert(root->ryt, data);
    }
    root->h = max(getHeight(root->lft), getHeight(root->ryt)) + 1;
    root = balanceTheNode(root);
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

struct Node* inorderSuccessorNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->lft != NULL)
        current = current->lft;
    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL)
        return root;
    if (data < root->data)
        root->lft = deleteNode(root->lft, data);
    else if (data > root->data)
        root->ryt = deleteNode(root->ryt, data);
    else {
        if ((root->lft == NULL) || (root->ryt == NULL)) {
            struct Node* temp = root->lft ? root->lft : root->ryt;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            struct Node* temp = inorderSuccessorNode(root->ryt);
            root->data = temp->data;
            root->ryt = deleteNode(root->ryt, temp->data);
        }
    }
    if (root == NULL)
        return root;
    root->h = max(getHeight(root->lft), getHeight(root->ryt)) + 1;
    root = balanceTheNode(root);
    return root;
}

int main() {
    struct Node* root = NULL;
    // int arr[] = {21, 26, 30, 9, 4, 14, 28, 18, 15};
    // int arr[] = { 13, 8, 5, 9, 4, 6, 12, 2, 1,3};
    // int arr[] = { 1,2,3,4,5,6,7,8,9};
    int arr[] = {9,4,5,7,8,2,11,1};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++) {
        root = insert(root, arr[i]);
    }
    root = deleteNode(root,5);
    root = deleteNode(root,9);
    root = insert(root,0);
    preorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    return 0;
}
