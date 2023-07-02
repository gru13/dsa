#include <stdio.h>
#include <stdlib.h>

// Structure for a node in AVL tree
struct Node {
    int data;
    struct Node* lft;
    struct Node* ryt;
    int height;
};

// Function to get the height of a node
int getHeight(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->lft = NULL;
    newNode->ryt = NULL;
    newNode->height = 1;
    return newNode;
}

// Function to right rotate a subtree rooted with y
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->lft;
    struct Node* T2 = x->ryt;

    // Perform rotation
    x->ryt = y;
    y->lft = T2;

    // Update heights
    y->height = max(getHeight(y->lft), getHeight(y->ryt)) + 1;
    x->height = max(getHeight(x->lft), getHeight(x->ryt)) + 1;

    // Return the new root
    return x;
}

// Function to lft rotate a subtree rooted with x
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->ryt;
    struct Node* T2 = y->lft;

    // Perform rotation
    y->lft = x;
    x->ryt = T2;

    // Update heights
    x->height = max(getHeight(x->lft), getHeight(x->ryt)) + 1;
    y->height = max(getHeight(y->lft), getHeight(y->ryt)) + 1;

    // Return the new root
    return y;
}

// Function to get the balance factor of a node
int getBalance(struct Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->lft) - getHeight(node->ryt);
}

struct Node* balanceTheNode(struct Node* root) {
    // Get the balance factor of the current node
    int balance = getBalance(root);

    // Left Left Cas
    if (balance > 1 && getBalance(root->lft) >= 0)
        return rotateRight(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->lft) < 0) {
        root->lft = rotateLeft(root->lft);
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->ryt) <= 0)
        return rotateLeft(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->ryt) > 0) {
        root->ryt = rotateRight(root->ryt);
        return rotateLeft(root);
    }

    return root;
}

// Function to find the minimum value node in a given AVL tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->lft != NULL)
        current = current->lft;
    return current;
}

// Function to perform deletion of a node in an AVL tree
struct Node* deleteNode(struct Node* root, int data) {
    // Perform the normal BST deletion
    if (root == NULL)
        return root;

    if (data < root->data)
        root->lft = deleteNode(root->lft, data);
    else if (data > root->data)
        root->ryt = deleteNode(root->ryt, data);
    else {
        // Node to be deleted is found

        // Case 1: Node has no child or only one child
        if (root->lft == NULL || root->ryt == NULL) {
            struct Node* temp = root->lft ? root->lft : root->ryt;

            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else // One child case
                *root = *temp; // Copy the contents of the non-empty child

            free(temp);
        } else {
            // Case 2: Node has two children

            struct Node* temp = minValueNode(root->ryt);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->ryt = deleteNode(root->ryt, temp->data);
        }
    }

    // If the tree had only one node, return
    if (root == NULL)
        return root;

    // Update the height of the current node
    root->height = 1 + max(getHeight(root->lft), getHeight(root->ryt));

    return balanceTheNode(root);
}

// Function to insert a node into an AVL tree
struct Node* insertNode(struct Node* root, int data) {
    // Perform the normal BST insertion
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->lft = insertNode(root->lft, data);
    else if (data > root->data)
        root->ryt = insertNode(root->ryt, data);
    else
        return root; // Duplicate datas not allowed

    // Update the height of the ancestor node
    root->height = 1 + max(getHeight(root->lft), getHeight(root->ryt));
    
    return balanceTheNode(root);
}

// Function to print the AVL tree in in-order traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->lft);
        printf("%d ", root->data);
        inorderTraversal(root->ryt);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->lft);
        postorderTraversal(root->ryt);
        printf("%d ", root->data);
    }
}
// Driver code
int main() {
    struct Node* root = NULL;
    int arr[] = {9,6,5,8,7,10};
    for(int i =0;i<6;i++){
        root = insertNode(root, arr[i]);
    }
    postorderTraversal(root);
    return 0;
}


// Function to print the AVL tree in post-order traversal

