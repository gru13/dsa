#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int top;
    char* stack;
};

struct Stack* create(){
    struct Stack* S = (struct Stack*)malloc(sizeof(struct Stack*));
    S->stack = NULL;
    S->top = -1;
    return S;
}

void display(struct Stack* stack){
    printf("\n----------stack-----------\n");
    printf("--------------------------\n");
    for(int i =0;i<=stack->top;i++){
        printf("%c->",stack->stack[i]);
    }
    printf("\n--------------------------\n");
}


char top(struct Stack* S){
    if(S->top==-1){return '\0';}
    return S->stack[0];
}
struct Stack* push(struct Stack* stack, char val){
    if(stack->top==-1){
        stack->top++;
        stack->stack = (char*)malloc(sizeof(char)*stack->top+1);
        stack->stack[0] = val;
    } else {
        stack->top++;
        char* k = (char*)malloc(sizeof(char)*stack->top+1);
        for(int i = 1;i<=stack->top;i++){
            k[i] = stack->stack[i-1];
        }
        k[0] = val;
        stack->stack = k;
    }
    return stack;
}


struct Stack* pop(struct Stack* S){
    if(S->top == -1){
        return NULL;
    }
    if(S->top == 0){
        S->top--;
        S->stack = NULL;
    } else {
        S->top--;
        char* k = (char*)malloc(sizeof(char)*S->top+1);
        for(int i = 0;i<=S->top;i++){
            k[i] = S->stack[i+1];
        }
        S->stack = k;
    }
    return S;
}



struct Stack* reverse(struct Stack* S){
    struct Stack* rev = create();
    while(S->top>=0){
        char val = top(S);
        rev = push(rev,val);
        S = pop(S);
    }
    free(S);
    return rev;
}


int main(){
    struct Stack* S = create();
    S = push(S,'1');
    S = push(S,'2');
    S = push(S,'3');
    S = push(S,'4');
    display(S);
    // printf("%c\n",top(S));
    // S = pop(S);
    S = reverse(S);
    display(S);
}