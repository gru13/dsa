#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* create_Node(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
int LEN(struct Node* last){
    if(last == NULL){
        return 0;
    }
    int len = 1;
    struct Node* head = last->next;
    while(head != last){
        len++;
        head = head->next;
    }
    return len;
}
void display(struct Node* last){
    int len = LEN(last);
    if(len == 0){
        printf("\nDQ:\nNULL\n");
        return;
    }
    struct Node* head = last->next;
    printf("\nDQ:\n||=>");
    for(int i = 0;i<len;i++){
        printf(" %d => ", head->data);
        head = head->next;
    }
    printf("||\n");
}
struct Node* insert_at_beg(struct Node* last, int data){
    int len = LEN(last);
    struct Node* newNode = create_Node(data);
    if(len == 0){
        newNode->next = newNode;
        newNode->prev = newNode;
        last = newNode;
        return last; 
    } 
    newNode->next = last->next;
    newNode->prev = last;
    last->next->prev = newNode;
    last->next = newNode;
    return last;
}
struct Node* insert_at_end(struct Node* last, int data){
    int len = LEN(last);
    struct Node* newNode = create_Node(data);
    if(len == 0){
        newNode->next = newNode;
        newNode->prev = newNode;
        last = newNode;
        return last; 
    } 
    newNode->next = last->next;
    newNode->prev = last;
    last->next->prev = newNode;
    last->next = newNode;
    last = last->next;
    return last;
}
struct Node* del_at_end(struct Node* last){
    int len = LEN(last);
    if(len == 1){
        last = NULL;
        return last; 
    } 
    last  = last->prev;
    last->next->next->prev = last;
    last->next = last->next->next;
    return last;
}
struct Node* del_at_beg(struct Node* last){
    int len = LEN(last);
    if(len == 1){
        last = NULL;
        return last; 
    } 
    last->next->next->prev = last;
    last->next = last->next->next;
    return last;
}

int main(){
    struct Node* DQ = NULL;
    display(DQ);
    DQ = insert_at_beg(DQ,2);
    DQ = insert_at_beg(DQ,1);
    DQ = insert_at_end(DQ,3);
    DQ = insert_at_end(DQ,4);
    DQ = del_at_beg(DQ);
    display(DQ);
}