#include<stdio.h>   
#include<stdlib.h>
#include<limits.h>

typedef struct Node* NODE;

struct Node{
    NODE lft;
    NODE ryt;
    int data;
};

NODE create_node(int val){
    NODE n = (NODE)malloc(sizeof(struct Node*));
    n->data = val;
    n->lft = NULL;
    n->ryt = NULL;
    return n;
} 
NODE create_tree(int* arr, int len){
    if(len <= 0 ){
        return NULL;
    }
    int val;
    NODE Root = create_node(arr*);
    for(int i = 1;i<len;i++){
        val = arr[i];
        insert(Root,val);
    }
    return Root;
}

void inorder(NODE node){
    if (node == NULL)
        return;
    
    /* first recur on left child */
    inorder(node->lft);
 
    /* then print the data of node */
    printf("%d ", node->data);
 
    /* now recur on right child */
    inorder(node->ryt);
}
void preorder(NODE node){
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);
 
    /* first recur on left child */
    preorder(node->lft);
 
    /* now recur on right child */
    preorder(node->ryt);
}

void postorder(NODE node){
    if (node == NULL)
        return;
    /* first recur on left child */
    postorder(node->lft);
 
    /* now recur on right child */
    postorder(node->ryt);
 
    /* then print the data of node */
    printf("%d ", node->data);
 
}

void insert(NODE tree, int val){
    if(val == tree->data){
        return;
    }
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
    // NODE Root = create_node(8);
    // NODE l1 = create_node(3);
    // NODE l2 = create_node(10);
    // NODE l1l = create_node(2);
    // NODE l1r = create_node(4);
    // NODE l2l = create_node(9);
    // NODE l2r = create_node(11);
    // Root->lft = l1;
    // l1->lft = l1l;
    // l1->ryt = l1r;
    // Root->ryt = l2;
    // l2->lft = l2l;
    // l2->ryt = l2r;
    // inorder(Root);
    // printf("\n");
    // preorder(Root);
    // printf("\n");
    // postorder(Root);
    // printf("\n");
    int* arr = malloc(sizeof(int)*8);
    // arr = 8,3,10,2,4,5,9,11;
    arr[0] = 8;
    arr[1] = 3;
    arr[2] = 10;
    arr[3] = 2;
    arr[4] = 4;
    arr[5] = 5;
    arr[6] = 9;
    arr[7] = 11;
    NODE Root = create_tree(arr,8);
    insert(Root ,55);
    insert(Root ,1);
    inorder(Root);
    printf("\n");

}