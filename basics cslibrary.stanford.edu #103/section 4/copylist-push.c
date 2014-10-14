#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void print(struct node *head);
struct node *copy(struct node *head);
void push(struct node **headref,int data);
struct node *build();

main()
{
	struct node *list;

	list=build();
	print(copy(list));
}

struct node *build()
{
	int i;
	struct node *tail,*head=NULL;

	push(&head,1);
	tail=head;

	for(i=2;i<10;++i,tail=tail->next)
		push(&(tail->next),i);

	return head;
}

void push(struct node **headref,int data)
{
	struct node *new=malloc(sizeof(*new));

	new->data=data;
	new->next=*headref;
	*headref=new;
}

struct node *copy(struct node *head)
{
	struct node *tail,*current,*new;

	new=NULL;
	current=head;

	while(current!=NULL){
		if(new==NULL){
			push(&new,current->data);
			tail=new;
		}
		else{
			push(&(tail->next),current->data);
			tail=tail->next;
		}
		current=current->next;
	}

	return new;
}

void print(struct node *head)
{
	struct node *current=head;

	while(current!=NULL){
		printf("  %d",current->data);
		current=current->next;
	}

	printf("\n\n");
}
