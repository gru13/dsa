#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node* next;
    int data;
};

struct Node* node(int val){
    struct Node* N = (struct Node*)malloc(sizeof(struct Node));
    N->data = val;
    N->next = NULL;
    return N;
}
struct Queue
{
    int len;
    struct Node* queue;
    struct Node* fst;
    struct Node* lst;
};

struct Queue* create(int len){
    struct Queue* Q = (struct Queue*)malloc(sizeof(struct Queue));
    int val;
    Q->len = len;
    Q->queue = NULL;
    Q->fst = Q->queue;
    return Q;

}

void display(struct Queue* Q){
    struct Node* tmp = Q->queue;
    printf("\n-------------------------------");
    printf("\n------------Queue--------------\n");
    while(tmp!=NULL){
        printf(" %d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n-------------------------------\n");
    return;

}
struct Queue* enQueue(struct Queue* Q, int val){
    if(Q->len == 0){
        Q->len++;
        Q->queue = node(val);
        Q->fst = Q->queue;
        Q->lst = Q->fst;
        return Q;
    }
    Q->len++;
    Q->lst->next = node(val);
    Q->lst = Q->lst->next;
    return Q;
}

struct Queue* deQueue(struct Queue* Q){
    Q->len--;
    Q->queue = Q->queue->next;
    Q->fst = Q->queue;
    return Q;
}

int demo(){
    struct Queue* Q = create(5);
    display(Q);
    Q = enQueue(Q,22);
    display(Q);
    Q = deQueue(Q);
    display(Q);
    printf("%d",Q->queue->data);
}

int main(){
    //  creation of menu;
    int val;
    printf("Creating Queue : ");
    struct Queue* Q = create(0);

    int option,exit_status = 0;
    // printf("%d\n",len(Q));
    do{
        printf("Select the below option:\n\n");
        printf("1.display the Queue\n");
        printf("2.enQueue\n");
        printf("3.deQueue\n");
        printf("4.exit\n\nEnter Your option:");
        scanf("%d",&option);
        printf("\n--------------------------------------------------------------\n\n");
        int index,val;
        switch (option)
        {
        case 1:
            display(Q);
            break;
        case 2:
            printf("Enter the value for enQueue : ");
            scanf("%d",&val);
            Q = enQueue(Q,val);
            break;
        case 3:
            printf("deQueue\n");
            Q = deQueue(Q);
            break;
        case 4:
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