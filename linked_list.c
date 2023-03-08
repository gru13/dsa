#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

void display(struct Node *head){
    struct Node *tmp = head;
    while(tmp != NULL){
        printf("The value is : %d\n",tmp->value);
        tmp = tmp->next;
    }
}

int len(struct Node* head){
    struct Node *rmp = head;
    int length = 0;
    while(rmp != NULL){
        length++;
        rmp = rmp->next;
    }
    return length;
}
void insert(int index,int value,struct Node *head){
    int length = len(head);
    struct Node *tmp = head;
    struct Node *new = (struct Node*)malloc(sizeof(struct Node*));
    new->value = value;
    if (index > length || index < 0){printf("can't inserted due to lenght");}
    else{
        if(index == 0){
            new->next = tmp;
            head = new;
            display(head);
        }
        else if(index == length){
            while(tmp->next != NULL){
                tmp = tmp->next;
            }
            tmp->next = new;
            new->next = NULL;
        }
        else{
            for(int i = 0;i<index-1;i++){
                tmp = tmp->next;
            }
            printf("%d\n",tmp->value);
            new->next = tmp->next;
            tmp->next = new; 
            // display(head);
        }
    }
}
int main(){
    struct Node *head;
    
    
    /*
    */
    // struct Node *arr[10];

    // for(int i = 0; i<11;i++){
    //     arr[i] = (struct Node*)malloc(sizeof(struct Node*));
    // }
    // for(int i = 0; i<11;i++){
    //     arr[i]->value = i;
    //     if(i < h){arr[i]->next = arr[i+1];}
    //     else{arr[i]->next=NULL;}
    // }
    // head = arr[0];
    
    
    struct Node *first = (struct Node*) malloc(sizeof(struct Node*));
    struct Node *second = (struct Node*) malloc(sizeof(struct Node*));
    struct Node *third = (struct Node*) malloc(sizeof(struct Node*));

    head = first;
    first->value = 1;
    first->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = NULL;  
    
    insert(len(head),4,head);
    printf("\t%d\n",len(head));
    display(head);
}