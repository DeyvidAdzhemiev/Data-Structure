#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node* prev;
};


void printList(Node* n)
{
	while (n != NULL)
	{
		cout << n->data << " ";
		n = n->next;
	}
}


void pushFront(Node** head, int newData)
{
	//allocate memory for new node
	Node* newNode = new Node();

	//assign data to new node
	newNode->data = newData;

	//new node is head and previous is null, since we are adding at the front 
	newNode->next = (*head);
	newNode->prev = NULL;

	//previous of head is new node
	if( (*head) != NULL )
		(*head)->prev = newNode;
	
	//head points to new node
	(*head) = newNode;
}


void pushAfter(Node* prevNode, int newData)
{
	//chek if previous node is null
	if (prevNode == NULL)
	{
		cout << "Previous node is required, it cannot be NULL";
		return;
	}

	//allocate memory for new node
	Node* newNode = new Node();

	//assign data to new node
	newNode->data = newData;

	//set next of new node to next of previous node
	newNode->next = prevNode->next;

	//set next of previous node to new node
	prevNode->next = newNode;

	//now set previous of new node to previous node
	newNode->prev = prevNode;

	//set previous of new node's next to new node
	if (newNode->next != NULL)
		newNode->next->prev = newNode;
}


void pushBack(Node** head, int newData)
{
	//allocate memory for node
	Node* newNode = new Node();
	Node* last = *head; //set last node value to head

	//set data for new node
	newNode->data = newData;

	//new node is the last node, so set next of new node to null
	newNode->next = NULL;

	//check if list is empty, if yes make new node the head of list
	if (*head == NULL)
	{
		newNode->prev = NULL;
		*head = newNode;
		return;
	}

	//otherwise traverse the list to go to last node
	while (last->next != NULL)
		last = last->next;

	//set next of last to new node
	last->next = newNode;

	//set last to prev of new node
	newNode->prev = last;
	return;
}


int main()
{
	Node* head = NULL;

	pushFront(&head, 1);
	pushFront(&head, 2);
	pushFront(&head, 3);
	pushFront(&head, 4);
	pushAfter(head->next->prev, 20);
	pushBack(&head, 100);

	printList(head);
}