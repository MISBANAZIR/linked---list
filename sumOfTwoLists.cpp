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

void printList(struct node *node)
{
    
    struct node *temp = node;
    while(temp != NULL)
    {
        cout<<temp -> val<<"\t";
        temp = temp -> next;
    }
}

struct node *sumOfTwoLists(struct node *l1, struct node *l2)
{
   struct node *l3 = insert(0);
   struct node *head = l3;
   int carry = 0;

   while(l1 && l2 != NULL)
   {
        int value = l1 -> val + l2 -> val + carry;
        carry = value/10;
        l3 -> next = insert(value%10);
        l3 = l3 -> next;
        l2 = l2 -> next;
        l1 = l1 -> next;
    }

   while(l1 != NULL)
   {
      int value = l1 -> val + carry;
        carry = value/10;
        l3 -> next = insert(value%10);
        l3 = l3 -> next;
        l1 = l1 -> next;
    }

    while(l2 != NULL)
   {
        int value = l2 -> val + carry;
        carry = value/10;
        l3 -> next = insert(value%10);
        l3 = l3 -> next;
        l2 = l2 -> next;    
    }
    if(carry)
    {
        l3 -> next = insert(carry);
    }
    
    return head -> next;
}

int main()
{
    struct node *head1 = insert(3);
    head1 -> next = insert(5);
    head1 -> next -> next = insert(7);
    head1 -> next -> next -> next = insert(2);
    cout<<"List one is\n";
    printList(head1);
    struct node *head2 = insert(4);
    head2 -> next = insert(5);
    head2 -> next -> next = insert(0);
    cout<<"\nList two is\n";
    printList(head2);
   struct node *temp =  sumOfTwoLists(head1, head2);
    cout<<"\nResultant list is\n";
    printList(temp);
    return 0;
}