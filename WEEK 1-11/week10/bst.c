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
NODE create_tree(int* arr, int len){
    if(len <= 0 ){
        return NULL;
    }
    int val;
    NODE Root = create_node(arr[0]);
    for(int i = 1;i<len;i++){
        insert(Root, arr[i]);
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
    int arr[] ={8,1,2,9,10,11,22,5,19,55};
    int len = sizeof(arr)/sizeof(arr[0]);
    NODE Root = create_tree(arr,len);
    insert(Root ,55);
    insert(Root ,1);
    inorder(Root);
    printf("\n");

}