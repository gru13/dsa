#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* create_Node(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = data;
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
        printf("\nCDLL:\n||<=> NULL <=>||\n");
        return ;
    }
    printf("\nCDLL: \n||<=> ");
    struct Node* head = last->next;
    for(int i = 0;i<len;i++){
        printf(" %d <=> ", head->data);
        head = head->next;
    }
    printf("||\n");
}
struct Node* insert(struct Node* last, int index, int data){
    if(last == NULL){
        last = create_Node(data);
        last->next = last;
        last->prev = last;
        return last;
    }
    int len = LEN(last);
    struct Node* newNode = create_Node(data);
    struct Node* head = last->next;
    if(index==0){   
        newNode->next = last->next;
        newNode->prev = last;
        newNode->next->prev = newNode;
        last->next = newNode;
    }else{
        for(int i = 0;i<index-1;i++){
            head = head->next;
        }
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
        if(index == len){
            last = last->next;
        }
    }
    return last;
}
struct Node* delete(struct Node* last, int index){
    int len = LEN(last);
    if(len<=0 || index<0 || index >= len){
        return last;
    }
    if(index==0&&len == 1){
        return NULL;
    }

    struct Node* head = last->next;
    if(index ==  0){
        last->next->next->prev = last;
        last->next = last->next->next;
    }else{
        for(int i = 0;i<index-1;i++){
            head = head->next;
        }
        if(head->next == last){
            last = head;
        }
        head->next->next->prev = head;
        head->next = head->next->next;
    }
    return last;
} 
int main(){
    struct Node* head = NULL;
    head = insert(head, 0, 0);
    head = insert(head, 1, 1);
    head = insert(head, 2, 2);
    head = insert(head, 3, 3);
    display(head);
    head = delete(head,0);
    display(head);
    head = delete(head,1);
    display(head);
    head = delete(head,3);
}