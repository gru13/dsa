#include<stdio.h>
#include<stdlib.h>

struct CQ
{
    int MAX;
    int first;
    int last;
    int n_ele;
    int* queue;
};

struct CQ* create(int max){
    struct CQ* cq = (struct CQ*)malloc(sizeof(struct CQ));
    cq->first = -1;
    cq->last = -1;
    cq->n_ele = 0;
    cq->MAX = max;
    cq->queue = (int*)malloc(sizeof(int)*cq->MAX);
    return cq;
}

struct CQ* enQueue(struct CQ* c, int val){
    if(c->n_ele==c->MAX){
        return c;
    }
    c->n_ele++;
    if(c->n_ele == 1){
        c->last = 0;
        c->first = 0;
        c->queue[0] = val;
    } else {
        c->last++;
        if(c->last>=c->MAX){
            c->last %= c->MAX; 
        }
        c->queue[c->last] = val;
    }
    return c;
}
struct CQ* deQueue(struct CQ* c){
    if(c->n_ele == 0){
        return c;
    }
    c->n_ele--;
    if(c->n_ele == 0){
        c->first = -1;
        c->last = -1;
    } else{
        c->first++;
        if(c->first>=c->MAX){
            c->first %= c->MAX;
        }
    }
    return c;
}
void display(struct CQ* c){
    int i = c->first;
    int m = c->n_ele;
    printf("\n");
    while (m!=0)
    {
        printf("%d -> ",c->queue[i]);
        i++;
        i%=c->MAX;
        m--;
    }
    printf("\n");
    return;
}
int demo(){
    struct CQ* c = create(5);
    c = enQueue(c,0);
    c = enQueue(c,1);
    c = enQueue(c,2);
    c = enQueue(c,3);
    c = enQueue(c,4);
    c = enQueue(c,34564321);
    display(c);
    c = deQueue(c);
    c = deQueue(c);
    c = enQueue(c,232321);
    c = enQueue(c,888787);
    display(c);
    printf("\n%d,%d\n",c->first,c->last);
}

int main(){
    //  creation of menu;
    int val,len;
    printf("Creating Queue , Enter max Length: ");
    scanf("%d",&len);
    struct CQ* Q = create(len);

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