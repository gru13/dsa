#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void display(struct Node* last){
    if( last == NULL){
        printf("\n||-null-||\n");
        return;
    }
    if(last->next == NULL || last == last->next){
        printf("\n||-> %d ->||\n",last->data);
        return; 
    }
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
struct Node* Create_(struct Node* Last, int length){
    if(Last == NULL){
       struct Node* Last = (struct Node*)malloc(sizeof(struct Node*)); 
    }
    
    Last->next = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* tmp = Last->next;
    for(int i = 0;i<length;i++){
        // printf("enter value of index %d : ",i);
        // scanf("%d",&tmp->data);
        tmp->data = i;
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
    while(tmp!=Last && tmp != NULL){
        len++;
        tmp = tmp->next;
    }
    if (len == 0 && Last->next == NULL)
    {
        len++;
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
    else if(index == length - 1 || index == -1){
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
    else{
        printf("Can't be inserted");
    }
    return Last;
}

struct Node* delete_(struct Node* Last, int index){
    struct Node* tmp = Last->next;
    int length = len(Last);
    if(index == 0){
        Last->next = Last->next->next;
    }
    else if(index == length - 1 || index == -1){
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
    else{
        printf("Can't be deleted");
    }
    return Last;
}

struct Node* delete(struct Node* Last,int index){
    int length = len(Last);
    if(index<0){
        index += length;
    }
    if(index<0 || index == length){
        printf("this index %d cannot be removed.\n",index);
        return Last;
    }
    if(length == 1 && index==0){
        return NULL;
    }
    if(length==2){
        if(index == 0){
            Last->next = Last->next->next;
            Last = Last->next;
            Last->next = NULL;
        }
        if(index == 1){
            Last = Last->next;
            Last->next = NULL;
        }
        return Last;
    }
    // if length of linked list is more than 2
    struct Node* tmp = Last->next;
    if(index == 0){
        Last->next = Last->next->next;
    }
    for(int i = 0;i<index-1;i++){
        tmp = tmp->next;
    }
    // printf("%d\n",tmp->data);
    tmp->next = tmp->next->next;
    // printf("%d\n",tmp->data); 
    return Last;
}


int main(){
    struct Node* Last = (struct Node*)malloc(sizeof(struct Node*));
    Last = Create_(Last, 2);
    // display(Last);
    // Last = insert(Last, 0, 11);
    // Last = insert(Last, 1, 14);
    // Last = insert(Last, 2, 99);
    display(Last);
    Last = delete(Last,0);
    // Last = delete(Last, 2);
    // Last = delete(Last, 5);
    // Last = delete(Last, 0);
    // Last = delete(Last, 0);
    // Last = delete(Last, 3);
    display(Last);
    printf("the ln : %d", len(Last));
    return 0;
}

int main_(){
    //  creation of menu;
    int len_ll,val;
    printf("Creating circular linked list\nenter length of circular linked list : ");
    scanf("%d",&len_ll);
    struct Node* Last = malloc(sizeof(struct Node*));
    Last =  Create(Last ,len_ll);

    int option,exit_status = 0;
    // printf("%d\n",len(Last));
    do{
        printf("Select the below option:\n\n");
        printf("1.display the circular linked list\n");
        printf("2.insertion\n");
        printf("3.deletion\n");
        printf("4.length of circular linked list\n");
        printf("5.exit\n\nEnter Your option:");
        scanf("%d",&option);
        printf("\n--------------------------------------------------------------\n\n");
        int index,val;
        switch (option)
        {
        case 1:
            display(Last);
            break;
        case 2:
            printf("(for appending enter -1)\nEnter the index of inserting : ");
            scanf("%d",&index);
            printf("Ënter the value for inserting : ");
            scanf("%d",&val);
            Last = insert(Last,index,val);
            break;
        case 3:
            printf("(for pop enter -1)\nEnter the index of deletion : ");
            scanf("%d",&index);
            Last = delete(Last,index);
            break;
        case 4:
            printf("\nlength of linked list is %d\n",len(Last));
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