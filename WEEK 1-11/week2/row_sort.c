#include<stdio.h>


void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void sort(int len, int arr[]){
    
}

int main(){
    
    int row, col;
    printf("enter the value row : ");
    scanf("%d", &row);
    printf("enter the value col : ");
    scanf("%d", &col);
    
    int arr[row][col];
    for(int i = 0; i<row;i++){
        for(int j = 0; j<col; j++){
            printf("enter the value for arr[%d][%d] : ", i,j);
            scanf("%d", &arr[row][col]);
        }
    }



    for(int i = 0; i<row;i++){
        for(int j = 0; j<col; j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}