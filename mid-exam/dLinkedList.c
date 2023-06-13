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
void display(struct Node* head){
    struct Node* tmp =  head;
    printf("DLL :\n NULL <-> ");
    while(tmp != NULL){
        printf("%d <-> ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void display_rev(struct Node* head){
    struct Node* tmp = head;
    printf("DLL in reverse : NULL <-> ");
    while(tmp != NULL||tmp->next != NULL){
        tmp = tmp->next;
    }
    while(tmp->prev != NULL){
        printf("%d <-> ",tmp->data);
        tmp = tmp->prev;
    }
    printf("NULL\n");
}

int LEN(struct Node* head){
    int len = 0;
    struct Node* tmp = head;
    while (tmp != NULL)
    {
        len++;
        tmp = tmp->next;
    }
    return len;
}
struct Node* insert(struct Node* head, int data, int index){
    int len = LEN(head);
    if(index<0 || index>len){
        return head;
    }
    struct Node* newNode = create_Node(data);
    struct Node* tmp = head;
    if(index == 0){
        if(len == 0){
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }else if(index == len){
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = newNode;
        newNode->prev = tmp;
    }else{
        for(int i = 0;i<index-1;i++){
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        newNode->prev = tmp;
        tmp->next->prev = newNode;
        tmp->next = newNode;
    }
    return head;
}

struct Node* delete(struct Node* head, int index){
    int len = LEN(head);
    if(index < 0 || index>=len || head == NULL){
        return head;
    }
    struct Node* tmp = head;
    if(index == 0){
        if(len == 1){
            return NULL;
        }
        head->next->prev = NULL;
        head = head->next;
    }else if (index == len-1){
        while(tmp != NULL || tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next->prev = NULL;
        tmp->next = NULL;
    }else{
        for(int i = 0;i<index-1;i++){
            tmp = tmp->next;
        }
        tmp->next->next->prev = tmp;
        tmp->next = tmp->next->next;
    }
    return head; 
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