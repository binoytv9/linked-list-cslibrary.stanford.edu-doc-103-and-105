/*	Count() function that counts the number of times a given int (data) occurs in a list		*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void push(struct node **headref,int data);
struct node *build(void);
int count(struct node *head,int data);

main()
{
	int n;
	struct node *list=build();

	printf("\n\nenter n : ");
	scanf("%d",&n);

	printf("\nno of '%d' is %d\n\n",n,count(list,n));
}

int count(struct node *head,int data)		/* counts the number of times a given int occurs in a list */
{
	int n=0;
	struct node *current=head;

	while(current!=NULL){
		if(current->data == data)
			++n;
		current=current->next;
	}

	return n;
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
