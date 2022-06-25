#include<Stdio.h>
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

void deleteAtTheMiddle(node **head, int data)
{
	node*temp = *head;
	node *t;
	while(temp -> next -> data != 3)
	{
		temp = temp -> next;
	}
	t = temp -> next;
	temp -> next = temp -> next -> next;
	free(t);
}

int main ()
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
	
	deleteAtTheMiddle(&head, 3);
	temp = head;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	return 0;
}
