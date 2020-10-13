#include <iostream>
#include <assert.h>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
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
	//allocate new node
	Node* newNode = new Node();

	//put in the data
	newNode->data = newData;

	//make next of new node as head
	newNode->next = (*head);

	//move the head to point to the new node
	(*head) = newNode;
}


void pushAfter(Node* prevNode, int newData)
{
	//Check if the prevNode is NULL
	if (prevNode == NULL)
	{
		cout << "The given previous node cannot be NULL";
		return;
	}

	//Allocate new node
	Node* newNode = new Node();

	//Put in the data
	newNode->data = newData;

	//Make next of new node as next of previous node 
	newNode->next = prevNode->next;

	//Move the next of previous node as new node
	prevNode->next = newNode;
}


void pushBack(Node** head, int newData)
{
	//allocate node
	Node* newNode = new Node();

	Node* last = *head;

	//put in the data 
	newNode->data = newData;

	//This new node is going to be the last node, so make next of it as NULL
	newNode->next = NULL;

	//If linked list is empty, then make the new node as head
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}

	//Else traverse till the last node 
	while (last->next != NULL)
	{
		last = last->next;
	}

	//Change the next of new node
	last->next = newNode;
	return;
}


void deleteList(Node** head)
{
	Node* current = *head;
	Node* next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}


//Iterative way
int getCountOfTheList(Node* head)
{
	int count = 0; 
	Node* current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}


//Recursive way
int getCountOfTheList2(Node* head)
{
	if (head == NULL)
		return 0;

	return 1 + getCountOfTheList2(head->next);
}


//Iterative way
int getNth(Node* head, int index)
{
	Node* current = head;
	int count = 0;
	while (current != 0)
	{
		if (count == index)
			return current->data;
		count++;
		current = current->next;
	}
	assert(0);
}


//Recursive way
int getNth2(Node* head, int n)
{
	int count = 0;
	if (count == n)
		return head->data;

	return getNth2(head->next, n - 1);
}


int getNthFromLast(Node* head, int n)
{
	int len = 0;
	Node* temp = head;

	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}

	if (len < n)
		assert(0);

	temp = head;
	for (size_t i = 1; i < len - n + 1; i++)
		temp = temp->next;

	return temp->data;
}


//Function to get the middle of the linked list 
void printMiddle(Node* head)
{
	Node* slowPtr = head;
	Node* fastPtr = head;

	if (head != NULL)
	{
		while (fastPtr != NULL && fastPtr->next != NULL)
		{
			fastPtr = fastPtr->next->next;
			slowPtr = slowPtr->next;
		}
		cout << "The middle element is: " << slowPtr->data << endl;
	}
}


//Counts the number of occurrences of a node in the linked list 
int count(Node* head, int searchFor)
{
	Node* current = head;
	int count = 0;
	while (current != NULL)
	{
		if (current->data == searchFor)
			count++;
		current = current->next;
	}
	return count;
}


//Detection of a loop in a Linked List
int detectLoop(Node* list)
{
	Node* slowPtr = list, * fastPtr = list;

	while (slowPtr && fastPtr && fastPtr->next)
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if (slowPtr == fastPtr)
			return 1;
	}
	return 0;
}


//The function removes duplicates from a sorted list
void removeDuplicates(Node* head)
{
	Node* current = head;

	//Pointer to store the next pointer of a node to be deleted
	Node* next_next;

	if (current == NULL)
		return;

	while (current->next != NULL)
	{
		if (current->data == current->next->data)
		{
			next_next = current->next->next;
			free(current->next);
			current->next = next_next;
		}
		else
			current = current->next;
	}
}


//Delete a Linked List node at a given position 
void deleteNode(Node** head, int position)
{
	if (head == NULL)
		return;

	Node* temp = *head;
	
	if (position == 0)
	{
		*head = temp->next;
		free(temp);
		return;
	}

	//Find previous node of the node to be deleted
	for (size_t i = 0; temp != NULL && i < position - 1; i++)
		temp = temp->next;
	
	//If position is more than number of nodes 
	if (temp == NULL || temp->next == NULL) 
		return;

	Node* next = temp->next->next;
	free(temp->next);
	temp->next = next;
}

int main()
{
	Node* head = NULL;

	pushFront(&head, 10);
	pushFront(&head, 30);
	pushFront(&head, 11);
	pushFront(&head, 21);
	pushFront(&head, 14);
	pushFront(&head, 14);
	pushFront(&head, 14);
	
	printList(head);
	
	cout << endl;
	cout << getCountOfTheList(head) << endl;
	cout << getCountOfTheList2(head) << endl;
	cout << "Element at index 3 is " << getNth(head, 3) << endl;
	cout << "Element at index 3 is " << getNth2(head, 3) << endl;
	cout << getNthFromLast(head, 4) << endl;
	printMiddle(head);
	cout << "count of 14 is " << count(head, 14);
	cout << endl;
	cout << "Deleting linked list" << endl;
	deleteList(&head);
	printList(head);
	cout << "\nLinked list deleted";

	return 0;
}