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
void insert_at_the_front(Node**head, int newValue)
{
	// 1. prepare a new node
	Node* newNode = new Node();
	newNode->Value = newValue;
	// 2. put it in front of current head
	newNode->Next = *head;
	// 3. move head of the list to point to the newNode
	*head = newNode;
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
	print_list(head);

	return 0;
}