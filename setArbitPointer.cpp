#include<Stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;
    struct node *arbit;
};

struct node *insert(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> val = val;
    temp -> next = NULL;
    temp -> arbit = NULL;
    return temp;
}

void reverse(struct node **head)
{
    struct node *curr = *head;
    struct node *prev = NULL;
    struct node *nxt;
    while(curr != NULL)
    {
        nxt = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nxt;
    }
     *head = prev;
}

struct node *populateArbitPointer(struct node *head)
{
    reverse(&head);
    struct node *maxNode = head;
    struct node*temp;
    for(temp = head -> next; temp; temp = temp -> next)
    {
        temp -> arbit = maxNode;
        if(maxNode -> val < temp -> val)
        maxNode = temp;
    }
    reverse(&head);
    return head;
}

struct node *printList(struct node *head)
{
    struct node *temp = head;
    printf("temp -> val\ttemp -> next\ttemp -> arbit\n");
    while(temp != NULL)
    {
        printf("%d\t", temp -> val);

        if(temp -> next != NULL)
        {
            printf("%d\t\t", temp -> next -> val);
        }
        else {
            printf("NULL\t\t");
        }
        if(temp -> arbit != NULL)
        {
            printf("%d\t\t", temp -> arbit -> val);
        }
        else {
            printf("NULL\t\t");
        }
        printf("\n");
        temp = temp -> next;
    }
}

int main()
{
    struct node *head = insert(2);
    head -> next = insert(1);
    head -> next -> next = insert(8);
    head -> next -> next -> next = insert(3);
    //reverse(&head);
    populateArbitPointer(head);
    printf("the resultant list is \n");
    printList(head);
    return 0;
}