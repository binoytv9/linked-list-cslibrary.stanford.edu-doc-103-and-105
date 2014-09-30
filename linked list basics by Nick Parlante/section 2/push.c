#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void display(struct node *head);
void push(struct node **headref,int data);
struct node *build123(void);

main()
{
	struct node *head=NULL;	//=build123();

	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	display(head);
	printf("\n\n");
}

struct node *build123(void)
{
	struct node *head=malloc(sizeof(struct node));

	head->data=2;
	head->next=malloc(sizeof(struct node));
	head->next->data=3;
	head->next->next=malloc(sizeof(struct node));
	head->next->next->data=4;
	head->next->next->next=NULL;

	return head;
}

void push(struct node **headref,int data)
{
	struct node *newnode;

	newnode=malloc(sizeof(*newnode));

	newnode->data=data;
	newnode->next=*headref;
	*headref=newnode;
}

void display(struct node *head)
{
	struct node *current=head;

	while(current != NULL){
		printf("\t%d",current->data);
		current = current->next;
	}
}
