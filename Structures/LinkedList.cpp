#include <stdlib.h>
#include <cassert>
#include <cstdio>

void append(int element);
void clear(void);
int max(void);
int get(unsigned int position);
void remove_element(unsigned int position);

struct Node 
{
	int value;
	struct Node* next;
};

static struct Node* head = 0;

void append(int element)
{
	if (!head)
	{
		head = (struct Node*)malloc(sizeof(struct Node));
		head->value = element;
		head->next = 0;
	}	
	else 
	{
		struct Node* iterator = head;
		while (iterator->next != 0)
			iterator = iterator->next;

		iterator->next = (struct Node*)malloc(sizeof(struct Node));
		iterator->next->value = element;
		iterator->next->next = 0;
	}
}

void clear(void)
{
	if (head == 0)
		return;

	struct Node* iterator = head;
	struct Node* iterator2;
	while (iterator != 0)
	{
		iterator2 = iterator->next;
		free(iterator);
		iterator = iterator2;
	}
	head = 0;
}

int max(void)
{
	int max = 0;
	for (struct Node* iterator = head; iterator; iterator = iterator->next)
		if (iterator->value > max)
			max = iterator->value;

	return max;
}


int get(unsigned int position)
{
	struct Node* iterator = head;
	for (int i = 0; i < position; i++)
	{
		if (!iterator || !iterator->next)
			return 0;

		iterator = iterator->next;
	}

	return iterator->value;
}

void remove_element(unsigned int position)
{
	struct Node* iterator = head;
	struct Node* prev_iterator = head;
	for (int i = 0; i < position; i++)
	{
		if (!iterator || !iterator->next)
			return;

		prev_iterator = iterator;
		iterator = iterator->next;
	}

	if(position == 0)
	{
		head = iterator->next;
		free(iterator);
	}
	else
	{
		iterator = iterator->next;
		free(prev_iterator->next);
		prev_iterator->next = iterator;
	}
}

/////////
//TESTS//
/////////

void max_of_one_element_is_same_element(void)
{
	append(5);
	assert(max() == 5);
	clear();
}

void max_of_three_elements(void)
{
	append(3);
	append(5);
	append(2);
	assert(max() == 5);
	clear();
}

void get_returns_element_in_position(void)
{
	append(3);
	append(5);
	append(7);
	assert(get(2) == 7);
	assert(get(0) == 3);
	assert(get(500) == 0);
	clear();
}

void erasing_elements(void)
{
	append(3);
	append(5);
	append(7);
	remove_element(1);
	assert(get(0) == 3);
	assert(get(1) == 7);
	assert(get(2) == 0);
	clear();
}


int main (void)
{
	max_of_one_element_is_same_element();
	max_of_three_elements();
	get_returns_element_in_position();
	erasing_elements();
	printf("All tests passed!\r\n");
}