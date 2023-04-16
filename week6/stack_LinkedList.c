#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* stack = NULL;
int  top = -1;

struct Node* push(struct Node* stack, int val){
    if(stack == NULL){
        stack = (struct Node*)malloc(sizeof(struct Node*));
        stack->data = val;
        stack->next = NULL;
        top++;
    }
    else{
        struct Node* newTop = (struct Node*)malloc(sizeof(struct Node*));
        newTop->data = val;
        newTop->next = stack;
        stack = newTop;
        top++;
    }
    return stack;
}
void display(struct Node* stack){
    printf("\n----------------------------------------------------------\n");
    printf("--------------------------stack---------------------------\n");
    printf("----------------------------------------------------------\n\n");
    if(stack == NULL){
        printf("No Element in stack\n");
    }
    struct Node* tmp = stack;
    for(int i =0;i<=top;i++){
        printf("%d\n",tmp->data);
        tmp = tmp->next;
    }
    printf("\n----------------------------------------------------------\n");
    printf("----------------------------------------------------------\n\n");
}


int top_val(struct Node* stack){
    return stack->data;
}

struct Node* pop(struct Node* stack){
    if(top==-1){
        return NULL;
    }
    else{
        stack = stack->next;
        top--;
    }
    return stack;
}

struct Node* reverse(struct Node* stack){
    int val, h = -1;
    struct Node* rev = NULL;
    while(top!=-1){
        val = top_val(stack);
        rev = push(rev,val);
        stack = pop(stack);
        top--;
        h++;
    }
    top = h;
    stack = rev;
    return stack;
}

int main(){
    stack = push(stack,1);
    stack = push(stack,2);
    stack = push(stack,3);
    stack = push(stack,4);



    // printf("%d\n",top);
    display(stack);
    
    // stack = pop(stack);
    // stack = pop(stack);
    // stack = pop(stack);
    // stack = pop(stack);
    
    stack = reverse(stack);

    display(stack);
    return 0;
}