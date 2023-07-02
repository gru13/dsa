#include <stdio.h>
#include <stdlib.h>
int len;
void printArr(int arr[], int size) {
  for (int i = 0; i < size; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(int arr[], int size, int i) {
  if (size == 1) {
    printf("Single element in the heap");
  } else {
    printArr(arr, len);
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && arr[l] > arr[largest])
      largest = l;
    if (r < size && arr[r] > arr[largest])
      largest = r;
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, size, largest);
    }
    else{
      return;// already the top is largeset;
    }
  }
}

void insertElement(int arr[], int *size, int element) {
  if (*size == 0) {
    arr[0] = element;
    *size += 1;
  } else {
    arr[*size] = element;
    *size += 1;
    for (int i = *size / 2 - 1; i >= 0; i--) {
      heapify(arr, *size, i);
    }
  }
}

void deleteElement(int arr[], int *size, int element) {
  int i;
  for (i = 0; i < *size; i++) {
    if (element == arr[i])
      break;
  }

  swap(&arr[i], &arr[*size - 1]);
  *size -= 1;
  for (int i = *size / 2 - 1; i >= 0; i--) {
    heapify(arr, *size, i);
  }
}


// int displayMenu() {
//   int choice;
//   printf("\nBinary Heap Menu:\n");
//   printf("1. Insert element\n");
//   printf("2. Delete element\n");
//   printf("3. Print heap\n");
//   printf("4. Exit\n");
//   printf("Enter your choice: ");
//   scanf("%d", &choice);
//   return choice;
// }

// int main() {
//   int arr[10];
//   int size = 0;
//   int choice, element;

//   do {
//     choice = displayMenu();

//     switch (choice) {
//       case 1:
//         printf("Enter the element to insert: ");
//         scanf("%d", &element);
//         insertElement(arr, &size, element);
//         printf("Element %d inserted successfully.\n", element);
//         break;
//       case 2:
//         printf("Enter the element to delete: ");
//         scanf("%d", &element);
//         deleteElement(arr, &size, element);
//         printf("Element %d deleted successfully.\n", element);
//         break;
//       case 3:
//         printf("Max-Heap arr: ");
//         printArr(arr, size);
//         break;
//       case 4:
//         printf("Exiting...\n");
//         break;
//       default:
//         printf("Invalid choice. Please try again.\n");
//     }
//   } while (choice != 4);

//   return 0;
// }
int main(){
  // int arr[] = {21, 26, 30, 9, 4, 14, 28, 18, 15};
  // int arr[] = { 13, 8, 5, 9, 4, 6, 12, 2, 1,3};
  int ar[] = { 1,2,3,4,5,6,7,8,9};
  // int ar[] = {9,4,5,7,8,2,11,1};
  len = sizeof(ar)/sizeof(ar[0]);
  int arr[]={0,0,0,0,0,0,0,0,0};
  int size = 0;
  for(int i =0;i<len;i++){
    insertElement(arr,&size,ar[i]);
    printf("\n");
  }
  printArr(arr, len);
}