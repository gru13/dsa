#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* Create(int len){
    struct Node* head = malloc(sizeof(struct Node*));
    struct Node* tmp = head;
    if(len == 0){
        return NULL;
    }
    if(len == 1){
        printf("enter value of index %d : ",i);
        scanf("%d",&tmp->data);
        tmp->next = NULL
    }
    for(int i = 0; i<len;i++){
        printf("enter value of index %d : ",i);
        scanf("%d",&tmp->data);
        if(i == length - 1){
            tmp->next = head;   
        }
        else{
            tmp->next = (struct Node*)malloc(sizeof(struct Node*));
            tmp = tmp->next;
        }
    }
    return tmp;
}


int main(){

    return 0;
}