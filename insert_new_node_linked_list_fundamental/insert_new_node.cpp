#include <iostream>

class Node 
{
public:
	int Value;
	Node* Next;
};
void print_list(Node* n)
{
	while (n != NULL)
	{
		std::cout << n->Value << std::endl;
		n = n ->Next;
	}
}
void insert_at_the_front(Node**head, int new_value)
{
	// 1. prepare a new node
	Node* new_node = new Node();
	new_node->Value = new_value;
	// 2. put it in front of current head
	new_node->Next = *head;
	// 3. move head of the list to point to the newNode
	*head = new_node;
}
void insert_at_the_last(Node** head, int new_value)
{
	// 1. prepare a new node
	Node* new_node = new Node();
	new_node->Value = new_value;
	new_node->Next = NULL;
	// 2. if linked list is empty, new node will be a head node
	if (*head == NULL)
	{
		*head = new_node;
		return;
	}
	// 3. find the last node
	Node* last = *head;
	while (last->Next != NULL)
	{
		last = last->Next;
	}
	// 4. insert new node after last node (at the end)
	last->Next = new_node;
}

int main()
{
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	head->Value = 1;
	head->Next = second;
	second->Value = 2;
	second->Next = third;
	third->Value = 3;
	third->Next = NULL;

	insert_at_the_front(&head, -1);
	insert_at_the_last(&head, -3);
	print_list(head);

	return 0;
}