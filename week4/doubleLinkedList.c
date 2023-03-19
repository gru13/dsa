#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

int len(struct Node * head){
    int len = 0;
    struct Node* tmp = head;
    while(tmp != NULL){
        len++;
        tmp = tmp->next;
    }
    return len;
}

void display(struct Node* head){
    struct Node* tmp = head;
    while(tmp != NULL){
        printf("%d -> ",tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

struct Node* insert(int index, int val, struct Node* head){
    if(index == 0){
        // inserting in start
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
        newNode->data = val;
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = head->prev;
        return head;
    }
    else if(index == len(head)-1){
        // inserting at end
        struct Node* tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = (struct Node*)malloc(sizeof(struct Node*));
        tmp->next->prev = tmp;
        tmp->next->data = val;
        tmp->next->next = NULL;
    }
    else{
        // insertin in bwtn
        struct Node* tmp = head;
        for(int i = 0;i<index-1;i++){
            tmp = tmp->next;
        }
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
        newNode->data = val;
        newNode->next = tmp->next;
        newNode->prev = tmp;
        tmp->next->prev=newNode;
        tmp->next = newNode;

    }
    return head;
}

struct Node* removed(int index, struct Node* head){
    if(index == 0){
        head = head->next;
        head->prev = NULL;
    }
    else if(index == len(head)-1){
        struct Node*  tmp = head;
        while(tmp->next->next != NULL){
            tmp = tmp->next;
        }
        tmp->next =  NULL;
    }
    else{
        struct Node* tmp = head;
        index--;
        while(index--){
            tmp = tmp->next;
        }
        tmp->next->next->prev = tmp;
        tmp->next = tmp->next->next;
    }
    return head;
}
int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node*));
    head->prev = NULL;
    struct Node* tmp = head;
    int length;
    printf("The length of the dll : ");
    scanf("%d",&length);
    for(int i = 0;i<length;i++){
        printf("Enter the value of the index %d : ",i);
        scanf("%d", &tmp->data);
        if(length - 1 == i){
            tmp->next = NULL;
        }
        else{
            tmp->next = (struct Node*)malloc(sizeof(struct Node*));
            tmp->next->prev = tmp;
            tmp = tmp -> next;
        }
    }
    display(head);
    // head = insert(2,100,head);
    head = removed(3,head);
    display(head);

}