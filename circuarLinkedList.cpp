#include<stdio.h>
#include<Stdlib.h>

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

void sentinalNode(node **head)
{
	int count = 0;
	node *temp = *head;
	while(temp != NULL)
	{
		count++;
		temp = temp -> next;
	}
	node *p = (node *)malloc(sizeof(node));
	p -> data = count;
	p -> next = *head;
	*head = p;
	printf("number of nodes present in the list is %d\n", p -> data);
}
void circularSLL(node **head)
{
	node *temp = *head;
	while(temp -> next != NULL)
	{
		temp = temp -> next;
		
	}
	temp -> next = *head;	
}

int main()
{
	node *head = NULL;
	for(int i = 0; i <= 5; i++)
	{
		insert(&head, i);
	}
	node *temp;
	temp = head;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	sentinalNode(&head);
	circularSLL(&head);
	temp = head;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	return 0;
}
