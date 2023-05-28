#include<stdio.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
    int len;
    printf("enter the lenght of array : ");
    scanf("%d",&len);
    int arr[len];
    for(int i = 0; i<len;i++){
	    printf("enter value of arr[%d] : ",i);
	    scanf("%d", &arr[i]);
    }
    for(int i = 0; i<len; i++){
	   for(int j = 0; j<len-i; j++){
		 if(arr[j]>arr[j+1]){
			 swap(&arr[j],&arr[j+1]);
		 }	
	   }
    } 
    for(int i = 0; i<len;i++){
	   printf("%d\n",arr[i]);
    } 
    return 0;
}
