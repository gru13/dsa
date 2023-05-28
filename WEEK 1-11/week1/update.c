#include<stdio.h>
void update(int *arr,int index,int val){
    *(arr+index) = val;
}
int main(){
    int arr[] ={1,2,3,4,5,6,9};
    update(&arr,6,7);
    for(int i =0;i<7;i++){
        printf("%d\t",arr[i]);
    }
}