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

struct Node* Create(struct Node* Last, int length){
    if(Last == NULL){
       struct Node* Last = (struct Node*)malloc(sizeof(struct Node*)); 
    }
    Last->next = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* tmp = Last->next;
    for(int i = 0;i<length;i++){
        printf("enter value of index %d : ",i);
        scanf("%d",&tmp->data);
        if(i == length - 1){
            tmp->next = Last;
        }
        else{
            tmp->next = (struct Node*)malloc(sizeof(struct Node*));
            tmp = tmp->next;
        }
    }
    return Last;


}
int main(){
    


    struct Node* Last = (struct Node*)malloc(sizeof(struct Node*));
    Last = Create(Last, 5);
    display(Last);
    return 0;
}