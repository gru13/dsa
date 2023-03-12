#include<stdio.h>

int search(int val, int arr[] ,int len){
    for(int i = 0;i<len;i++){
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[] ={1,2,3,4,5,6,9};
    int index = search(2, arr,7);
    printf("%d",index);
}