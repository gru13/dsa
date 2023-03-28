#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node* next;
    struct Node* prev;
}

int main(){
    struct Node* last = (struct Node*)malloc(sizeof(struct Node*));
    last->prev = NULL;
    last->next = NULL;
    struct Node* tmp = last.next;
    for(int i = 0;i<5;i++){
        tmp->data = i;
        if(i == 0){
            tmp->next = (struct Node*)malloc(sizeof(struct Node*));
            tmp->next->prev = Last;
        }
        if(i != 4){
            tmp->next = (struct Node*)malloc(sizeof(struct Node*));
            tmp->next->prev = tmp;
        }
        else{
            tmp->next = Last;
            Last->prev = tmp;
        }
    }

}