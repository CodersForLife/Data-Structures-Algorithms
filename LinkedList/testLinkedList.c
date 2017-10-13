#include <stdio.h>
#include <stdlib.h>

struct Node {
        int data;       //To store data element
        struct Node *next;      // pointer to point to next node in Linked List
};

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

void PrintList(struct Node *n){
        while(n != NULL){
                printf("%d ", n->data);
                n = n->next;
        }
}

int main() {
	struct Node* head = CreateLinkedList();
	PrintList(head);

	return 0;
}

