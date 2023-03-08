#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

void display(struct Node *head){
    struct Node *tmp = head;
    while(tmp != NULL){
        printf("The value is : %d\n",tmp->value);
        tmp = tmp->next;
    }
}

int main(){
    struct Node *head;
    
    
    /*
    */
    // struct Node *arr[10];

    // for(int i = 0; i<11;i++){
    //     arr[i] = (struct Node*)malloc(sizeof(struct Node*));
    // }
    // for(int i = 0; i<11;i++){
    //     arr[i]->value = i;
    //     if(i < h){arr[i]->next = arr[i+1];}
    //     else{arr[i]->next=NULL;}
    // }
    // head = arr[0];
    
    
    struct Node *first = (struct Node*) malloc(sizeof(struct Node*));
    struct Node *second = (struct Node*) malloc(sizeof(struct Node*));
    struct Node *third = (struct Node*) malloc(sizeof(struct Node*));

    head = first;
    first->value = 1;
    first->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = NULL;  
    
    display(head);
}