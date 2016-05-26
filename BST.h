#pragma once

#include <iostream>
#include <queue>

struct BSTNode
{
public:
	int data;
	BSTNode *left;
	BSTNode *right;
	BSTNode *right_neighbor;

	BSTNode(int p_data)
	{
		data = p_data;
		left = NULL;
		right = NULL;
		right_neighbor = NULL;
	}
};

class BST
{
public:
	BSTNode *insertnode(BSTNode *root, int data)
	{
		if (root == NULL)
		{
			root = new BSTNode(data);
			return root;
		}
		else
		{
			BSTNode *tmp = new BSTNode(data);

			BSTNode *iterator, *parent = NULL;
			iterator = root;
			bool found = false;
			while (iterator != NULL)
			{
				parent = iterator;//save parent nodes
				if (tmp->data <= iterator->data)
				{
					iterator = iterator->left;
				}
				else
				{
					iterator = iterator->right;

				}
			}
			if (data < parent->data)
			{
				parent->left = tmp;
			}
			else if (data > parent->data)
			{
				parent->right = tmp;
			}
		}
		return root;
	}
	void Search(BSTNode *root, int data)
	{
		BSTNode *iterator = root;
		bool found = false;
		while (iterator != NULL && !found)
		{
			if (data < iterator->data)
			{
				iterator = iterator->left;
			}
			else if (data > iterator->data)
			{
				iterator = iterator->right;
			}
			else if (data == iterator->data)
				found = true;
		}
		if (found)
			std::cout << "found" << std::endl;
		else
		{
			std::cout << "not found" << std::endl;
		}
	}

	void BST::preorderTraversal(BSTNode *subtreeRoot)
	{
		if (subtreeRoot != 0)
		{
			std::cout << subtreeRoot->data << "  ";  // V operation
			preorderTraversal(subtreeRoot->left);    // L operation
			preorderTraversal(subtreeRoot->right);   // R operation
		}
	}
	void BST::inorderTraversal(BSTNode *subtreeRoot)
	{
		if (subtreeRoot != 0)
		{

			inorderTraversal(subtreeRoot->left);    // L operation
			std::cout << subtreeRoot->data << "  "; // V operation
			inorderTraversal(subtreeRoot->right);   // R operation
		}
	}
	void BST::postorderTraversal(BSTNode *subtreeRoot)
	{
		if (subtreeRoot != 0)
		{

			postorderTraversal(subtreeRoot->left);    // L operation
			postorderTraversal(subtreeRoot->right);   // R operation
			std::cout << subtreeRoot->data << "  "; // V operation
		}
	}
	void levelorderTraversal(BSTNode *root)
	{
		if (root == NULL)
			return;
		queue<BSTNode*> myQueue;
		BSTNode *iterator;
		myQueue.push(root);

		while (!myQueue.empty())
		{
			iterator = myQueue.front();
			cout << iterator->data << endl;
			if (iterator->left != NULL)
			{
				myQueue.push(iterator->left);
			}
			if (iterator->right != NULL)
			{
				myQueue.push(iterator->right);
			}
			myQueue.pop();
		}
	}
	void PrintLevelOrder(BSTNode *root)
	{
		if (root == NULL)
		{
			return;
		}

		int levelNodes = 0;
		queue <BSTNode*>myQueue;
		myQueue.push(root);

		while (!myQueue.empty())
		{
			levelNodes = myQueue.size();
			while (levelNodes > 0) 
			{
				BSTNode *n = myQueue.front();
				myQueue.pop();
				cout << " " << n->data;
				if (n->left != NULL) myQueue.push(n->left);
				if (n->right != NULL) myQueue.push(n->right);
				levelNodes--;
			}
			cout << endl;
		}
	}
	void GenerateRightNeighbor(BSTNode *root)
	{
		if (root == NULL)
		{
			return;
		}

		int levelNodes = 0;
		queue<BSTNode*> myQueue;
		myQueue.push(root);

		while (!myQueue.empty())
		{
			int levelNodes = myQueue.size();
			BSTNode *node = myQueue.front();
			myQueue.pop();

			if (node->left != NULL)
				myQueue.push(node->left);
			if (node->right != NULL)
				myQueue.push(node->right);

			for (int i = 1; i < levelNodes; i++)//begins at 1 because aldready popped one from the staque!
			{
				BSTNode *nextNode = myQueue.front();
				myQueue.pop();
				node->right_neighbor = nextNode;
				node = nextNode;
				if (node->left != NULL)
					myQueue.push(node->left);
				if (node->right != NULL)
					myQueue.push(node->right);
			}
		}
	}
	int findHeight(BSTNode *root)
	{
		//base case
		if (root == NULL)
		{
			return -1;
		}

		int left = findHeight(root->left) + 1;
		cout << left << endl;
		int right = findHeight(root->right) + 1;

		if (left < right)
		{
			return right;
		}
		else
		{
			return left;
		}
		//	cout << left << endl;

	}
};