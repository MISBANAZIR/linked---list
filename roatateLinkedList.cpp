#include<iostream>
using namespace std;

struct node {
    int val;
    struct node *next;
};

struct node *insert(int val)
{
    struct node *temp;
    temp = new node;
    temp -> val = val;
    temp -> next = NULL;
    return temp;
}

void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        cout<<temp -> val<<"\t";
        temp = temp -> next;
    }
}

void rotateList(struct node **head, int k)
{
        int count = 1;
    struct node *curr = *head;
    if(curr == NULL)
    {
        return;
    }
    while(count < k && curr != NULL)
    {
        curr = curr -> next;
        count++;
    }
    struct node *kthNode = curr;
    while(curr -> next != NULL)
    {
        curr = curr -> next;
    }
    curr -> next = *head;
    *head = kthNode -> next;
    kthNode -> next = NULL;
    
}


int main()
{
    struct node *head = NULL;
    head = insert(1);
    head -> next = insert(2);
    head -> next -> next = insert(3);
    head -> next -> next -> next = insert(4);
    head -> next -> next -> next -> next = insert(5);
    head -> next -> next -> next -> next -> next = insert(6);
    cout<<"list before rotation\n";
    printList(head);
    rotateList(&head, 4);
    cout<<"\nList after rotation\n";
    printList(head);
    return 0;
}