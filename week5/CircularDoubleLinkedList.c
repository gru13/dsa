#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct CDL
{
    struct Node* Last;
    int len;
};

struct Node* node(int val){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->prev = NULL;
    n->next = NULL;
    return n;
}
struct CDL* Create(int len){
    struct CDL* ll = (struct CDL*)malloc(sizeof(struct CDL));
    ll->len = len;
    ll->Last = NULL;
    if(len==0){return ll;}
    struct Node* head = node(0);
    struct Node* tmp = head;
    for(int i = 0;i<len;i++){
        int va = 0;
        printf("Enter the value of the index %d : ",i);
        scanf("%d",&va);
        tmp->data = va;
        if(i!=len-1){
            tmp->next = node(0);
            tmp->next->prev= tmp;
        }
        else{
            ll->Last = tmp;
            head->prev = ll->Last;
            ll->Last->next = head;
        }
        tmp = tmp->next;
    }
    return ll;  
}
struct CDL* Create_(int len){
    struct CDL* ll = (struct CDL*)malloc(sizeof(struct CDL));
    ll->len = len;
    ll->Last = NULL;
    if(len==0){return ll;}
    struct Node* head = node(0);
    struct Node* tmp = head;
    for(int i = 0;i<len;i++){
        tmp->data = i+1;
        if(i!=len-1){
            tmp->next = node(0);
            tmp->next->prev= tmp;
        }
        else{
            ll->Last = tmp;
            head->prev = ll->Last;
            ll->Last->next = head;
        }
        // printf("%d -> ",tmp->data);
        tmp = tmp->next;
    }
    return ll;  
}

void display(struct CDL* cdl){
    
    if(cdl->len == 0){
        printf("\n||<-null->||\n");
        return;
    }
    if(cdl->len == 1){
        printf("\n||<-> %d <->||\n",cdl->Last->data);
        return; 
    }

    struct Node* tmp = cdl->Last->next;
    printf("\n||<-> ");
    for(int i = 0;i<cdl->len;i++){
        printf("%d <-> ",tmp->data);
        tmp = tmp->next;
    }
    printf("||\n");
    return;
}

void display_reverse(struct CDL* cdl){
    
    struct Node* last = cdl->Last;
    if( last == NULL){
        printf("\n||<-null->||\n");
        return;
    }
    if(last->next == NULL || last == last->next){
        printf("\n||<-> %d <->||\n",last->data);
        return; 
    }

    struct Node* tmp = last;
    printf("\n||<-> ");
    for(int i = 0;i<cdl->len;i++){
        printf("%d <-> ",tmp->data);
        tmp = tmp->prev;
    }
    printf("||\n");
    return;
}

struct CDL* insert(struct CDL* cdl, int index, int val){
    if(index<0){
        index += cdl->len;
    }
    if(index < 0 || index >= cdl->len){
        return cdl;
    }
    struct Node* n = node(val);
    if(index == 0 || index == cdl->len-1){
        n->next = cdl->Last->next;
        n->prev = cdl->Last;
        cdl->Last->next->prev = n;
        cdl->Last->next = n;
        cdl->len++;
        if(index != 0){
            int t = cdl->Last->data;
            cdl->Last->data = cdl->Last->next->data;
            cdl->Last->next->data = t;
            cdl->Last = cdl->Last->next;
        }
        return cdl;
    } else {
        struct Node* tmp = cdl->Last->next;
        for(int i = 0;i<index-1;i++){tmp = tmp->next;}
        n->next = tmp->next;
        n->prev = tmp->prev;
        tmp->next->prev = n;
        tmp->next = n;
        cdl->len++;
        return cdl;
    }
}

struct CDL* delete(struct CDL* cdl,int index){
    if(index < 0){
        index += cdl->len;
    }
    if(index<0||index>cdl->len){return cdl;}

    if(index == 0){
        cdl->Last->next = cdl->Last->next->next;
        cdl->Last->next->prev = cdl->Last; 
    }
    return cdl;
}


int main(){
    //  creation of menu;
    int len_ll,val;
    printf("Creating circular linked list\nenter length of circular linked list : ");
    scanf("%d",&len_ll);
    struct CDL* Last = Create(len_ll);

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
            printf("\nlength of linked list is %d\n", Last->len);
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


/*
---------------------extra--snipets-----------------------
    // printf("\n%d",last->Last->data);
-------------print--front---------------------------------
    tmp = ll->Last->next; // tmp:rtype->struct Node* ,ll->CDL
    for(int i = 0;i<len;i++){
        printf("%d -> ",tmp->data);
        tmp = tmp->next; 
    }
    printf("\n");

-------------print--back---------------------------------
    tmp = ll->Last;
    for(int i = 0;i<len;i++){
        printf("%d -> ",tmp->data);
        tmp = tmp->prev; 
    }
----------------------------------------------------------
    // display_reverse(cdl);
*/