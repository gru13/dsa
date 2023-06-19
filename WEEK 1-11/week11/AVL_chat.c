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

    // Get the balance factor of the current node
    int balance = getBalance(root);

    // Lft Lft Case
    if (balance > 1 && getBalance(root->lft) >= 0)
        return rightRotate(root);

    // Lft Right Case
    if (balance > 1 && getBalance(root->lft) < 0) {
        root->lft = leftRotate(root->lft);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->ryt) <= 0)
        return leftRotate(root);

    // Right Lft Case
    if (balance < -1 && getBalance(root->ryt) > 0) {
        root->ryt = rightRotate(root->ryt);
        return leftRotate(root);
    }

    return root;
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

    // Get the balance factor of the ancestor node to check for imbalance
    int balance = getBalance(root);

    // Lft Lft Case
    if (balance > 1 && data < root->lft->data)
        return rightRotate(root);

    // Lft Right Case
    if (balance > 1 && data > root->lft->data) {
        root->lft = leftRotate(root->lft);
        return rightRotate(root);
    }
    // Right Right Case
    if (balance < -1 && data > root->ryt->data)
        return leftRotate(root);


    // Right Lft Case
    if (balance < -1 && data < root->ryt->data) {
        root->ryt = rightRotate(root->ryt);
        return leftRotate(root);
    }

    // Return the new root
    return root;
}

// Function to print the AVL tree in in-order traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->lft);
        printf("%d ", root->data);
        inorderTraversal(root->ryt);
    }
}

// Driver code
int main() {
    struct Node* root = NULL;

    // Inserting nodes into the AVL tree
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    // Printing the AVL tree
    printf("In-order traversal of the AVL tree: ");
    inorderTraversal(root);
    printf("\n");

    // Deleting nodes from the AVL tree
    root = deleteNode(root, 30);
    root = deleteNode(root, 40);

    // Printing the AVL tree after deletion
    printf("In-order traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
