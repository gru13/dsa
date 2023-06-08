#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
    D->last = -1;
    D->n_ele = 0;
    D->q = (int*)malloc(sizeof(int*)*max);
    // D->q[max];
    for(int i=0;i<max;i++){
        D->q[i] = INT_MAX;
    }
    // printf("\n%d---%d--%d\n",D->MAX,D->front,D->last);
    D->MAX = max;
    return D;
}

void display(struct DQ* D){
    printf("\n");
    for(int i = 0;i<D->MAX;i++){
        if(D->q[i] != INT_MAX){
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
        
        D->q[D->front] = INT_MAX;
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
        D->q[D->last] = INT_MAX;
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
int demo(void){
    struct DQ* D = create(5);
    D = add_start(D,4);
    printf("\n--%d--\n");
    // D = add_end(D,1);
    // D = add_end(D,2);
    // D = add_end(D,3);
    // D = remove_start(D);
    // D = add_end(D,4);
    // D = remove_start(D);
    // D = remove_start(D);
    // D = remove_start(D);
    // D = add_end(D,5);
    display(D);
}
int main() {
    int len;
    printf("Creating Deque, Enter max Length: ");
    scanf("%d", &len);
    struct DQ* D = create(len);

    int option, exit_status = 0;
    do {
        printf("Select the below option:\n\n");
        printf("1. Display the Deque\n");
        printf("2. Add element at the front\n");
        printf("3. Add element at the end\n");
        printf("4. Remove element from the front\n");
        printf("5. Remove element from the end\n");
        printf("6. Exit\n\nEnter Your option: ");
        scanf("%d", &option);
        printf("\n--------------------------------------------------------------\n\n");

        int val;
        switch (option) {
            case 1:
                display(D);
                break;
            case 2:
                printf("Enter the value to add at the front: ");
                scanf("%d", &val);
                D = add_start(D, val);
                break;
            case 3:
                printf("Enter the value to add at the end: ");
                scanf("%d", &val);
                D = add_end(D, val);
                break;
            case 4:
                printf("Removing element from the front\n");
                D = remove_start(D);
                break;
            case 5:
                printf("Removing element from the end\n");
                D = remove_end(D);
                break;
            case 6:
                printf("Exiting...\n");
                exit_status = 1;
                break;
            default:
                printf("Enter a valid option\n");
                break;
        }
        printf("\n--------------------------------------------------------------\n\n");
    } while (exit_status != 1);

    return 0;
}
