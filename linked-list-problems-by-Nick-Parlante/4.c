/*	Pop() function that is the inverse of Push(). Pop() takes a non-empty list, deletes
 *	the head node, and returns the head node's data.Pop() should assert() fail if there
 *	is not a node to pop
 */

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *build(void);
int length(struct node *head);
void print(struct node *head);
int pop(struct node **headref);
void push(struct node **headref,int data);

main()
{
	struct node *list=build();

	print(list);
	printf("\nlength of list is : %d",length(list));
	printf("\n\t\t\tpoped %d\n",pop(&list));
	print(list);
	printf("\nlength of new list is : %d",length(list));
	printf("\n\n");
}

int pop(struct node **headref)			/* pops a node from beginning */
{
	int data;

	if(*headref==NULL)
		return '\0';
	else{
		data=(*headref)->data;
		free(*headref);
		*headref=(*headref)->next;
		return data;
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

	for(i=1;i<5;++i,tail=tail->next)
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

void print(struct node *head)			/* print the list */
{
	struct node *current=head;

	printf("\n\n");
	while(current!=NULL){
		printf("\t%d",current->data);
		current=current->next;
	}
	printf("\n\n");
}
