#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CQ {
    int MAX;
    int n_ele;
    struct Node* front;
    struct Node* rear;
};

struct CQ* create(int max) {
    struct CQ* cq = (struct CQ*)malloc(sizeof(struct CQ));
    cq->MAX = max;
    cq->n_ele = 0;
    cq->front = NULL;
    cq->rear = NULL;
    return cq;
}

struct CQ* enQueue(struct CQ* c, int val) {
    if (c->n_ele == c->MAX) {
        printf("Queue is full. Cannot enqueue.\n");
        return c;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (c->front == NULL) {
        c->front = newNode;
        c->rear = newNode;
    } else {
        c->rear->next = newNode;
        c->rear = newNode;
    }

    c->n_ele++;
    return c;
}

struct CQ* deQueue(struct CQ* c) {
    if (c->n_ele == 0) {
        printf("Queue is empty. Cannot dequeue.\n");
        return c;
    }

    struct Node* temp = c->front;
    c->front = c->front->next;

    if (c->front == NULL) {
        c->rear = NULL;
    }

    free(temp);
    c->n_ele--;
    return c;
}

void display(struct CQ* c) {
    if (c->n_ele == 0) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* curr = c->front;
    printf("Queue: ");
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int val, len;
    printf("Creating Queue, Enter max Length: ");
    scanf("%d", &len);
    struct CQ* Q = create(len);

    int option, exit_status = 0;

    do {
        printf("Select the below option:\n\n");
        printf("1. Display the Queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Exit\n\nEnter your option: ");
        scanf("%d", &option);
        printf("\n--------------------------------------------------------------\n\n");

        switch (option) {
            case 1:
                display(Q);
                break;
            case 2:
                printf("Enter the value to enqueue: ");
                scanf("%d", &val);
                Q = enQueue(Q, val);
                break;
            case 3:
                printf("Dequeue\n");
                Q = deQueue(Q);
                break;
            case 4:
                printf("Exiting...\n");
                exit_status = 1;
                break;
            default:
                printf("Enter a valid option.\n");
                break;
        }

        printf("\n--------------------------------------------------------------\n\n");
    } while (exit_status != 1);

    return 0;
}
