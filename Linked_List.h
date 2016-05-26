#pragma once

#include <iostream>

struct Node
{
public:
	Node *next;
	int data;

	Node(int p_data)
	{
		data = p_data;
		next = NULL;
	}
	Node()
	{
		data = 0;
		next = NULL;
	}
};

class LinkedList
{
public:
	Node *top;//members
	int count;

	LinkedList()
	{
		top = NULL;
		count = 0;
	}
	void print()
	{
		Node *iterator = top;
		int count = 0;
		while (iterator != NULL)
		{
			cout << iterator->data << endl;
			iterator = iterator->next;
			count++;
		}
	}
	void addFront(int data)
	{
		Node *new_node = new Node(data);
		if (top == NULL)
		{
			top = new_node;
			count = 1;
		}
		else
		{
			new_node->next = top;
			top = new_node;
		}
	}
	void addLast(int data)
	{
		Node *new_node = new Node(data);
		if (top == NULL)
		{
			top = new_node;
			count = 1;
		}
		else
		{
			Node *iterator;
			iterator = top;
			while (iterator->next != NULL)
			{
				iterator = iterator->next;
			}
			iterator->next = new_node;

		}
	}
	void removeBack()
	{
		Node* iterator = top;        /////this time it points to previouse node
		Node* temp = top;

		while (iterator->next->next != NULL)
		{
			iterator = iterator->next;
		}
		iterator->next = NULL;//next to last dereference
		iterator = iterator->next;//get last
		delete iterator;//delete it
	}
	void removeFront()
	{
		Node *iterator = top;
		top = iterator->next;
		iterator->next = NULL;
		delete iterator;
	}
};