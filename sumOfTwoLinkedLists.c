#include<Stdio.h>
#include<Stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node *insert(int val)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp -> val = val;
    temp -> next = NULL;
    return temp;
}

struct node *printList(struct node *head1, struct node *head2)
{
    struct node *temp = head1;
    struct node *p = head2;
    while(temp != NULL)
    {
        printf("%d\t", temp -> val);
        temp = temp -> next;
    }
    printf("\n");
    while(p != NULL)
    {
        printf("%d\t", p -> val);
        p = p -> next;
    }
}

struct node *sumOfTwoLists(struct node *head)
{
    struct node *
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    head1 = insert(9);
    head1 -> next = insert(8);
    head1 -> next -> next = insert(7);
    head2 = insert(3);
    head2 -> next = insert(2);
    head2 -> next -> next = insert(1);
    printList(head1, head2);
    return 0;
}