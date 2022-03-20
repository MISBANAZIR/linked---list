#include<stdio.h>
#include<stdlib.h>
struct node {
	node *prev;
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
		temp -> prev = NULL;
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
		temp -> next -> prev = *head;
		temp -> next -> next = NULL;
		
	}
}
void insertAtTheEnd(node **head, int data)
{
	node *temp;
	temp = *head;
	node *p = (node *)malloc(sizeof(node));
	p -> data = data;
	while(temp -> next = NULL)
	{
		temp = temp -> next;
	}
	temp -> next = p;
	p -> prev = temp ;
	p -> next = NULL;
}
//void insertAtTheMiddle(node **head, int data)
//{
 // node *temp;
  //temp = *head;
  //node *p;
  //p = (node *)malloc(sizeof(node));
  //p -> data = data;
  //while(temp -> next -> data != 3)
  //{
  	//temp = temp -> next;
  //}
  //temp -> next = p;
  //p -> prev = temp -> next;
  //p -> next = temp -> next -> next;
//}
int main ()
{
	int i;
	node *head;
	head = NULL;
	for(i = 1; i <= 4; i++)
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
	insertAtTheEnd(&head, 7);
	//insertAtTheMiddle(&head,8);
	temp = head;
	while(temp != NULL)
	{
		printf("%d\t",temp -> data);
		temp = temp -> next;
	}
	return 0;
}
