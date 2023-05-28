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


int main(){
    // int arr[] ={8,1,2,9,10,11,22,5,19,55};
    // int arr[] = {1, 14, 3, 7, 4, 5, 15, 6, 13, 10, 11, 2, 12, 8, 9} ;
    int arr[] = {1, 2, 5, 3, 6, 4} ;
    int len = sizeof(arr)/sizeof(arr[0]);
    NODE Root = create_tree(arr,len);
    preorder(Root);
    printf("\n");

}