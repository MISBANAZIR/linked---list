#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	node *next;
};

void insert(node **head, int data)
{
	node *temp = (node *)malloc(sizeof(node));
	temp -> data = data;
	temp -> next = *head;
	*head = temp;
}

detectLoop(node **head)
{
	node *fastptr;
	node *slowptr;
	for(fastptr = *head, slowptr = *head; fastptr && fastptr -> next && slowptr;)
	{
		fastptr = fastptr -> next -> next;
		slowptr = slowptr -> next;
		if(slowptr == fastptr)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	node *head = NULL;
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	insert(&head, 5);
	head -> next -> next -> next = head;
	if(detectLoop(&head))
	printf("loop found");
	else 
	printf("no loop");
	return 0;
}
