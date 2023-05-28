#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node Node;

struct Node{
    int data;
    int height;
    Node* lft;
    Node* ryt;
};

Node* create_Node(int data){
    Node* newNode = (Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->lft = NULL;
    newNode->ryt = NULL;
    newNode->height = 1;
    return newNode;
}

Node create_Tree(int* arr){
    int len = sizeof(arr)/sizeof(arr[0]);

}