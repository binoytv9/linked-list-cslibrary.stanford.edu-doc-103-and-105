#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void display(struct node *head);
void push(struct node **headref,int data);
struct node *tailptr(void);

main()
{
	display(tailptr());
	printf("\n\n");
}
void push(struct node **headref,int data)
{
	struct node *newnode = malloc(sizeof(struct node));

	newnode->data = data;
	newnode->next = *headref;
	*headref=newnode;
}

struct node *tailptr(void)
{
	int i;
	struct node *head,*tail;

	head=NULL;

	push(&head,1);
	tail=head;

	for(i=2;i<6;++i,tail=tail->next)
		push(&(tail->next),i);


	return head;
}

void display(struct node *head)
{
	struct node *current=head;

	while(current!=NULL){
		printf("\t%d",current->data);
		current=current->next;
	}
}
