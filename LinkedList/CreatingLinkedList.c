// Creating a Linked List of 3 nodes of data type 'struct node'
//which is defined in ''
struct Node* CreateLinkedList(){

        struct Node* Head = NULL;       // Defining nodes
        struct Node* Second = NULL;
        struct Node* Third = NULL;

        Head = (struct Node*) malloc(sizeof(struct Node));      // Allocating memory to nodes
        Second = (struct Node*) malloc(sizeof(struct Node));    // 'malloc' is defined under 'stdlib.h'
        Third = (struct Node*) malloc(sizeof(struct Node));

        Head->data = 1;
        Head->next = Second;

        Second -> data = 2;
        Second -> next = Third;

        Third -> data = 3;
        Third -> next = NULL;
        return Head;
}
