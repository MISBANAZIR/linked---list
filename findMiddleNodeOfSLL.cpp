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

void findMiddleNode(node *head)
{
	node *fastptr;
	node *slowptr;
	fastptr = head;
	slowptr = head;
	while(fastptr -> next && fastptr -> next -> next != NULL )
	{
		fastptr = fastptr -> next -> next;
		slowptr = slowptr -> next;
	}
	printf(" middle node is %d", slowptr -> data);
}

int main()
{
	node *head = NULL;
	for(int i = 0; i <= 6; i++)
	{
		insert(&head, i);
	}
	node *temp = head;
	while(temp != NULL)
	{
		printf("%d\t", temp);
		temp = temp -> next;
	}
	printf("\n");
//	findMiddleNode(head);
	return 0;

}

