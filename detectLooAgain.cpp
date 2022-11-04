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
    struct node *temp = head;
    while(temp != NULL)
    {
        cout<<temp -> val<<"\t";
        temp = temp -> next;
    }
}

int detectLoop(struct node *head)
{
    struct node *slow = head;
    struct node *fast = head;
    while(fast && slow != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    
        if(fast == slow)
        {
            return 1;
        }
    }
        
    return 0;
    
}

int main()
{
    struct node *head = insert(1);
    head -> next = insert(2);
    head -> next -> next = insert(3);
    head -> next -> next -> next = head;
    //printList(head);
    if(detectLoop(head))
        cout<<"loop detected";
        else 
        cout<<"loop is not found";

    return 0;
}

/*time complexity = O(n)
space complexity = O(1)
we are solving this problem with the help of floydes algorithm*/