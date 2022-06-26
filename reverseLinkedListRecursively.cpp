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
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = (node *)malloc(sizeof(node));
		temp -> next -> data = data;
		temp -> next -> next = NULL;
	}
}

void reverseSLLRecursively(node *p)
{
	if(p)
	{
		reverseSLLRecursively(p -> next);
		printf("%d\t", p -> data);
	}
}

int main()
{
	node *head = NULL;
	for(int i = 0; i <= 5; i++)
	{
    	insert(&head, i);
	}
	node *p = head;
	reverseSLLRecursively(p);
	return 0;
}
