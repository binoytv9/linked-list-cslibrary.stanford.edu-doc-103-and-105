/*	function to return the number of nodes/elements in a linked list	*/

#include<stdio.h>
#include<stdlib.h>

struct node *build123();
void lengthtest(void);
int length(struct node *head);

struct node{
	int data;
	struct node *next;
};

main()
{
	lengthtest();
}

int length(struct node *head)
{
	int len=0;
	struct node *current;

	for(current=head;current!=NULL;current=current->next)
		++len;

	return len;
}

void lengthtest(void)
{
	struct node *nlist;

	nlist=build123();

	printf("\nlength is : %d\n\n",length(nlist));
}

struct node *build123()
{
	struct node *head=(struct node *)malloc(sizeof(struct node));
	
	head->data=1;
	head->next=(struct node *)malloc(sizeof(struct node));
	head->next->data=2;
	head->next->next=(struct node *)malloc(sizeof(struct node));
	head->next->next->data=3;
	head->next->next->next=NULL;

	return head;
}
