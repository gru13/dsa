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

struct CQ* insert(struct CQ* c, int val){
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
struct CQ* delete(struct CQ* c){
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
int main(){
    struct CQ* c = create(5);
    c = insert(c,0);
    c = insert(c,1);
    c = insert(c,2);
    c = insert(c,3);
    c = insert(c,4);
    c = insert(c,34564321);
    display(c);
    c = delete(c);
    c = delete(c);
    c = insert(c,232321);
    c = insert(c,888787);
    display(c);
    printf("\n%d,%d\n",c->first,c->last);
}