#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
	
};
 insert(node **head, int data)
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
	 	while(temp -> next !=NULL)
	 	{
	 		temp = temp -> next;
		 }
		 temp -> next = (node *)malloc(sizeof(node));
		 temp -> next -> data = data; 
		 temp -> next -> next = NULL;
	 	
	 }
 }
 void AddInTheMiddle(node **head, int data)
 {
  node *temp;
  temp = *head;
 node *p = (node *)malloc(sizeof(node));
 p -> data = data;
 while(temp -> data != 3)
 {
 	
 	temp = temp -> next;
 }
 p -> next = temp -> next;
 temp -> next = p;
	 
 }
 int main()
 {
 	int i;
 	node *head = NULL;
 	for(i = 0; i <= 5; i++)
 	{
 		insert(&head,i);
	 }
	 node *temp = head;
	 while(temp != NULL)
	 {
	 	printf("%d\t",temp -> data);
	 	temp = temp -> next;
	 }
	void AddInTheMiddle(&head int data);
	 temp = *head;
	 return 0;
 }

