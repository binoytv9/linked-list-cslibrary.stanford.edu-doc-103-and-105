/*	function to return the number of elements in a linked list	*/

int length(struct node *head)
{
	int len=0;
	struct node *np;

	for(np=head;np!=NULL;np=np->next)
		++len;

	return len;
}
