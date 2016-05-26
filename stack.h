#pragma once

struct S_Node
{
public:
	int data;
	S_Node *next;

	S_Node(int p_data)
	{
		data = p_data;
		next = NULL;
	}
};

class stack
{
public:

	S_Node *push(S_Node *root,int p_data)
	{
		
		if (root == NULL)
		{
			S_Node *new_Node = new S_Node(p_data);
			root = new_Node;
			return root;			
		}
		S_Node *iterator = new S_Node(p_data);
		iterator->next = root;
		root = iterator;
		return root;

	}
	int front(S_Node *root)
	{
		if (root == NULL)
		{
			cout << "stack is empty"<<endl;
			return 0;
		}
		S_Node *iterator = root;
		int to_return = iterator->data;
		//iterator = iterator->next;
		//delete root;
		//root = iterator;
		return to_return;
	}
	S_Node *Pop(S_Node *root)
	{
		if (root == NULL)
		{
			cout << "stack is empty" << endl;
			return 0;
		}
		S_Node *iterator = root;
		int to_return = iterator->data;
		iterator = iterator->next;
		delete root;
		root = iterator;
		return root;
	}
	void print(S_Node *top)
	{
		S_Node *iterator = top;
		int count = 0;
		while (iterator != NULL)
		{
			cout << iterator->data << endl;
			iterator = iterator->next;
			count++;
		}
	}
};