/*	function InsertNth() which can insert a new node at any index within a list	*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *build(void);
int length(struct node *head);
void print(struct node *head);
void push(struct node **headref,int data);
void insertnth(struct node **headref,int index,int data);

main()
{
	int index,data;
	struct node *list=build();	//list=NULL;

	printf("\nenter the index : ");
	scanf("%d",&index);

	if(index<=length(list) && index>=0){
		printf("\nenter the data : ");
		scanf("%d",&data);

		print(list);
		insertnth(&list,index,data);	
		print(list);
	}
	else
		printf("\n\nerror : index out of range!!!\n\n");
}

void insertnth(struct node **headref,int index,int data)	/* insert new node with 'data' at 'index' in 'list' */
{
	int i;
	struct node *current,*prev_node;

	current=*headref;
	prev_node=NULL;

	for(i=0;current!=NULL;++i,current=current->next){
		if(index == i)
			break;

		prev_node=current;		
	}

	if(prev_node == NULL)
			push(headref,data);
	else
			push(&prev_node->next,data);
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
