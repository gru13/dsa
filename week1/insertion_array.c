#include<stdio.h>
#include<stdlib.h>

int* insert(int *arr, int len, int index,int val){
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
    free(arr);
    return arr1;

}

int main(){
    int l;
    printf("Enter the length of array :");
    scanf("%d", &l);

    int *arr = malloc(l*sizeof(int));
    int index, value;

    for(int i = 0 ;i<l;i++){
        printf("Enter the vslue of array[%d] : ",i);
        scanf("%d", &arr[i]);
    }
    arr = insert(arr,l,1,199);
    printf("%d\n",arr[2]);
    l++;
    printf("array after inserting :\n");
    for(int i = 0 ;i<l;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}