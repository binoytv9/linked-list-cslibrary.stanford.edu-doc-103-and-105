/*	function DeleteList() that takes a list, deallocates all of its memory and sets its
 *	head pointer to NULL (the empty list)
 */

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *build(void);
void print(struct node *head);
void deletelist(struct node **headref);
void push(struct node **headref,int data);

main()
{
	char y='n';
	struct node *list=build();

	printf("\n\nare u sure u want to delete the list ?(Y/y) : ");
	scanf("%c",&y);

	if(y=='y' || y=='Y'){
		deletelist(&list);
		print(list);
	}
	else
		print(list);

}


void deletelist(struct node **headref)		/* deallocate entire list	*/
{
	struct node *current,*nextnode;

	current=*headref;

	while((current!=NULL)){
		free(current);
		current=current->next;
	}
	*headref=current;
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
