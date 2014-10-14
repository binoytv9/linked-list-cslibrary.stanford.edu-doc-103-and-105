/*	Write a SortedInsert() function which given a list that is sorted in increasing order, and a
 *	single node, inserts the node into the correct sorted position in the list.
 */

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *build(void);
void print(struct node *head);
struct node *createnode(int data);
void sortedinsert(struct node **headref,struct node *newnode);

main()
{
	int data;
	struct node *newnode,*head;

	head=build();	

	printf("\n\nentr the data : ");
	scanf("%d",&data);

	newnode=createnode(data);

	print(head);
	sortedinsert(&head,newnode);
	print(head);
}

void sortedinsert(struct node **headref,struct node *newnode)
{
	struct node *current,*prev_node;

	current=*headref;
	prev_node=NULL;

	while(current!=NULL){
		if(current->data > newnode->data)
			break;
		prev_node=current;
		current=current->next;
	}

	if(prev_node == NULL){					/* if at head position */
			newnode->next=*headref;
			*headref=newnode;
	}
	else{							/* else where */
		newnode->next = current;
		prev_node->next = newnode;
	}
}


struct node *build(void)
{
	struct node *head=malloc(sizeof(*head));

	head->data=1;
	head->next=malloc(sizeof(*head));
	head->next->data=2;
	head->next->next=malloc(sizeof(*head));
	head->next->next->data=4;
	head->next->next->next=NULL;

	return head;
}

struct node *createnode(int data)				/* to create a new node */
{
	struct node *new=malloc(sizeof(*new));

	new->data=data;
	new->next=NULL;

	return new;
}

void print(struct node *head)					/* print the list */
{
	struct node *current=head;

	if(current==NULL){
		printf("\n\t\t<empty>\n\n");
		return;
	}


	printf("\n\n");
	while(current!=NULL){
		printf("\t%d",current->data);
		current=current->next;
	}
	printf("\n\n");
}
