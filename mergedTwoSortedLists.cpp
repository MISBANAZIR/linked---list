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
	while(p != NULL)
	{
		printf("%d\t", p -> data);
		p = p -> next;
	}
}

node *merge(node *list1, node *list2)
{
	node *mergeList;
	node *temp;
	if(list1 -> data <= list2 -> data)
	{
		mergeList = list1;
		list1 = list1 -> next;
	}
	else {
	mergeList = list2;
	list2 = list2 -> next;
    }
    
    temp = mergeList;
    while(list1 && list2)
    {
    	if(list1 -> data <= list2 -> data)
    	{
    		temp -> next = list1;
    		temp = temp -> next;
    		list1 = list1 -> next;
		}
		temp -> next = list2;
		temp = temp -> next;
		list2 = list2 -> next;
	}
	
	if(!list1)
	{
		temp -> next = list2;
	}
	else {
		temp -> next = list1;
	}
	return mergeList;
	
}

int main()
{
	node *head1 = insert(1);
	head1 -> next = insert(3);
	head1 -> next -> next = insert(5);
	node *head2 = insert(2);
	head2 -> next = insert(4);
	head2 -> next -> next = insert(6);
	printList(head1, head2);
	node *temp = merge(head1, head2);
	printf("\n the merged list is ");
	while(temp != NULL)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	return 0;
}
