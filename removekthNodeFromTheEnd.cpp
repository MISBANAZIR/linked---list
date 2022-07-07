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

node *removeKthNodeFromTheEnd(node **head, int k)
{
	node *p = *head;
	node *q = *head;
	node *temp;
	int count;
	for(count = 1; count < k && p != NULL; count++)
	{
		p = p -> next;
	}
	if(p == NULL)
	{
		return p;
	}
	while(p -> next != NULL)
	{
		p = p -> next;
		q = q -> next;
	}
	printf("%d", q -> data);
	temp = *head;
	while (temp -> next -> data != q -> data)
	{
		temp = temp -> next;
	}
	temp -> next = q -> next;
	free(q);
}

int main()
{
	node *head = NULL;
	for(int i = 1; i <= 6; i++)
	{
		insert(&head, i);
	}
	node *temp = head;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	removeKthNodeFromTheEnd(&head, 5);
	temp = head;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	return 0;
}
