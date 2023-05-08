#include<stdio.h>
#include<stdlib.h>

struct DQ
{
    int front;
    int last;
    int n_ele;
    int* q;
    int MAX;
};

int inRange(int f, int e, int i){
    if(f<=e){
        if(f<=i && i<=e){
            return 1;
        }
        else{return 0;}
    }
    return 0;
}
struct DQ* create(int max){
    struct DQ* D = (struct DQ*)malloc(sizeof(struct DQ*));
    D->front = -1;
    // printf("asdfghjkl;");
    D->last = -1;
    D->n_ele = 0;
    D->q = (int*)malloc(sizeof(int*)*max);
    // printf("\n%d---%d--%d\n",D->MAX,D->front,D->last);
    D->MAX = max;
    return D;
}

void display(struct DQ* D){
    printf("\n");
    for(int i = 0;i<D->MAX;i++){
        if(inRange(D->front, D->last, i) == 1 || D->MAX == D->n_ele){
        // if(1){
            printf(" %d ->",D->q[i]);
            // cur--;
        } else {
            printf(" NULL ->");
        }
    }
    printf("\n");
    return;
}
struct DQ* add_end(struct DQ* D,int val){
    if (D->n_ele < D->MAX)
    {   
        if(D->n_ele == 0){
            D->front++;
            D->last++;
        } else {
            D->last = (D->last + 1) % D->MAX;
        }
        D->q[D->last] = val;
        D->n_ele++;
    }
    return D;
}
struct DQ* add_start(struct DQ* D,int val){
    if (D->n_ele < D->MAX)
    {   
        if(D->n_ele == 0){
            D->front++;
            D->last++;
        } else {
            int index = D->front -1;
            if(index < 0){
                index = D->MAX + index;
                index = index % D->MAX;
            }
            D->front = index;
        }
        D->q[D->front] = val;
        D->n_ele++;
    }
    return D;
}

struct DQ* remove_start(struct DQ* D){
    if(D->n_ele>0){
        
        D->q[D->front] = 0;
        int index = D->front + 1;
        index = index % D->MAX;
        D->front = index;
        D->n_ele--;
    }
    if(D->n_ele == 0){
        D->front == -1;
        D->last == -1;
    }
    return D;
}

struct DQ* remove_end(struct DQ* D){
    if(D->n_ele>0){
        D->q[D->last] = 0;
        int index = D->last - 1;
        if(index < 0){
            index = index + D->MAX;
            index = index % D->MAX;
        }
        index = index % D->MAX;
        D->last = index;
        D->n_ele--;
        if(D->n_ele == 0){
            D->front == -1;
            D->last == -1;
        }
        if(D->n_ele == 0){
            D->front == -1;
            D->last == -1;
        }
    }
    return D;
}
int main(void){
    struct DQ* D = create(5);
    D = add_start(D,4);
    D = add_end(D,1);
    D = add_end(D,2);
    D = add_end(D,3);
    D = remove_start(D);
    D = add_end(D,4);
    D = add_end(D,5);
    display(D);
}