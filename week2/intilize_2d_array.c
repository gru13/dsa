#include<stdio.h>
#include<stdlib.h>

int ROW;
int COL;
int **create(int i, int j) {
    int **arr = malloc(i * sizeof(int *));
    for (int a = 0; a < i; a++) {
        arr[a] = malloc(j * sizeof(int));
        for (int b = 0; b < j; b++) {
            printf("Enter value of arr[%d][%d]: ", a, b);
            scanf("%d", &arr[a][b]);
        }
    }
    return arr;
}
int **create_empty(int i, int j) {
    int **arr = malloc(i * sizeof(int *));
    for (int a = 0; a < i; a++) {
        arr[a] = malloc(j * sizeof(int));
    }
    return arr;
}


void display(int** arr){
    for(int i =0; i<ROW;i++){
        for(int j = 0;j<COL;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int** delete(int**arr,int row, int col){
    arr[row][col] = 0;
    return arr;
}

int** update(int**arr,int row, int col, int val){
    arr[row][col] = val;
    return arr;
}

int** delete_row(int **arr,int row){
    int ** arr1 = create_empty(ROW-1,COL);
    for(int i =0;i<ROW;i++){
        if(i<row){
            arr1[i] = arr[i];
        }
        if(i>row){
            arr1[i-1] = arr[i];
        }
    }
    ROW--;
    free(arr);
    return arr1;
}

int** insert_row(int **arr,int row){
    int** arr1 = create_empty(ROW+1,COL);
    for(int i = 0;i>ROW;i++){
        if(i<row){
            arr1[i] = arr1[i]; 
        }
        else if
    }
    ROW++;
    free(arr);
    return arr1;
}


int main(){
    int i , j;

    printf("Enter no of row : ");
    scanf("%d",&ROW);
    printf("Enter no of col : ");
    scanf("%d",&COL);

    int **arr = create(ROW,COL);
    display(arr);
    // arr = delete(arr,1,1);
    // display(arr);
    // arr = update(arr,1,1,999);
    arr = delete_row(arr,1);
    display(arr);



}