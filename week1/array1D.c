#include<stdio.h>
#include<stdlib.h>

void  Create(int *arr,int len){
    for(int i = 0;i<len;i++){
        printf("Enter the value at index %d : ",i);
        scanf("%d",arr+i);
    }
    // return arr;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void display(int arr[],int len){
    printf("\n");
    for(int i = 0; i<len;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}


int* insert(int *arr,int len,int index,int val){
    if(index>len || index<0){
        return NULL;
    }
    (len)++;
    int *arr1 = (int*)malloc(sizeof(int*)*(len));
    for(int i = 0;i<index;i++){
        *(arr1+i) = *(arr + i);
    }
    *(arr1 + index) = val;
    for(int i = index+1;i<len;i++){
        *(arr1+i) = *(arr+i-1); 
    }
    arr = arr1;
    return arr;
}

int* delete(int *arr,int len,int index){
    if(index>len || index<0){
        return NULL;
    }
    len--;
    int *arr1 = (int*)malloc(sizeof(int*)*(len));
    for(int i = 0;i<index;i++){
        *(arr1+i) = *(arr + i);
    }
    for(int i = index;i<len;i++){
        *(arr1+i) = *(arr+i+1); 
    }
    arr = arr1;
    return arr;
}
int* sort(int* arr, int len){
    for(int i = 0; i<len; i++){
	   for(int j = 0; j<len-i; j++){
		 if(*(arr+j)>*(arr+j+1)){
			 swap((arr+j),(arr+j+1));
		 }	
	   }
    }
    return arr;
}



int main(){
    int len;
    printf("Enter the length of array : ");
    scanf("%d", &len);
    int *arr = (int*)malloc(sizeof(int*)*len);
    Create(arr,len);
    display(arr,len);
    // arr = insert(arr,len,0,11);
    // len++;
    // display(arr,len);
    // arr = delete(arr,len,5);
    // len--;
    // display(arr,len);
    arr  = sort(arr,len);
    display(arr,len);



}