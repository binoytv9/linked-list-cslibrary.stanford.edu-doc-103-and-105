/*	Write a SortedMerge() function that takes two lists, each of which is sorted in increasing
 *	order, and merges the two together into one list which is in increasing order.
 *	SortedMerge() should return the new list
*/


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void print(struct node *head);
struct node *build(int data[],int len);
void push(struct node **headref,int data);
void movenode(struct node **dref,struct node **sref);
struct node *sortedmrg(struct node *a,struct node *b);

main()
{
	
	int len;
	int dataA[]={1,5,8};
	int dataB[]={2,4,7};
	struct node*a,*b,*mrglist;

	len=sizeof(dataA)/sizeof(int);
	a=build(dataA,len);

	len=sizeof(dataB)/sizeof(int);
	b=build(dataB,len);

	printf("\n list A :\n");
	print(a);
	printf("\n list B :\n");
	print(b);

	mrglist=sortedmrg(a,b);

	printf("\nlist aftr merging :\n");
	print(mrglist);
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
