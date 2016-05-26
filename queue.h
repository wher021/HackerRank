#pragma once
#include <iostream>
using namespace std;
struct Q_Node
{
	int data;
	Q_Node *next;

	Q_Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

class Queue
{
public:
	Q_Node *push(Q_Node *root, int data)
	{
		if (root == NULL)
		{
			root = new Q_Node(data);
			return root;
		}
		Q_Node *iterator = root;
		while (iterator->next != NULL)
		{
			iterator = iterator->next;
		}
		iterator->next = new Q_Node(data);
		return root;
	}
	int front(Q_Node *root)
	{
		if (root == NULL)
			return 0;
		return root->data;
	}
	Q_Node *Pop(Q_Node *root)
	{
		if (root == NULL)
			return root;
		Q_Node*tmp;
		tmp = root;
		root = root->next;
		delete tmp;
		return root;
	}
	void Print(Q_Node*root)
	{
		Q_Node *iterator = root;
		while (iterator != NULL)
		{
			cout << iterator->data << endl;
			iterator = iterator->next;
		}
	}
};