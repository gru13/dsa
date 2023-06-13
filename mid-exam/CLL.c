#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* create_Node(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next = NULL;
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
        head = head->next;
        len++;
    }
    return len;
}

void display(struct Node* last){
    if(last == NULL){
        printf("\nCLL:\n|| <-> NULL <->||\n");
        return;
    }
    struct Node* head = last->next;
    printf("\nCLL:\n|| <-> ");
    int len = LEN(last);
    while(len--){
        printf(" %d <->", head->data);
        head = head->next;
    }
    printf(" ||");
    return;
}

struct Node* insert(struct Node* last, int index, int data){
    struct Node* newNode = create_Node(data);
    if(last == NULL){
        newNode->next = newNode;
        return newNode;
    }
    int len = LEN(last);
    struct Node* head = last;
    if(index<0 || index > len){
        return last;
    }
    if(index == 0 || index == len){
        newNode->next = last->next;
        last->next = newNode;
        if(len == index){
            last = last->next;
        }
    }else{
        for(int i = 0;i<index-1;i++){
            head = head->next;
        }
        newNode->next = head->next;
        head->next = newNode;
    }
    return last;
}

struct Node* delete(struct Node* last, int index){
    if(last == NULL){
        return last;
    }
    int len = LEN(last);
    if(index<0 || index>=len){
        return last;
    }
    if(len == 1 && index == 0){
        return NULL;
    }
    struct Node* head = last->next;
    if(index == 0){
        last->next = last->next->next;
    }else{
        for(int i = 0;i<index-1;i++){
            head = head->next;
        }
        head->next = head->next->next;
        if(index == len-1){
            last = head;
        }
    }
    return last;
}
int main(){
    struct Node* head = NULL;
    // display(head);
    head = insert(head, 0, 0);
    // display(head);
    head = insert(head, 1, 1);
    // display(head);
    head = insert(head, 2, 2);
    // display(head);
    head = insert(head, 3, 3);
    display(head);
    // head = delete(head,0);
    // display(head);
    head = delete(head,3);
    display(head);
    // head = delete(head,3);

}