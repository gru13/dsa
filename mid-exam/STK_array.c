#include<stdio.h>
#include<stdlib.h>

int* stack = NULL;
int len = 0;

int* push(int val){
    len++;
    int* new_arr = (int*)malloc(sizeof(int)*len);
    for(int i = 0;i<len-1;i++){
        new_arr[i] = stack[i];
    }
    new_arr[len-1] = val;
    stack = new_arr;
    return stack;
}

int* pop(){
    if(len == 0 || len == 1){
        if(len == 1){
            len--;
        }
        return NULL;
    }
    len--;
    int* arr = (int*)malloc(sizeof(int)*len);
    for(int i = 0;i<len;i++){
        arr[i] = stack[i];   
    }
    stack = arr;
    return stack;
}

int peak(){
    return stack[len-1];
}
void display(){
    printf("\nSTK: \n");
    for(int i = len -1;i>=0;i--){
        printf("%d ->", stack[i]);
    }
    printf("\n");
}
int main(){
    int* stack;
    stack = push(0);
    stack = push(1);
    stack = push(2);
    stack = push(3);
    display();
    stack = pop();
    display();
    stack = pop();
    display();
}