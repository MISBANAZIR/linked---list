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

void countOfNodes(node *head)
{
	int count = 0;
	node *temp = head;
	if(temp == NULL)
	{
		printf("linked list is empty");
	}
	while(temp != NULL)
	{
		count++;
		temp = temp -> next;
	}
	printf("%d", count);
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
	while(temp != NULL)
	{
		//printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	countOfNodes(head);
	return 0;
}
// time complexity is O(n)
// space complexity is O(1)
