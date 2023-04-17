#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int top;
    int* stack; 
};

struct charStack{
    int top;
    char* stack; 
};




struct charStack* push(struct charStack* Stack,int val){
    Stack->top++;
    char* nw = (char*)malloc(sizeof(int)*(1+Stack->top));
    for(int i = 0;i <= Stack->top;i++){
        if(i == 0){
            nw[0]=val;
        }
        else{
            nw[i] = Stack->stack[i-1];
        }
    }
    Stack->stack = nw;
    nw = NULL;

    return Stack;
}


struct charStack* pop(struct charStack* Stack){
    if(Stack->top == -1){
        printf("\nNO ELEMENT TO POP\n");
    }
    else{
        char* nw  = (char*)malloc(sizeof(char*)*(Stack->top-1));
        for(int i = 0;i <= Stack->top-1;i++){
            nw[i] = Stack->stack[i+1];
            // printf("\n%d\n",stack[i+1]);
        }
        Stack->stack = nw;
        Stack->top--;
        nw = NULL;
    }
    return Stack;
}


void display(struct charStack* Stack){
    printf("\n----------------------------------------------------------\n");
    printf("--------------------------stack---------------------------\n");
    printf("----------------------------------------------------------\n\n");
    if(Stack->top == -1){
        printf("No Element in stack\n");
    }
    for(int i = 0;i<=Stack->top;i++){
        printf("%c\n",Stack->stack[i]);
    }
    printf("\n----------------------------------------------------------\n");
    printf("----------------------------------------------------------\n\n");
}

char top_val(struct charStack* Stack){
    return Stack->stack[0];
}


int top_int(struct charStack* Stack){
    int val = 0;
    int i = 0;
    while(i <= Stack->top && Stack->stack[i]>=48 && Stack->stack[i]<=57){
        val *= 10;
        val += Stack->stack[i]-48;
        i++;
    }
    return val;
}

// struct charStack* reverse(struct charStack* Stack){
//     struct charStack* rev;
//     // display(stack);
//     while(Stack->top != -1){
//         rev = push(rev,top_val(Stack));
//         Stack = pop(Stack);
//         Stack->top--;
//         rev->top++;
//     }
//     return rev;
// }

int main(){
    struct charStack* stack = (struct charStack*)malloc(sizeof(struct charStack*));
    stack->stack = NULL;
    stack->top = -1;
    printf("-------------------------------");               

    stack = push(stack,'1');
    stack = push(stack,'-');
    stack = push(stack,'2');
    stack = push(stack,'3');
    display(stack);
    // printf("\n%d\n",top_int(stack));
}