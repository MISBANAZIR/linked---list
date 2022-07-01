#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	node *prev;
	node *next;
};

void insert(node **head, int data)
{
	node *temp;
	if(*head == NULL)
	{
		temp = (node *)malloc(sizeof(node));
		temp -> data = data;
		temp -> prev = NULL;
		temp -> next = NULL;
		*head = temp;
	}
	else {
		temp = *head;
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = (node *)malloc(sizof(node));
		temp -> next -> data = data;
		temp -> next -> prev = NULL;
		temp -> next -> next = NULL;
	}
}

void insertInTheMiddle(node **head, int data)
{
	node *temp = *head;
	node *p;
	p = (node *)malloc(sizeof(node));
	p -> data = data;
	while(temp -> next -> data != 3)
	{
		temp = temp -> next;
	}
	p -> prev = temp;
	p -> next = temp -> next;
	temp -> next = p -> prev;
	temp -> next -> prev = p -> next;
	
}

int main()
{
	node *head = NULL;
	for(int i = 0; i <= 4; i++)
	{
		insert(&head, i);
	}
	node *temp = head;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	insertInTheMiddle(&head, 5);
	temp = head;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	return 0;
}
