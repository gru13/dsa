#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void display(struct Node* last){
    struct Node* tmp = last->next;
    printf("\n||->");
    while(tmp != last){
        printf(" %d ->",tmp->data);
        tmp = tmp->next;
    }
    printf("||\n");
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

int len(struct Node* Last){
    int len = 0;
    struct Node* tmp = Last->next;
    while(tmp!=Last){
        len++;
        tmp = tmp->next;
    }
    return len;
}

struct Node* insert(struct Node* Last, int index, int val){
    struct Node* tmp = Last->next;
    int length = len(Last);
    struct Node* new = (struct Node*) malloc(sizeof(struct Node*));
    new->data = val;
    if(index == 0){
        new->next = Last->next;
        Last->next = new;
    }
    else if(index == length - 1){
        for(int i = 0;i<length-1;i++){
            tmp = tmp->next;
        }
        new->next = tmp->next;
        tmp->next = new;
        tmp = tmp->next;
    }
    else if(index > 0 && index < length){
        for(int i = 0;i<index-1;i++){
            tmp = tmp->next;
        }
        new->next = tmp->next;
        tmp->next = new;
    }
    return Last;
}

struct Node* remove(struct Node* Last, int index){
    struct Node* tmp = Last->next;
    int length = len(Last);
    if(index == 0){
        Last->next = Last->next->next;
    }
    else if(index == length - 1){
        while(tmp->next  != Last){
            tmp = tmp->next;
        }
        tmp->next = Last->next;
    }
    else if(index>0 && index < length -1){
        for(int i = 0;i<index-1;i++){
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
    }
    return Last;
}
int main(){
    struct Node* Last = (struct Node*)malloc(sizeof(struct Node*));
    Last = Create(Last, 6);
    display(Last);
    Last = insert(Last, 0, 11);
    Last = insert(Last, 5, 14);
    Last = insert(Last, 2, 99);
    display(Last);
    Last = remove(Last, 0);
    Last = remove(Last, 5);
    Last = remove(Last, 2);
    display(Last);
    printf("the ln : %d", len(Last));
    return 0;
}