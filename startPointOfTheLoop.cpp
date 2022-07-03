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

printList(node *head)
{
	node *temp = head;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}

node *findTheStartPointOfTheLoop(node *head)
{
	node *slowptr;
	node *fastptr;
	int loopExists = 0;
	for(fastptr = head, slowptr = head; fastptr && slowptr && fastptr -> next;)
	{
		fastptr = fastptr -> next -> next;
		slowptr = slowptr -> next;
		if(fastptr == slowptr)
		{
			loopExists = 1;
			break;
		}
    }
    if(loopExists)
    {
    	for(slowptr = head; fastptr != slowptr;)
    	{
    		slowptr = slowptr -> next;
    		fastptr = fastptr -> next;
		}
		return slowptr;
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
	head -> next -> next -> next -> next = head -> next -> next;
	node *flag = findTheStartPointOfTheLoop(head);
	printf("the starting point of the loop is %d", flag -> data);
	return 0;
}
