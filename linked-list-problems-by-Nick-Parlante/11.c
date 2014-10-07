/*	MoveNode() takes two lists, removes the front node from the second list and pushes
 *	it onto the front of the first
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

main()
{
	int len;
	int dataA[]={1,2,3};
	int dataB[]={5,6,7};
	struct node*a,*b;

	len=sizeof(dataA)/sizeof(int);
	a=build(dataA,len);

	len=sizeof(dataB)/sizeof(int);
	b=build(dataB,len);

	printf("\n list A :\n");
	print(a);
	printf("\n list B :\n");
	print(b);

	movenode(&a,&b);

	printf("\n\t\taftr moving\n\n");
	printf("list A :\n");
	print(a);
	printf("\nlist B :\n");
	print(b);
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

	while(current!=NULL){
		printf("\t%d",current->data);
		current=current->next;
	}
	printf("\n\n");
}
