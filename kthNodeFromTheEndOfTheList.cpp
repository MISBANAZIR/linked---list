#include<Stdio.h>
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

node *kthNodeFromTheEnd(node **head, int k)
{
	node *p;
	node *q;
	int count;
	p = q = *head;
	for(count = 1; count < k && p!= NULL; count++)
	{
		p = p -> next;
	}
	if(p == NULL)
	printf("NULL");
	while(p -> next != NULL)
	{
		p = p -> next;
		q = q -> next;
	}
	printf("the kth node from the end of the list is %d", q -> data);
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
	kthNodeFromTheEnd(&head, 2);
	return 1;
}
