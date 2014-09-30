#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void printlist(struct node *head);
struct node *build123(void);
struct node *copylist(struct node *head);

main()
{
	struct node *newlist;

	newlist=build123();

	printlist(newlist);
	printlist(copylist(newlist));
}

struct node *copylist(struct node *head)
{
	struct node *tail,*current,*newlist;

	current=head;
	newlist=NULL;

	while(current!=NULL){
		if(newlist==NULL){
			newlist=malloc(sizeof(*newlist));
			newlist->data=current->data;
			newlist->next=NULL;
			tail=newlist;
		}
		else{
			tail->next=malloc(sizeof(*tail));
			tail=tail->next;
			tail->data = current->data;
			tail->next=NULL;
		}
		current=current->next;
	}

	return newlist;
}

struct node *build123(void)
{
	struct node *head=malloc(sizeof(*head));

	head->data=1;
	head->next=malloc(sizeof(*head));
	head->next->data=5;
	head->next->next=malloc(sizeof(*head));
	head->next->next->data=8;
	head->next->next->next=NULL;

	return head;
}

void printlist(struct node *head)
{
	struct node *current=head;

	while(current!=NULL){
		printf("\t%d",current->data);
		current=current->next;
	}
	printf("\n\n");
}	
