#include<stdio.h>   
#include<stdlib.h>
#include<limits.h>

struct Node{
    struct Node* lft;
    struct Node* ryt;
    int data;
};

struct Node* create_node(int val){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->lft = NULL;
    n->ryt = NULL;
    return n;
} 
void inorder(struct Node* node){
    if (node == NULL)
        return;
 
    /* first recur on left child */
    inorder(node->lft);
 
    /* then print the data of node */
    printf("%d ", node->data);
 
    /* now recur on right child */
    inorder(node->ryt);
}
void preorder(struct Node* node){
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);
 
    /* first recur on left child */
    preorder(node->lft);
 
    /* now recur on right child */
    preorder(node->ryt);
}

void postorder(struct Node* node){
    if (node == NULL)
        return;
    /* first recur on left child */
    postorder(node->lft);
 
    /* now recur on right child */
    postorder(node->ryt);
 
    /* then print the data of node */
    printf("%d ", node->data);
 
}

void insert(struct Node* tree, int val){
    if(val < tree->data){
        if(tree->lft == NULL){
            tree->lft = create_node(val);
            return;
        }else{
            return insert(tree->lft,val);
        }
    }
    if(val > tree->data){
        if(tree->ryt == NULL){
            tree->ryt = create_node(val);
            return;
        }else{
            return insert(tree->ryt,val);
        }
    }
}

int main(){
    struct Node* Root = create_node(8);
    struct Node* l1 = create_node(3);
    struct Node* l2 = create_node(10);
    struct Node* l1l = create_node(2);
    struct Node* l1r = create_node(4);
    struct Node* l2l = create_node(9);
    struct Node* l2r = create_node(11);
    Root->lft = l1;
    l1->lft = l1l;
    l1->ryt = l1r;
    Root->ryt = l2;
    l2->lft = l2l;
    l2->ryt = l2r;
    inorder(Root);
    printf("\n");
    // preorder(Root);
    // printf("\n");
    // postorder(Root);
    // printf("\n");
    insert(Root,55);
    inorder(Root);
    printf("\n");

}