#include<stdio.h>
#include<stdlib.h>

int size  = 0;
int arr[100000];

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
    return;
}
void heapify(int i){
    if(size == 1){
        return;
    }
    int largest = i;
    int left = i*2+1;
    int ryt = i*2+2;
    if(left < size && arr[left]>arr[largest]){
        largest = left;
    }
    if(ryt < size && arr[ryt]>arr[largest]){
        largest = ryt;
    }
    if(largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(largest);
    }
}

void insert(int data){
    arr[size] = data;
    size++;
    for(int i = size/2-1;i>=0;i--){
        heapify(i);
    }
}

void delete(int data){
    for(int i = 0 ;i<size;i++){
        if(arr[i]==data){
            swap(&arr[i], &arr[size-1]);
            size--;
            for(int i = size/2-1;i>=0;i--){
                heapify(i);
            }
            break;
        }
    }
}
void heapSort(){
    for(int i = size/2-1;i>=0;i--){
        heapify(i);
    }
    int len = size;
    for(int i = size-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        size--;
        heapify(0);
    }
    size = len;

}
void printArray(){
    printf("\n");
    for(int i =0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("\n");
    return;
}
int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(10);
    // heapSort();
    printArray();
}