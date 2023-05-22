#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node* NODE;

struct Node{
    int data;
    int height;
    NODE lft;
    NODE ryt;
};

NODE create_Node(int data){
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->lft = NULL;
    newNode->ryt = NULL;
    newNode->height = 1;
    return newNode;
}

NODE create_Tree(int* arr, int len){
    
}