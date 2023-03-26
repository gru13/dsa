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
    printf("\n");
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

int** insert_row(int **arr,int row_del){
    int ** arr1 = create_empty(ROW-1,COL);
    for(int i = 0;i<ROW+1;i++){
        if(i<row_del){
            arr1[i] = arr[i];
        }
        else if(i == row_del){
            for(int j = 0;j<COL;j++){
                printf("Enter the valuee for index arr[%d][%d] : ",i,j);
                scanf("%d",&arr1[i][j]);
            }
        }
        else{
            arr1[i] = arr[i-1];
        }
    }
    ROW++;
    free(arr);
    return arr1;
}

int sum(int ** arr){
    int sum =0;
    for(int i =0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            sum += arr[i][j];
        }
    }
    return sum;
}


int** sort_row(int** arr){
    for(int i = 0;i<ROW;i++){
        for(int j = 0 ;j<ROW-i-1;j++){
            if(arr[j][0] > arr[j+1][0]){
                int *temp = arr[j];
                arr[j] = arr[j+1]; 
                arr[j+1] = temp; 
            }
        }
    }
    return arr;
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
    // arr = delete_row(arr,1);
    // arr = insert_row(arr,1);
    // printf("%d",sum(arr));
    arr = sort_row(arr);
    display(arr);



}