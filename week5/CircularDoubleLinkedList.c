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
int main(){
    struct CDL* cdl =  Create_(5);
    display(cdl);
    cdl = insert(cdl ,0,222);
    display(cdl);
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