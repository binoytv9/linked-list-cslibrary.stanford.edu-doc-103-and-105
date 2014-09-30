int length(struct node *head)
{
	int len=0;

	while(head!=NULL){
		len++;
		head=head->next;
	}

	return len;
}
