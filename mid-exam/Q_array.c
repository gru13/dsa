#include<stdio.h>
#include<stdlib.h>

int* Q = NULL;
int len = 0;

int* Enqueue(int val){
    len++;
    Q = (int*)realloc(Q, sizeof(int)*len);
    Q[len -1 ] = val;
    return Q;
}

int* DEqueue(){
    if(len == 0 && len == 1){
        if(len == 1){
            len--;
        }
        return NULL;
    }
    len--;
    int* arr = (int*)malloc(sizeof(int)*len);
    for(int i = 0;i<len;i++){
        arr[i] = Q[i+1];
    } 

    Q = arr;
    return Q;
}

void display(){
    printf("\nQ:\n");
    for(int i = 0;i<len;i++){
        printf("%d -> ", Q[i]);
    }
    printf("\n");
    return;
}

int main(){
    Q = Enqueue(0);
    Q = Enqueue(1);
    Q = Enqueue(2);
    Q = Enqueue(3);
    display();
    Q = DEqueue();
    // Q = DEqueue();
    display();
}