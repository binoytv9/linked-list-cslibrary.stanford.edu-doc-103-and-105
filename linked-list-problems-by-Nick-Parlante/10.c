/*	Write a RemoveDuplicates() function which takes a list sorted in increasing order and
 *	deletes any duplicate nodes from the list. Ideally, the list should only be traversed once.
 */


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void print(struct node *head);
void rmdup(struct node *head);
struct node *build(int data[],int len);
void push(struct node **headref,int data);

main()
{
	int len;
	int data[]={1,1,5,9,9,15,17,17,17,17,20};
	struct node *head;

	len=sizeof(data)/sizeof(int);
	head=build(data,len);

	printf("\ninitial list :\n");
	print(head);

	rmdup(head);

	printf("list after removing duplicates :\n");
	print(head);
}

void rmdup(struct node *head)					/* returns list without duplicates */
{
	struct node *current,*nxt_node;

	current=head;

	while(current!=NULL){
		if((nxt_node=current->next)!=NULL && current->data == nxt_node->data){
			current->next = nxt_node->next;
			free(nxt_node);
		}
		else	
			current=nxt_node;
	}
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
