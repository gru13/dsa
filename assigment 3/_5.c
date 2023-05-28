#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *deleteMiddle(struct ListNode *head, int len)
{
    struct ListNode *tmp = head;
    if (len == 1)
    {
        return NULL;
    }
    if (len == 2)
    {
        tmp->next = NULL;
        return head;
    }
    for (int i = 0; i < len / 2 - 1; i++)
    {
        tmp = tmp->next;
    }
    tmp->next = tmp->next->next;
    return head;
}