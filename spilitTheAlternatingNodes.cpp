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

void spilitTheAlternatingNodes(node *head, node **head1, node **head2)
{
	*head1 = head;
	if(head == NULL)
	{
		return;
	}
    head -> next = *head2;
    node *temp;
    while(head != NULL)
    {
    	temp = head -> next;
    	head -> next = temp ? temp -> next : temp;
    	head = temp;
	} 
	printf("\n alternate nodes are");

}

int main()
{
	node *head = NULL;
	for(int i = 1; i <= 4; i++)
	{
		insert(&head, i);
	}
	node *temp = head;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	node *head1 = head;
	node *head2 = head -> next;
	spilitTheAlternatingNodes(head, &head1, &head2);
	temp = head2;
    while(temp != NULL)
    {
    	printf(" %d\t", temp -> data);
    	temp = temp -> next;
	}
	return 0;
}
