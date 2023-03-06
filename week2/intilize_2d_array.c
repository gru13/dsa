#include<stdio.h>

int main(){
    int i , j;
    printf("Pls enter no of row : ");
    scanf("%d",&i);
    printf("Pls enter no of col : ");
    scanf("%d",&j);
    
    int arr[i][j];

    for(int a = 0; a<i; a++){
        for(int b = 0; b<j; b++){
        printf("Ënter value of arr[%d][%d]", i,j);
        scanf("%d", &arr[a][b]);
        }
    }

    for(int a = 0; a<i; a++){
        for(int b = 0; b<j; b++){
        printf("Ënter value of %d\n", arr[a][b]);
        }
    }
    return 0;
}