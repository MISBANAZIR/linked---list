#include<iostream>
using namespace std;

struct node {
    int val;
    struct node *next;
    
};

struct node *insert(int val)
{
    struct node *temp = new node;
    temp -> val = val;
    temp -> next = NULL;
    return temp;
}

void printList(struct node *head)
{
    struct node *temp;
    temp = head;
    while(temp != NULL)
    {
        cout<<temp -> val<<"\t";
        temp = temp -> next;
    }
}

// insertion
// insert at the beginning

void insert(struct node **head, int val)
{
    struct node *temp;
    temp = new node;
    temp -> val = val;
    temp -> next = *head;
    *head = temp;

}

int main()
{
    struct node *head = insert(1);
    head -> next = insert(2);
    head -> next -> next = insert(3);
    head -> next -> next -> next = insert(4);
    head -> next -> next -> next -> next = insert(5);
    cout<<"\nBefore Insertion\n";
    printList(head);
    cout<<"\nAfter Insertion\n";
    insert(&head, 6);
    printList(head);
}

//time complexity = O(1);
// space complixity = O(1);