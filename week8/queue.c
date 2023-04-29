#include<stdio.h>
#include<stdlib.h>

struct  Queue
{
    int top;
    int* queue;
};

struct Queue* create(){
    struct Queue* Q = (struct Queue*)malloc(sizeof(struct Queue*));
    Q->queue = NULL;
    Q->top = -1;
    return Q;
}

void display(struct Queue* Q){
    printf("\n-------queue-int----------\n");
    printf("--------------------------\n");
    for(int i =0;i<=Q->top;i++){
        printf(" %d ->",Q->queue[i]);
    }
    printf("\n--------------------------\n");
}


struct Queue* enQueue(struct Queue* Q, int val){
    Q->top++;
    if(Q->top == 0){
        Q->queue = (int*)malloc(sizeof(int*)*(Q->top+1));
        Q->queue[0] = val;
    } else {
        int* nw = (int*)malloc(sizeof(int*)*(Q->top+1));
        for (int i = 0; i <= Q ->top; i++)
        {
            if(i == Q->top){
                nw[i] = val;
                continue;
            }
            nw[i] = Q->queue[i];
        }
        Q->queue = nw;
    }
    return Q;
}

struct Queue* deQueue(struct Queue* Q){
    Q->top--;
    if(Q->top == -1){
        Q->queue=NULL;
    } else {
        int* nw = (int*)malloc(sizeof(int*)*(Q->top));
        for (int i = 1; i <= Q ->top+1; i++)
        {
            nw[i-1] = Q->queue[i];
        }
        Q->queue = nw;
    }
    return Q;
}

int top(struct Queue* Q){
    if(Q->top == -1){return 0;}
    return Q->queue[0];
}

struct Queue* reverse(struct Queue* Q){
    int* rev = (int*)malloc(sizeof(int*)*(Q->top+1));
    int j =0;
    for(int i = Q->top-1;i>=0;i--){
        rev[j] = Q->queue[i];
        printf(" %d ---%d --- %d\n",Q->queue[i],rev[j],j);
        j++;
    }   
    Q->queue = rev;
    return Q;
}
int main(){
    struct Queue* Q = create();
    Q = enQueue(Q,1);
    Q = enQueue(Q,2);
    Q = enQueue(Q,3);
    Q = enQueue(Q,4);
    // display(Q);
    // Q = deQueue(Q); 
    display(Q);
    Q = reverse(Q);
    display(Q);
}