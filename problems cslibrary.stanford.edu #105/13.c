/*	Given two lists, merge their nodes together to make one list, taking nodes alternately
 *	between the two lists
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
struct node *shufflemerge(struct node *a,struct node *b);

main()
{
	int len;
	int dataA[]={1,2,3,4,5};
	int dataB[]={45,4,36,98,45};
	struct node*a,*b,*mrglist;

	len=sizeof(dataA)/sizeof(int);
	a=build(dataA,len);

	len=sizeof(dataB)/sizeof(int);
	b=build(dataB,len);

	printf("\n list A :\n");
	print(a);
	printf("\n list B :\n");
	print(b);

	mrglist=shufflemerge(a,b);

	printf("\nnew merged list is :\n");
	print(mrglist);
}

/*
Merge the nodes of the two lists into a single list taking a node
alternately from each list, and return the new list.
*/
struct node *shufflemerge(struct node *a,struct node *b)
{
	int i;
	struct node dummy,*tail;

	dummy.next=NULL;
	tail=&dummy;

	for(i=0;a!=NULL || b!=NULL;++i){
		if(a!=NULL && b!=NULL){
			if(i%2==0)
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

/* Take the node from the front of the source, and move it to the front of the dest. */
void movenode(struct node **dref,struct node **sref)
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
