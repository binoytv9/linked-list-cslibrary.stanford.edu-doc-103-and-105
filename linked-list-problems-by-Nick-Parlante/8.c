/*	Write an Append() function that takes two lists, 'a' and 'b', appends 'b' onto the end of 'a',
 *	and then sets 'b' to NULL
 */

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void print(struct node *head);
struct node *build(int m,int n);
void push(struct node **headref,int data);
void append(struct node **aref,struct node **bref);

main()
{
	struct node *a,*b;

	a=build(0,4);
	b=build(4,8);

	printf("list A :\n");
	print(a);
	printf("list B :\n");
	print(b);
	append(&a,&b);
	printf("list A after append:\n");
	print(a);
}

void append(struct node **aref,struct node **bref)	/* to append B to A and make B point to NULL */
{
	struct node *current=*aref;

	if(*aref == NULL)
		*aref=*bref;
	else{
		while(current->next != NULL)
			current = current->next;
		current->next = *bref;
	}
	*bref=NULL;
}

struct node *build(int m,int n)			/* to build list */
{
	int i;
	struct node dummy,*tail;

	dummy.next=NULL;
	tail=&dummy;

	for(i=m;i<n;++i){
		push(&(tail->next),i);
		tail=tail->next;
	}

	return (dummy.next);
}

void push(struct node **headref,int data)	/* push node at end */
{
	struct node *new=malloc(sizeof(*new));

	new->data=data;
	new->next=*headref;
	*headref=new;
}

void print(struct node *head)			/* print the list */
{
	struct node *current=head;

	if(current==NULL){
		printf("\n\t\t<empty>\n\n");
		return;
	}


	while(current!=NULL){
		printf("\t%d",current->data);
		current=current->next;
	}

	printf("\n\n");
}
