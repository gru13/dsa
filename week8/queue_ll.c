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
    Q->len = len;
    Q->queue = node(0);
    Q->fst = Q->queue;
    struct Node* head = Q->queue;
    for(int i =0;i<len;i++){
        head->data = i; 
        if(i!=len-1){
            head->next = node(0);
        } else {
            Q->lst = head;
        }
        head = head->next;
    }
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

int main(){
    struct Queue* Q = create(5);
    display(Q);
    Q = enQueue(Q,22);
    display(Q);
    Q = deQueue(Q);
    display(Q);
    printf("%d",Q->queue->data);
}