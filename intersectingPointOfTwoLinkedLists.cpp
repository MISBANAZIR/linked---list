#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	node *next;
};

node *insert(int data)
{
	node *temp = (node *)malloc(sizeof(node));
	temp -> data = data;
	temp -> next = NULL;
	return temp;
}

node *printList(node *head)
{
	node *temp = head;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
}

int main()
{
	node *head = NULL;
	head = insert(1);
	head -> next = insert(2);
	head -> next -> next = insert(3);
	head -> next -> next -> next = insert(4);
	head -> next -> next -> next -> next = insert(5);
	printList(head);
	return 0;
}
