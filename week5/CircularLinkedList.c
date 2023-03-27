#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
void display(struct Node* last){
    struct Node* tmp = last->next;
    printf("||->");
    while(tmp != last){
        printf(" %d ->",tmp->data);
        tmp = tmp->next;
    }
    printf("||");
}

int main(){
    
    // struct Node* first = (struct Node*)malloc(sizeof(struct Node*));
    // struct Node* second = (struct Node*)malloc(sizeof(struct Node*));
    // struct Node* third = (struct Node*)malloc(sizeof(struct Node*));
    // struct Node* four = (struct Node*)malloc(sizeof(struct Node*));
    // struct Node* Last = four;
    // struct Node* Last.next = head;

    // first->data = 1;
    // second->data = 2;
    // third->data = 3;
    // four->data = 4;

    // four->next = first
    // first->next = second;
    // second->next = third;
    // third->next = four;
    // four->next = Last;

    struct Node* Last = (struct Node*)malloc(sizeof(struct Node*));
    Last->next = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* tmp = Last->next;

    for(int i = 0;i<3;i++){
        
        tmp->data = i;
        if(i == 2){
            tmp->next = Last;
        }
        else{
            tmp->next = (struct Node*)malloc(sizeof(struct Node*));
            tmp = tmp->next;
        }
    }
    tmp = Last->next;
    for(int i = 0;i<3;i++){
        printf("%d->",tmp->data);
        tmp = tmp->next;
    }
    display(Last);
    return 0;
}