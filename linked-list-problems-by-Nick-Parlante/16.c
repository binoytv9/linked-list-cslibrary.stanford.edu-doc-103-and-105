/*	Given two lists sorted in increasing order, create and return a new list representing the
 *	intersection of the two lists
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
struct node *sortedintersect(struct node* a,struct node *b);

main()
{
	int len;
	int dataA[]={1,4,5,7,8,9,10};
	int dataB[]={1,2,3,5,9,10};
	struct node*a,*b,*intrlist;

	len=sizeof(dataA)/sizeof(int);
	a=build(dataA,len);

	len=sizeof(dataB)/sizeof(int);
	b=build(dataB,len);

	printf("\n list A :\n");
	print(a);
	printf("\n list B :\n");
	print(b);

	intrlist=sortedintersect(a,b);
	printf("\nintersection of list A and B is :\n");
	print(intrlist);
}

/* Compute a new sorted list that represents the intersection of the two given sorted lists */
struct node *sortedintersect(struct node* a,struct node *b)
{
	struct node dummy,*tail;

	dummy.next=NULL;
	tail=&dummy;

	while(a!=NULL && b!=NULL){
		if(a->data < b->data)
			a=a->next;
		else if(a->data > b->data)
			b=b->next;
		else{
			push(&(tail->next),a->data);
			tail=tail->next;
			a=a->next;
			b=b->next;
		}
	}
	return dummy.next;
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

void push(struct node **headref,int data)			/* push node to list */
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
		printf("\n\t\tnull\n\n");
		return;
	}

	while(current!=NULL){
		printf("\t%d",current->data);
		current=current->next;
	}
	printf("\n\n");
}
