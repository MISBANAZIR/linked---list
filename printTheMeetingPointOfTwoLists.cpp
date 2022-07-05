#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	node *next;
};

node *insert(int data)
{
	node *temp = (node *)malloc(sizeof(node));
	temp -> data = data;
	temp -> next = NULL;
	return temp;
}

node *printList(node *head1, node *head2)
{
	node *temp = head2;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
    }
}

int countNode(node *head);
int _getIntersectionNode(int diff, node *head1, node *head2);


int getIntersectionNode(node *head1, node *head2)
{
	int l1 = countNode(head1);
	int l2 = countNode(head2);
	int diff = abs(l1 - l2);
	return (l1 > l2) ? _getIntersectionNode(diff, head1, head2) :
	_getIntersectionNode(diff, head2, head1);
}

int countNode(node *head)
{
	int count;
	for(count = 0; head; head = head -> next, count++);			
    return count;
     
}
_getIntersectionNode(int diff, node *head1, node *head2)
{
	
	for(int count = 0; count < diff; count++, head1 = head1 -> next)
	if(!head1)
	{
		return 1;
	}
	for(; head1 && head2; head1 = head1 -> next, head2 = head2 -> next)
	{
		if(head1 == head2)
		{
			return head2 -> data;
		}
	}
}

int main()
{
	node *head1 = NULL;
	node *head2 = NULL;
	head1 = insert(1);
	head1 -> next = insert(2);
	head1 -> next -> next = insert(3);
	head1 -> next -> next -> next = insert(4);
	head2 = insert(5);
	head2 -> next = insert(6);
	head2 -> next -> next = head1 -> next -> next;
	printList(head1, head2);
	//countNode(head2);
	printf("the intersection node is %d\n", getIntersectionNode(head1, head2));
	return 0;
}
