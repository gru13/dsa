#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node* NODE;

struct Node{
    int data;
    int height;
    NODE lft;
    NODE ryt;
};

NODE create()