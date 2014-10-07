/*	Write a function AlternatingSplit() that takes one list and divides up its nodes to make
 *	two smaller lists. The sublists should be made from alternating elements in the original
 *	list
 */

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *build(int);
void print(struct node *);
void push(struct node **,int);
int length(struct node *head);
void movenode(struct node **dref,struct node **sref);
void altsplit(struct node *head,struct node **aref,struct node **bref);

main()
{
	int n=5;
	struct node *head,*a,*b;

	head=build(n);
	a=b=NULL;

	printf("\noriginal list :\n");
	print(head);

	altsplit(head,&a,&b);

	printf("\n\t\tafter splitting :\n\n");
	printf("list A:\n");
	print(a);
	printf("list B:\n");
	print(b);
}

void altsplit(struct node *head,struct node **aref,struct node **bref)/* split list such that all even elements go to first list and others to second list */
{
	int i,len;

	len=length(head);
	for(i=0;i<len;++i){
		if(i%2==0)
			movenode(aref,&head);
		else
			movenode(bref,&head);
	}
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

int length(struct node *head)			/* return length of list */
{
	int len=0;
	struct node *current=head;

	while(current!=NULL){
		len++;
		current=current->next;
	}
	return len;
}

struct node *build(int n)			/* create a list */
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

void push(struct node **headref,int data)	/* push node to list */
{
	struct node *new=malloc(sizeof(*new));

	new->data=data;
	new->next=*headref;
	*headref=new;
}

void print(struct node *head)			/* print entire list */
{
	struct node *current=head;

	while(current!=NULL){
		printf("\t%d",current->data);
		current=current->next;
	}
	printf("\n\n");
}
