#include<stdio.h>
#include<stdlib.h>

typedef struct Node* NODE;

struct Node {
    NODE left;
    NODE right;
    int data;
};

NODE create_node(int val) {
    NODE node = (NODE)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

NODE insert(NODE root, int val) {
    if (root == NULL) {
        return create_node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

NODE find_min(NODE root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    } else {
        return find_min(root->left);
    }
}

NODE delete_node(NODE root, int val) {
    if (root == NULL) {
        printf("Value not found in the binary tree.\n");
        return root;
    }
    if (val < root->data) {
        root->left = delete_node(root->left, val);
    } else if (val > root->data) {
        root->right = delete_node(root->right, val);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
            printf("Value %d deleted successfully.\n", val);
        } else if (root->left == NULL) {
            NODE temp = root;
            root = root->right;
            free(temp);
            printf("Value %d deleted successfully.\n", val);
        } else if (root->right == NULL) {
            NODE temp = root;
            root = root->left;
            free(temp);
            printf("Value %d deleted successfully.\n", val);
        } else {
            NODE temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
            printf("Value %d deleted successfully.\n", val);
        }
    }
    return root;
}

void inorder(NODE root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(NODE root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(NODE root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    NODE root = NULL;

    int choice = 0;
    int value;
    while (choice != 5) {
        printf("Binary Tree Operations:\n");
        printf("1. Inorder Traversal\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Insert a value\n");
        printf("5. Delete a value\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 4:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value %d inserted successfully.\n", value);
                break;
            case 5:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = delete_node(root, value);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}
