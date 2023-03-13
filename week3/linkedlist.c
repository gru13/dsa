#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
    
};

int len(struct Node* head){
    struct Node* tmp = head;
    int len = 0; 
    while (tmp != NULL)
    {
        len++;
        tmp = tmp->next;
    }
    return len;
}


void display(struct Node* head){
    struct Node* tmp = head;
    while (tmp != NULL)
    {
        printf("%d -> ",tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

struct Node* insert (struct Node* head, int index, int val){
    struct Node* newNode  = (struct Node*) malloc(sizeof(struct Node*));
    newNode->data = val;
    int length = len(head);
    if(index == 0){
        newNode->next = head;
        head = newNode; 
    }
    else if(index == length-1) {
        struct Node* tmp = head;
        while (tmp->next != NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=newNode;
        newNode->next=NULL; 
    }
    else if (index<length && index>0)
    {
        puts("ghur");
    }
    else{
        printf("Can't be inserted");
    }
    return head;

}

int main(){
    struct Node* first = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* four = (struct Node*)malloc(sizeof(struct Node*));

    first->data = 1;
    second->data = 2;
    third->data = 3;
    four->data = 4;

    first->next = second;
    second->next = third;
    third->next = four;
    four->next = NULL;

    struct Node* head = first;

    display(head);
    head = insert(head,2,4);
    display(head);
    printf("%d\n",len(head));
    return 0;
}