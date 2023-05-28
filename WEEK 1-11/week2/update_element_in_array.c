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
        printf("Ënter value of arr[%d][%d]", a,b);
        scanf("%d", &arr[a][b]);
        }
    }
    // asking which index to change element to change 
    int index1, index2, value;
    printf("Ënter indexs : ");
    scanf("%d %d",index1, index2);

    // asking which value to change element to change 
    int index1, index2;
    printf("Ënter value : ");
    scanf("%d",value);

    arr[index1][index2] = value;

    for(int a = 0; a<i; a++){
        for(int b = 0; b<j; b++){
        printf("Ënter value of %d\n", arr[a][b]);
        }
    }
    return 0;
}