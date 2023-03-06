#include<stdio.h>
#include<stdlib.h>

void insert(int *arr, int len, int index,int val){
    int *arr1 = malloc((len+1)*sizeof(int));
    int o = index;
    for(int i=0; i<len+1;i++){
        // puts("huh\n");
        if(i<index){
            arr1[i] = arr[i];
        }
        else if (i>index)
        {
            arr1[i] = arr[o];
            o++;
        }
        else
        {
            arr1[index] = val;
        }
    }
    for(int i = 0 ;i<len+1;i++){
        printf("Enter the length of array: %d\n",arr1[i]);
    }
    free(arr);
    arr = arr1;
    arr1 = NULL;

}

int main(){
    int l;
    printf("Enter the length of array :");
    scanf("%d", &l);

    int *arr = malloc(l*sizeof(int));
    int index, value;

    for(int i = 0 ;i<l;i++){
        printf("Enter the length of array[%d] : ",i);
        scanf("%d", &arr[i]);
    }
    insert(arr,l,0,199);
    printf("%d\n",arr[0]);
    return 0;
}