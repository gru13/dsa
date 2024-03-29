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

struct Node* insert( struct Node* head,int index, int val){
    if(head == NULL){
        head = (struct Node*)malloc(sizeof(struct Node*));
        head->prev = NULL;
        head->data = val;
    }
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
    else if(index == len(head)-1 || index == -1){
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

struct Node* delete( struct Node* head,int index){
    if (head == NULL){return NULL;} // empty
    int length = len(head);

    if(index == 0){
        head = head->next;
        head->prev = NULL;
    }
    else if(index == length-1 || index == -1){
        struct Node*  tmp = head;
        while(tmp->next->next != NULL){
            tmp = tmp->next;
        }
        tmp->next =  NULL;
    }
    else if(index<length && index>0){
        struct Node* tmp = head;
        index--;
        while(index--){
            tmp = tmp->next;
        }
        tmp->next->next->prev = tmp;
        tmp->next = tmp->next->next;
    }
    else{
         printf("Can't be removed");
    }
    return head;
}

struct Node* Create(struct Node* head,int length){

    if(head == NULL){
        head = (struct Node*)malloc(sizeof(struct Node*));
        head->prev = NULL;
    }

    struct Node* tmp = head;

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
    return head;
}
int demo(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node*));
    head->prev = NULL;
    int length;
    printf("The length of the dll : ");
    scanf("%d",&length);
    head = Create(head, length);
    head = insert(head,2,100);
    display(head);
    head = delete(head,3);
    display(head);

}
int main(){
    //  creation of menu;
    int len_ll,val;
    printf("Creating lined list\nenter length of Double LinkedList : ");
    scanf("%d",&len_ll);
    struct Node* head = NULL;
    head =  Create(head ,len_ll);

    int option,exit_status = 0;
    // printf("%d\n",len(head));
    do{
        printf("Select the below option:\n\n");
        printf("1.display the Double LinkedList\n");
        printf("2.insertion\n");
        printf("3.deletion\n");
        printf("4.length of Double LinkedList\n");
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
            printf("\nLength of Double LinkedList is %d\n",len(head));
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
