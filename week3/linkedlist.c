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
    else if(index == length-1 || index == -1) {
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
        struct Node* tmp = head;
        for(int i = 0;i<index-1;i++){
            tmp = tmp->next;
        }
        struct Node *ext = tmp->next;
        tmp->next = newNode;
        newNode->next = ext; 
    }
    else{
        printf("Can't be inserted");
    }
    return head;

}

struct Node* delete (struct Node* head, int index){
    int length = len(head);
    if(index == 0){
        head = head->next;
    }
    else if(index == length-1 || index == -1) {
        struct Node* tmp = head;
        while (tmp->next->next != NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=NULL; 
    }
    else if (index<length && index>0)
    {
        struct Node* tmp = head;
        for(int i = 0;i<index-1;i++){
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
 
    }
    else{
        printf("Can't be inserted");
    }
    return head;

}

struct Node* Create(struct Node* head, int length){
    if(head == NULL){
        head  = (struct Node*)malloc(sizeof(struct Node*));
    }
    struct Node* tmp = head;

    for(int i = 0;i<length;i++){
        printf("enter value of index %d : ",i);
        scanf("%d",&tmp->data);
        if(i == length - 1){
            tmp->next = NULL;   
        }
        else{
            tmp->next = (struct Node*)malloc(sizeof(struct Node*));
            tmp = tmp->next;
        }
    }

    return head;
}

int demo(){
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
    head = delete(head,2);
    display(head);
    printf("%d\n",len(head));
    return 0;
}

int main(){
    //  creation of menu;
    int len_ll,val;
    printf("Creating lined list\nenter length of linked list : ");
    scanf("%d",&len_ll);
    struct Node* head = NULL;
    head =  Create(head ,len_ll);

    int option,exit_status = 0;
    // printf("%d\n",len(head));
    do{
        printf("Select the below option:\n\n");
        printf("1.display the linked list\n");
        printf("2.insertion\n");
        printf("3.deletion\n");
        printf("4.length of linked list\n");
        printf("5.exit\n\nEnter Your option:");
        scanf("%d",&option);
        printf("\n--------------------------------------------------------------\n\n");
        int index,val;
        switch (option)
        {
        case 1:
            display(head);
            break;
        case 2:
            printf("(for appending enter -1)\nEnter the index of inserting : ");
            scanf("%d",&index);
            printf("Ënter the value for inserting : ");
            scanf("%d",&val);
            head = insert(head,index,val);
            break;
        case 3:
            printf("(for pop enter -1)\nEnter the index of deletion : ");
            scanf("%d",&index);
            head = delete(head,index);
            break;
        case 4:
            printf("\nlength of linked list is %d\n",len(head));
            break;
        case 5:
            printf("exiting.....\n");
            exit_status = 1;
            break;
        
        default:
            printf("enter the valid option\n");
            break;
        }
        printf("\n--------------------------------------------------------------\n\n");
    }
    while(exit_status != 1);
    return 0;  
}