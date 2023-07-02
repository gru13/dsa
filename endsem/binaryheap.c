#include <stdio.h>
#include <stdlib.h>

int heap[1000];
int len;

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int i) {
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    if (left < len && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < len && heap[right] > heap[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

void insert(int data) {
    heap[len] = data;
    len++;
    for (int i = len / 2 - 1; i >= 0; i--) {
        heapify(i);
    }
}

void delete(int data) {
    for (int i = 0; i < len; i++) {
        if (heap[i] == data) {
            swap(&heap[i], &heap[len - 1]);
            len--;
            for (int j = len / 2 - 1; j >= 0; j--) {
                heapify(j);
            }
            heapify(0); // Call heapify to maintain the heap property
            break;
        }
    }
}

void heapSort() {
    for (int i = len / 2 - 1; i >= 0; i--) {
        heapify(i);
    }
    int l = len;
    for (int i = len - 1; i >= 0; i--) {
        swap(&heap[0], &heap[i]);
        heapify(0);
    }
    len = l;
}

void printArray() {
    printf("\n");
    for (int i = 0; i < len; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n\n");
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(10);
    heapSort();
    printArray();
    return 0;
}
