#include<stdio.h>
#include<Stdlib.h>

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

deleteNodeAtTheBeg(node **head, int data)
{
	node *temp = *head;
	*head = (*head) -> next;
	(*head) -> prev = NULL;
	free(temp);
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
	deleteNodeAtTheBeg(&head, 0);
	temp = head;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	return 0;
}
