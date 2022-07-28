#include<iostream>

using namespace std;

struct node {
    int val;
    struct node *next;
};

struct node *insert(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> val = val;
    temp -> next = NULL;
    return temp;
}

void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        cout<<temp ->  val << "\t";
        temp = temp -> next;
    }
}

void sortList(struct node *head)
{
    int count[3] = {0, 0, 0};
    struct node *temp = head;
    while(temp != NULL)
    {
        count [temp -> val] +=1;
        temp = temp -> next;
    }
    temp = head;
    int i = 0;
        while(temp != NULL)
        {
          if(count[i] == 0)
          ++i;
          else {
            temp -> val = i;
            --count[i];
            temp = temp -> next;
          }
        }
}

int main()
{
    struct node *head = NULL;
    head = insert(2);
    head -> next = insert(0);
    head -> next -> next = insert(2);
    head -> next -> next -> next = insert(1);
    head -> next -> next -> next -> next = insert(2);
    head -> next -> next -> next -> next -> next = insert(0);
    cout <<"The list before sorting\n";
    printList(head);

    cout<< "\nThe list after sorting\n";
    sortList(head);
    printList(head);
    return 0;

}