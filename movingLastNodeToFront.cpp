#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	node *next;
};


void insert(node **head, int data)
{
	node *temp;
	if(*head == NULL)
	{
		temp = (node *)malloc(sizeof(node));
		temp -> data = data;
		temp -> next = NULL;
		*head = temp;
	}
    else {
    	temp = *head;
    	while(temp -> next != NULL)
    	{
    		temp = temp -> next;
		}
		temp -> next = (node *)malloc(sizeof(node));
		temp -> next -> data = data;
		temp -> next -> next = NULL;
	}
}

node *moveToFront(node **head)
{
node *p;
node *q;
//	if(!*head || (!(*head -> next)))
//	{
//		return *head;
//	}
	p = NULL;
	q = *head;
	while(q -> next)
	{
		p = q;
		q = q -> next;
	}
	p -> next = NULL;
	q -> next = *head;
	*head = q;
	
	return *head;
}

int main ()
{
	node *head = NULL;
	for(int i = 0; i <= 5; i++)
	{
		insert(&head, i);
	}
	node *temp = head;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	moveToFront(&head);
	temp = head;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	return 0;
}
