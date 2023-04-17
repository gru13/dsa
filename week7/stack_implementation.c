#include<stdio.h>
#include<stdlib.h>

char* stack;
int top = -1;


char* push(char* stack,int val){
    if(top == -1){
        top++;
        stack = (char*)malloc(sizeof(int)*(1+top));
        stack[0] = val;
    }
    else{
        top++;
        char* nw = (char*)malloc(sizeof(int)*(1+top));
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
char* push_(char* stack,int val,int top){
    if(top == -1){
        top++;
        stack = (char*)malloc(sizeof(int)*(1+top));
        stack[0] = val;
    }
    else{
        top++;
        char* nw = (char*)malloc(sizeof(int)*(1+top));
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

char* pop(char* stack){
    if(top == -1){
        printf("\nNO ELEMENT TO POP\n");
    }
    else{
        char* nw  = (char*)malloc(sizeof(char*)*(top-1));
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
char* pop_(char* stack, int top){
    if(top == -1){
        printf("\nNO ELEMENT TO POP\n");
    }
    else{
        char* nw  = (char*)malloc(sizeof(char*)*(top-1));
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



void display(char* stack){
    int d = 0;
    if(top == -1){
        printf("NONE\n");
    }
    printf("\n");
    for(int i = top;i>=0;i--){
        printf("%c\t", stack[d]);
        d++;
    }
    printf("\n");
}

char top_val(char* stack){
    return stack[0];
}


int top_int(char* stack){
    int val = 0;
    int i = 0;
    while(i<=top && stack[i]>=48 && stack[i]<=57){
        val *= 10;
        val += stack[i]-48;
        i++;
    }
    return val;
}

char* reverse(char* stack){
    char* rev;
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

int main(){
    stack = push(stack,'1');
    stack = push(stack,'-');
    stack = push(stack,'2');
    stack = push(stack,'3');
    display(stack);
    printf("\n%d\n",top_int(stack));
}