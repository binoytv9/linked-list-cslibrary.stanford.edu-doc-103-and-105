void appendnode(struct node **headref,int data)
{
	struct node *current=*headref;
	struct node *newnode;

	newnode=malloc(sizeof(*newnode));
	newnode->data=data;
	newnode->next=NULL;

	if(current==NULL)
		*headref=newnode;
	else{
		while(current->next != NULL)
			current=current->next;

		current->next=newnode;
	}
}
