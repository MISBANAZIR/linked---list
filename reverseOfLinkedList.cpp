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

void reverseList(node **head)
{
	node *currptr, *prevptr, *nxtptr;
	currptr = *head;
	prevptr = NULL;
 	while(currptr != NULL)
	{
		nxtptr = currptr -> next;
		currptr -> next = prevptr;
		prevptr = currptr;
		currptr = nxtptr;
	}
	*head = prevptr;
}

int main()
{
	node *head;
	head = NULL;
	for(int i = 0; i <= 5; i++)
	{
		insert(&head, i);
	}
	node *temp = head;
	while(temp != NULL){
		
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	reverseList(&head);
	temp = head;
	printf("\n");
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	return 0;
}
