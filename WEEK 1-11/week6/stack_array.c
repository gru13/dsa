#include<stdio.h>
#include<stdlib.h>

int *stack;
int top = -1;


int* push(int* stack,int val){
    if(top == -1){
        top++;
        stack = (int*)malloc(sizeof(int)*(1+top));
        stack[0] = val;
    }
    else{
        top++;
        int* nw = (int*)malloc(sizeof(int)*(1+top));
        for(int i = 0;i<=top;i++){
            if(i == 0){
                nw[0]=val;
            }
            else{
                nw[i] = stack[i-1];
            }
        }
        stack = nw;
        nw = NULL;
    }
    return stack;
}
int* push_(int* stack,int val,int top){
    if(top == -1){
        top++;
        stack = (int*)malloc(sizeof(int)*(1+top));
        stack[0] = val;
    }
    else{
        top++;
        int* nw = (int*)malloc(sizeof(int)*(1+top));
        for(int i = 0;i<=top;i++){
            if(i == 0){
                nw[0]=val;
            }
            else{
                nw[i] = stack[i-1];
            }
        }
        stack = nw;
        nw = NULL;
    }
    return stack;
}

int* pop(int* stack){
    if(top == -1){
        printf("\nNO ELEMENT TO POP\n");
    }
    else{
        int* nw  = (int*)malloc(sizeof(int*)*(top-1));
        for(int i = 0;i<=top-1;i++){
            nw[i] = stack[i+1];
            // printf("\n%d\n",stack[i+1]);
        }
        stack = nw;
        top--;
        nw = NULL;
    }
    return stack;
}
int* pop_(int* stack, int top){
    if(top == -1){
        printf("\nNO ELEMENT TO POP\n");
    }
    else{
        int* nw  = (int*)malloc(sizeof(int*)*(top-1));
        for(int i = 0;i<=top-1;i++){
            nw[i] = stack[i+1];
            // printf("\n%d\n",stack[i+1]);
        }
        stack = nw;
        top--;
        nw = NULL;
    }
    return stack;
}



void display(int* stack){
    int d = 0;
    if(top == -1){
        printf("NONE\n");
    }
    printf("\n");
    for(int i = top;i>=0;i--){
        printf("%d\t", stack[d]);
        d++;
    }
    printf("\n");
}

int top_val(int* stack){
    return stack[0];
}

int* reverse(int* stack){
    int* rev;
    int va,h = -1;
    // display(stack);
    while(top != -1){
        va = top_val(stack);
        rev = push_(rev, va, h); 
        h++;
        stack = pop(stack);
        
    }
    stack = rev;
    top = h;
    return stack;
}

int demo(){
    stack = push(stack,5);
    stack = push(stack,4);
    stack = push(stack,3);
    stack = push(stack,2);
    stack = push(stack,1);

    // printf("%d\n", pop_val(stack));
    // display(stack);
    // stack = pop(stack);
    // display(stack);
    // stack = pop(stack);
    // display(stack);
    // stack = pop(stack);
    // display(stack);
    // stack = pop(stack);
    // display(stack);
    // printf("%d", top_val(stack));
    display(stack);
    stack = reverse(stack);
    display(stack);
    // stack = push(stack, 7); 
    // stack = push(stack, 6); 
    // stack = push(stack, 9);
    // display(stack); 
    // return 0;
}

int main(){
    //  creation of menu;
    int val;
    printf("Creating stack: ");

    int option,exit_status = 0;
    // printf("%d\n",len(stack));
    do{
        printf("Select the below option:\n\n");
        printf("1.display the stack\n");
        printf("2.push\n");
        printf("3.pop\n");
        printf("4.exit\n\nEnter Your option:");
        scanf("%d",&option);
        printf("\n--------------------------------------------------------------\n\n");
        int index,val;
        switch (option)
        {
        case 1:
            display(stack);
            break;
        case 2:
            printf("Enter the value for push : ");
            scanf("%d",&val);
            stack = push(stack,val);
            break;
        case 3:
            printf("POP");
            stack = pop(stack);
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