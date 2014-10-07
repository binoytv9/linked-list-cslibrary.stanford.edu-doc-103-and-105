/*	Split the nodes of the given list into front and back halves,
 *	and return the two lists using the reference parameters.
 *	If the length is odd, the extra node should go in the front list.
 */

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *build(int n);
void print(struct node *head);
int length(struct node *head);
void push(struct node **headref,int data);
void frontbacksplit(struct node *source,struct node **frontref,struct node **backref);

main()
{
	struct node *head,*front,*back;

	head=build(5);
	front=back=NULL;

	printf("\ninitial list :\n");
	print(head);
	frontbacksplit(head,&front,&back);

	printf("front half :\n");
	print(front);

	printf("back half :\n");
	print(back);
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

struct node *build(int n)								/* create a list with data from 0 to n-1 */
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

void push(struct node **headref,int data)						/* push node */
{
	struct node *new=malloc(sizeof(*new));

	new->data=data;
	new->next=*headref;
	*headref=new;
}

void print(struct node *head)								/* print list */
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
