#include<Stdio.h>
#include<Stdlib.h>

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

struct node *printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d\t", temp -> val);
        temp = temp -> next;
    }
}

void reverseList(struct node **head_ref)
{
    struct node *prev = NULL;
    struct node *curr = *head_ref;
    struct node *nxt;
    while(curr != NULL)
    {
        nxt = curr -> next;
        curr -> next = prev;
        prev  = curr;
        curr = nxt;
    }
     *head_ref = prev;
}

int compareLists(struct node *head, struct node *secondHalf)
{
    struct node *temp1 = head;
    struct node *temp2 = secondHalf;
    while(temp2 != NULL && temp1 -> val == temp2 -> val)
    {
       temp1 = temp1 -> next;
       temp2 = temp2 -> next;
    }
    if(temp2 == NULL)
    {
        return 1;
    }
    return 0;
}

int isPalindrome(struct node *head)
{
    struct node *midNode;
    struct node *secondHalf;
    struct node *slow = head;
    struct node *fast = head;
    while(fast -> next != NULL && fast -> next -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    midNode = slow;
    secondHalf = slow -> next;
    midNode -> next = NULL;
     reverseList(&secondHalf);
    int result = compareLists(head, secondHalf);
    reverseList(&secondHalf);
    midNode -> next = secondHalf;
    return result;
}



int main()
{
    struct node *head;
    head = insert(1);
    head -> next = insert(2);
    head -> next -> next = insert(3);
    head -> next -> next -> next = insert(2);
    head -> next -> next -> next -> next = insert(1);
    printList(head);
    if(isPalindrome(head))
    printf("list is palindrome");
    else 
    printf("list is not palindrome");
    return 0;
}
