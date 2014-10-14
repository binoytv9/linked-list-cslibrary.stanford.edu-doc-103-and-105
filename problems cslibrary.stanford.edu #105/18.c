/*	Recursively reverses the given linked list by changing its .next
 *	pointers and its head pointer in one pass of the list.
 */


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *build(int n);
void print(struct  node *head);
void push(struct node **headref,int data);
void recursivereverse(struct node **headref);

main()
{
	int n=5;
	struct node *head;

	head=build(n);

	printf("\ninitial list is :\n");
	print(head);

	recursivereverse(&head);

	printf("\nlist aftr reversing :\n");
	print(head);
}

void recursivereverse(struct node **headref)		/* Reverse the given linked list recursively */
{
	struct node *first,*rest;

	if(*headref==NULL)
		return;

	first=*headref;
	rest=first->next;

	if(rest==NULL)
		return;

	recursivereverse(&rest);

	first->next->next=first;
	first->next=NULL;

	*headref=rest;
}

struct node *build(int n)			/* create a linked list */
{
	int i;
	struct node dummy,*tail;

	dummy.next=NULL;
	tail=&dummy;

	for(i=0;i<n;++i){
		push(&(tail->next),i);
		tail=tail->next;
	}

	return dummy.next;
}

void push(struct node **headref,int data)	/* push new node to a list */
{
	struct node *new=malloc(sizeof(*new));

	new->data=data;
	new->next=*headref;
	*headref=new;
}

void print(struct  node *head)			/* print the list */
{
	struct node *current=head;

	if(current==NULL){
		printf("\n\t<empty>\n\n");
		return;
	}

	while(current!=NULL){
		printf("\t%d",current->data);
		current=current->next;
	}
	printf("\n\n");
}
