#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* create_Node(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node* head){
    struct Node* tmp = head;
    printf("THE LINKEDLIST :\n");
    while(tmp != NULL){
        printf(" %d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
    return;
}

int  LEN(struct Node* head){
    struct Node* tmp = head;
    int len = 0;
    while(tmp!=NULL){
        tmp = tmp->next;
        len++;
    }    
    return len;
}

struct Node* insert(struct Node* head,int data, int index){
    int len = LEN(head);
    if(index<0 || index>len){
        return head;
    }
    struct Node* newNode = create_Node(data);
    struct Node* tmp  = head;
    if(index == 0){ 
        newNode->next = head;
        head = newNode;
    } else if(index == len){
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = newNode;
    } else {
        index--;
        while(index!=0){
            index--;
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode; 
    }
    return head; 
}

struct Node* delete(struct Node* head, int index){
    int len = LEN(head);
    if(index<0 || index >= len || head == NULL){
        return head;
    }
    struct Node* tmp = head;
    if(index == 0){
        head = head->next;
    }else{
        for(int i = 0;i<index-1;i++){
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
    }
    return head;

} 

int main(){
    struct Node* head = NULL;
    head = insert(head,0,0);
    head = insert(head,1,1);
    head = insert(head,2,2);
    head = insert(head,3,3);
    head = insert(head,4,4);
    display(head);
    head = delete(head,0);
    head = delete(head,3);
    display(head);
}