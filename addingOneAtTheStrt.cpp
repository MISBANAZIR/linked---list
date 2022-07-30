#include<iostream>
using namespace std;

struct node {
    int val;
    struct node *next;
};

struct node *newNode (int val)
{
    struct node *temp = new node;
    temp -> val = val;
    temp -> next = NULL;
    return temp;
}

void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        cout<<temp -> val << "\t";
        temp = temp -> next;
    }
}

struct node *reverse(struct node *head)
{
    struct node *curr = head;
    struct node *prev = NULL;
    struct node *next;
    while (curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
     return prev;

}

struct node *addingOne(struct node *head)
{
     head = reverse(head);
    struct node *res = head;
    struct node *temp;
    int carry = 1;
    int sum;
    while(head != NULL)
    {
      sum = carry +(head -> val);
      carry = (sum == 10) ? 1: 0;
      sum = sum%10;
      head -> val = sum;
      temp = head;
      head = head -> next;
    }
    if(carry > 0)
    {
        temp -> next = newNode(carry);
    }
    return reverse(res);
    
}

int main()
{
    struct node *head = NULL;
    head = newNode(9);
    head -> next = newNode(5);
    head -> next -> next = newNode(9);
    head -> next -> next -> next = newNode(9);
    head -> next -> next -> next -> next = newNode(9);
    cout<<"Given list is \n";
    printList(head);
  // reverse(head);
    //printList(head);
   addingOne(head);
   cout<< "\nResultant list is\n";
    printList(head);
    
}
