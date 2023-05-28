#include<stdio.h>
void display(int arr[],int length){
    for(int i = 0;i<length;i++){
        printf("%d\t",arr[i]);
    }
}
int main(){
    int arr[] ={1,2,3,4,5,6,9};
    display(arr,7);
}