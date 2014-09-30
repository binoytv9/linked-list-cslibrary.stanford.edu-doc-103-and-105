void linktest()
{
	struct node *head=build23();
	struct node *newnode;

	newnode=(struct node *)malloc(sizeof(*newnode));

	newnode->data=1;
	newnode->next=head;
	head=newnode;
}
