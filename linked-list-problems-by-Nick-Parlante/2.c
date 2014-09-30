/*	GetNth() function that takes a linked list and an integer index and returns the data
 *	value stored in the node at that index position.The index should be in the range [0..length-1].
 *	If it is not, GetNth() should assert() fail.
 */

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *build(void);
int length(struct node *head);
void push(struct node **headref,int data);
int getnth(struct node *head,int index);

main()
{
	int index;
	struct node *list=build();

	printf("\n\nenter the index : ");
	scanf("%d",&index);

	if((index<0) || (index>=length(list)))	/* check whether index is in bound */
		printf("\n\nerror : index out of bound!!!\n\n");
	else
		printf("\ndata stored in index '%d' is %d\n\n",index,getnth(list,index));
}

int getnth(struct node *head,int index)		/* returns the data value stored in the node at index position */
{
	struct node *current=head;

	while(current!=NULL){
		if(index-- == 0)
			return current->data;
		current=current->next;
	}
}

int length(struct node *head)			/* returns length of list */
{
	int len=0;
	struct node *current=head;

	while(current!=NULL){
		len++;
		current=current->next;
	}

	return len;
}

struct node *build(void)			/* build a linked list */
{
	int i;
	struct node dummy,*tail;

	dummy.next=NULL;
	tail=&dummy;

	for(i=1;i<10;++i,tail=tail->next)
		push(&(tail->next),i);

	return dummy.next;
}

void push(struct node **headref,int data)	/* add node at the end */
{
	struct node *new=malloc(sizeof(*new));

	new->data=data;
	new->next=*headref;
	*headref=new;
}
