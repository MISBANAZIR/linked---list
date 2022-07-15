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

printList(node *head1, node *head2)
{
	node *temp = head1;
	node *p = head2;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
	while( p != NULL)
	{
		printf("%d\t", p -> data);
		p = p -> next;
	}
}


node *newNode(int data)
{
	node *temp = (node *)malloc(sizeof(node));
	temp -> data = data;
	temp -> next = NULL;
}

node *addTwoLists(node *l1, node *l2)
{
	node *l3 = newNode(0);
	node *head = l3;
	int carry = 0;
	int value;
	while(l1 != NULL && l2 != NULL)
	{
		 value = l1 -> data + l2 -> data + carry;
	//	carry = value/10;
		l3 -> next = newNode(value);
		printf("%d\t", value);
		l3 = l3 -> next;
		l1 = l2 -> next;
		l2 = l2 -> next;
	}
	while(l1 != NULL)
	{
	  value = l1 -> data + carry;
	//  carry = value/10;
	  l3 -> next = newNode(value);
	  l3 = l3 -> next;
	  l1 = l1 -> next;	
	}
	while(l2 != NULL)
	{
		value = l2 -> data + carry;
		//carry = value/10;
		l3 -> next = newNode(value);
		l3 = l3 -> next;
		l2 = l2 -> next;
	}
	if(carry)
	{
		return l3 -> next = newNode(carry);
	}
     return head;
}

int main()
{
	node *head = NULL;
	node *head1 = NULL;
	node *head2 = NULL;
	head1 = insert(9);
	head1 -> next = insert(8);
	head1 -> next -> next = insert(3);
	head1 -> next -> next -> next = insert(6);
	head1 -> next -> next -> next -> next = insert(5);
	head2 = insert(3);
	head2 -> next = insert(7);
	head2 -> next -> next = insert(6);
	head2 -> next -> next -> next = insert(1);
    printList(head1, head2);
	addTwoLists(head1, head2);
	node *temp = head -> next;
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	
   return 0;	
}
