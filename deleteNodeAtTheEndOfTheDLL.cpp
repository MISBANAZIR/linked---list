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

deleteAtTheEnd(node **head, int data)
{
	node *temp = *head;
	node *p;
	while(temp -> next -> next != NULL)
	{
		temp = temp -> next;
	}
	p = temp -> next;
	temp -> next = NULL;
	free(p);
}

int main()
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
	deleteAtTheEnd(&head, 5);
	temp = head;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	return 0;
}
