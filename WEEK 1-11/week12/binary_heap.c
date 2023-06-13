#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(int array[], int size, int i) {
  if (size == 1) {
    printf("Single element in the heap");
  } else {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i) {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}

void insertElement(int array[], int *size, int element) {
  if (*size == 0) {
    array[0] = element;
    *size += 1;
  } else {
    array[*size] = element;
    *size += 1;
    for (int i = *size / 2 - 1; i >= 0; i--) {
      heapify(array, *size, i);
    }
  }
}

void deleteElement(int array[], int *size, int element) {
  int i;
  for (i = 0; i < *size; i++) {
    if (element == array[i])
      break;
  }

  swap(&array[i], &array[*size - 1]);
  *size -= 1;
  for (int i = *size / 2 - 1; i >= 0; i--) {
    heapify(array, *size, i);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}

int displayMenu() {
  int choice;
  printf("\nBinary Heap Menu:\n");
  printf("1. Insert element\n");
  printf("2. Delete element\n");
  printf("3. Print heap\n");
  printf("4. Exit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  return choice;
}

int main() {
  int array[10];
  int size = 0;
  int choice, element;

  do {
    choice = displayMenu();

    switch (choice) {
      case 1:
        printf("Enter the element to insert: ");
        scanf("%d", &element);
        insertElement(array, &size, element);
        printf("Element %d inserted successfully.\n", element);
        break;
      case 2:
        printf("Enter the element to delete: ");
        scanf("%d", &element);
        deleteElement(array, &size, element);
        printf("Element %d deleted successfully.\n", element);
        break;
      case 3:
        printf("Max-Heap array: ");
        printArray(array, size);
        break;
      case 4:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 4);

  return 0;
}
