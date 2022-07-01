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
		temp -> next = (node *)malloc(sizeof(node));
		temp -> next -> data = data;
		temp -> next -> prev = NULL;
		temp -> next -> next = NULL;
	}
}

void insertAtTheEnd(node **head, int data)
{
	node *temp;
	node *p = (node *)malloc(sizeof(node));
	p -> data = data;
    temp = *head;
    while(temp -> next != NULL)
    {
    	temp = temp -> next;
	}
	temp -> next = p;
	p -> prev = temp -> next;
	p -> next = NULL;
	
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
	insertAtTheEnd(&head, 5);
	temp = head;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	return 0;
}
