/*	Write an iterative Reverse() function that reverses a list by rearranging all the .next
 *	pointers and the head pointer
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
void movenode(struct node **dref,struct node **sref);

struct node *prev_node=NULL;

main()
{
	int n=0;
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
	struct node *current;
	struct node *tmp;

	current=*headref;

	if(*headref==NULL){
		*headref=prev_node;
		return;
	}

	tmp=(*headref)->next;
	(*headref)->next=prev_node;
	prev_node=*headref;
	*headref=tmp;

	recursivereverse((headref));
}

void movenode(struct node **dref,struct node **sref)/* Take the node from the front of the source, and move it to the front of the dest. */
{
	struct node *tmp;

	if(*sref != NULL){
		tmp=*dref;
		*dref=*sref;
		*sref=(*sref)->next;
		(*dref)->next=tmp;
	}
	else
		printf("\n\terror : source is empty!!!\n\n");
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
