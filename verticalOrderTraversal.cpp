#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	node *left;
	node *right;
};


node *newNode(int data)
{
	node *temp = (node *)malloc(sizeof(node));
	temp -> data = data;
	temp -> left = temp -> right = NULL;
	return temp; 
}

void findMinMax(node *root, int *min, int *max, int hd)
{
	if (root == NULL)
	{
		return;
	}
	if(hd < *min) 
	*min = hd;
	else if(hd > *max) 
	*max = hd;
	
	findMinMax(root -> left, min, max, hd-1);
	findMinMax(root -> right, min, max, hd+1);
}

void printVerticalLine(node *root, int line_no, int hd)
{
	if(root == NULL)
	{
		return;
	}
	if(hd == line_no)
	{
		printf("%d ", root -> data);
	}
	printVerticalLine(root -> left, line_no, hd - 1);
	printVerticalLine(root -> right, line_no,hd + 1);
}

void verticalOrder(node *root)
{
	int min = 0, max = 0;
	findMinMax(root, &min, &max, 0);
	for(int line_no = min; line_no <= max; line_no++)
	{
		printVerticalLine(root, line_no, 0);
		printf("%d\n");
	}
}

int main()
{
	node *root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	root -> right -> left = newNode(6);
	root -> right -> right = newNode(7);
	printf("vertical order traversal is\n");
	verticalOrder(root);
	return 0;
}
    
  
    
    
    
