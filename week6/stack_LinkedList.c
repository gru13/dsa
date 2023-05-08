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
    printf("--------------------------stack---------------------------\n\n");
    if(stack == NULL){
        printf("No Element in stack\n");
    }
    struct Node* tmp = stack;
    for(int i =0;i<=top;i++){
        printf("%d\n",tmp->data);
        tmp = tmp->next;
    }
    printf("\n----------------------------------------------------------\n");
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

int demo(){
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