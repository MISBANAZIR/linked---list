#include<iostream>

using namespace std;

struct node {
    int val;
    node *next;
};

struct node *insert(int val)
{
    struct node *temp = new node();
    temp -> val = val;
    temp -> next = NULL;
    return temp;
}

void printList(struct node *head)
{
    struct node *temp = head;

    while (temp != NULL)
    {
        cout<<temp -> val<<"\t";
        temp = temp -> next;
    }
}

struct node *swapNodes(struct node *head)
{
    struct node *first = head;
    struct node *dummy = new node();
    struct node *prev = dummy;
    prev -> next = head;
    while(first && first -> next)
    {
        struct node *second = first -> next;
        struct node *future = first -> next-> next;
        second -> next = first;
        prev -> next = second;
        first -> next = future;
        prev = first;
        first = future;
    }
    return dummy -> next;
}

int main()
{
    struct node *head = insert(1);
    head -> next = insert(2);
    head -> next -> next = insert(3);
    head -> next -> next -> next = insert(4);
    head -> next -> next -> next -> next = insert(5);
    printList(head);
    cout<<"\nList after swap\n";
    printList(swapNodes(head));
    
    return 0;
}
