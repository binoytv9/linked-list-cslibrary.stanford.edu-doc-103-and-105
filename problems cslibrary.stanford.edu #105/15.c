/*	Given FrontBackSplit() and SortedMerge(), it's pretty
 *	easy to write a classic recursive MergeSort(): split the list into two smaller lists,
 *	recursively sort those lists, and finally merge the two sorted lists together into a single
 *	sorted list.
 */


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void print(struct node *head);
void mergesort(struct node **headref);
struct node *build(int data[],int len);
void push(struct node **headref,int data);
void movenode(struct node **dref,struct node **sref);
struct node *sortedmrg(struct node *a,struct node *b);
void frontbacksplit(struct node *source,struct node **frontref,struct node **backref);

main()
{
	
	int len;
	int data[]={1,5,3,4,2};
	struct node*head;

	len=sizeof(data)/sizeof(int);
	head=build(data,len);

	printf("\ninitial list :\n");
	print(head);

	mergesort(&head);

	printf("\nlist aftr merge sort :\n");
	print(head);
}

/* sorts list recursively using fronbacksplit() and sortedmrg() */
void mergesort(struct node **headref)
{
	struct node *a,*b;

	if(length(*headref)==1)
		return;

	frontbacksplit(*headref,&a,&b);
	mergesort(&a);
	mergesort(&b);

	*headref=sortedmrg(a,b);
	
}

void frontbacksplit(struct node *source,struct node **frontref,struct node **backref)	/* splits list into 2 subsets */
{
	int len,split;

	if((len=length(source))%2 == 0)
		split=len/2;
	else
		split=len/2 + 1;							/* if odd extra element taken in to front subset */

	*frontref=source;
	while(source!=NULL){
		if(split-- == 1){
			*backref=source->next;
			source->next=NULL;
			break;
		}
	source=source->next;
	}
}

struct node *sortedmrg(struct node *a,struct node *b)
{
	int i;
	struct node dummy,*tail;

	dummy.next=NULL;
	tail=&dummy;

	for(i=0;a!=NULL || b!=NULL;++i){
		if(a!=NULL && b!=NULL){
			if(a->data < b->data)
				movenode(&(tail->next),&a);
			else
				movenode(&(tail->next),&b);
		}
		else
			a==NULL ? movenode(&(tail->next),&b) : movenode(&(tail->next),&a);

		tail=tail->next;
	}
	return dummy.next;
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

struct node *build(int *data,int len)				/* create a list */
{
	int i;
	struct node dummy,*tail;

	dummy.next=NULL;
	tail=&dummy;

	for(i=0;i<len;++i){
		push(&(tail->next),data[i]);
		tail=tail->next;
	}

	return dummy.next;
}

void push(struct node **headref,int data)			/* push node */
{
	struct node *new=malloc(sizeof(*new));

	new->data=data;
	new->next=*headref;
	*headref=new;
}

void print(struct node *head)					/* print the list */
{
	struct node *current=head;

	if(current==NULL){
		printf("\n\t\t<empty>\n\n");
		return;
	}


	while(current!=NULL){
		printf("\t%d",current->data);
		current=current->next;
	}
	printf("\n\n");
}

int length(struct node *head)								/* returns length of list */
{
	int len=0;
	struct node *current=head;

	while(current!=NULL){
		len++;
		current=current->next;
	}
	return len;
}
