#include<Stdio.h>
#include<Stdlib.h>


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
printList(node *head)
{
	node *temp = head;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
}

node *linearSearch(node *head, int target)
{
	node *temp = head;
	if(temp)
	{
		while(temp)
		{
			if(temp -> data == target)
			printf("%d\t", target);
			temp = temp -> next;
		}
	}
}

int main()
{
	node *head = insert(1);
	head -> next = insert(2);
	head -> next -> next = insert(3);
	head -> next -> next -> next = insert(4);
	head -> next -> next -> next -> next = insert(5);
	printList(head);
	printf("\n the target node is\t");
	linearSearch(head, 4);
	return 0;
	
}
