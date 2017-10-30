// Printing all the value of data in every node 
void PrintList(struct Node *n){
	while(n != NULL){
		printf("%d ", n->data);
		n = n->next;
	}
}
