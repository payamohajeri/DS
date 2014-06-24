#include "RBTree.h"
#include <iostream>

using namespace std;


//Node class functions definition entry point.
Node::Node(int d , Node* l , Node* r)
{
	data = d;
	left = l;
	right = r;
	color = 'r';
}
//Node class functions definitions end ponit.


RBTree::RBTree(int d)
{
	Nil = new Node(0,0,0);
	Nil->color = 'b';
	root = new Node(d,Nil,Nil);
	root->color = 'b';
	Nil->left = root;
	Nil->right = root;
	nodeCount = 1;
}

void RBTree::insertHelp(Node* n , int d)
{
	if (d >= (n->data))
	{
		if (n->right == Nil)
		{
			n->right = new Node(d,Nil,Nil);
			nodeCount++;
			return;
		}
		insertHelp(n->right,d);
	}
	else
	{
		if (n->left == Nil)
		{
			n->left = new Node(d,Nil,Nil);
			nodeCount++;
			return;
		}
		insertHelp(n->left,d);
	}
	return;
}

void RBTree::insert(int d)
{
	insertHelp(root,d);
	Node* temp = searchHelp(root,d);
	if (temp->right->data == d)
		redBlackInsertFixup(temp->right);
	else
		redBlackInsertFixup(temp->left);
	return;
}

Node* RBTree::searchHelp(Node* n , int d)
{
	if (root->data == d)
		return Nil;

	if (d > (n->data))
	{
		if (n->right == Nil || n->right->data == d)
			return n;
		searchHelp(n->right,d);
	}

	else
	{
		if (n->left == Nil || n->left->data == d)
			return n;
		searchHelp(n->left,d);
	}
}

bool RBTree::search(int d)
{
	if ( (searchHelp(root,d)->left == Nil) && (searchHelp(root,d)->right == Nil) )
		return false;
	return true;
}

int RBTree::parent(int d)
{
	if (root->data == d)
		return -1;
	if ( (searchHelp(root,d)->left == Nil) && (searchHelp(root,d)->right == Nil) )
		return -1;
	return (searchHelp(root,d)->data);
}

void RBTree::traverse(Node* n , char t)
{
	switch (t)
	{
	case 'p':
		cout<<n->data<<"."<<n->color<<" ";
		if (n->left != Nil)
			traverse(n->left,'p');
		if (n->right != Nil)
			traverse(n->right,'p');
		break;
	case 'i':
		if (n->left != Nil)
			traverse(n->left,'i');
		cout<<n->data<<"."<<n->color<<" ";
		if (n->right != Nil)
			traverse(n->right,'i');
		break;
	case 'o':
		if (n->left != Nil)
			traverse(n->left,'o');
		if (n->right != Nil)
			traverse(n->right,'o');
		cout<<n->data<<"."<<n->color<<" ";
		break;
	default:
		break;
	}
	return;
}

void RBTree::preorder()
{
	traverse(root,'p');
	return;
}

void RBTree::inorder()
{
	traverse(root,'i');
	return;
}

void RBTree::postorder()
{
	traverse(root,'o');
	return;
}

int RBTree::size()
{
	return nodeCount;
}

int RBTree::successor(int d)
{
	Node* temp = searchHelp(root,d);
	if ((temp->left == Nil) && (temp->right == Nil))
		return -1;
	if (temp->left != Nil && temp->left->data == d)
		temp = temp->left;
	else
		temp = temp->right;

	if (temp->right == Nil)
		return -1;
	temp = temp->right;
	int tempData = temp->data;
	while (temp->left != Nil)
	{
		temp = temp->left;
		tempData = temp->data;
	}
	return tempData;
}

int RBTree::minimum()
{
	Node* temp = root;
	while (temp->left != Nil)
		temp = temp->left;
	return temp->data;
}

bool RBTree::rotateLeft(int d)
{
	Node* tempParent = searchHelp(root,d);
	char direction;
	if (tempParent->right == Nil && tempParent->left == Nil)
		return false;
	Node* temp;
	if (tempParent->right->data == d)
	{
		temp = tempParent->right;
		direction = 'r';
	}
	else
	{
		temp = tempParent->left;
		direction = 'l';
	}
	if (temp->right == Nil)
		return false;

	Node* beta = temp->right->left;
	if (direction == 'r')
	{
		tempParent->right = temp->right;
		if (tempParent == Nil)
			root = tempParent->right;
	}
	else
	{
		tempParent->left = temp->right;
		if (tempParent == Nil)
			root = tempParent->left;
	}
	temp->right->left = temp;
	temp->right = beta;
	return true;
}

bool RBTree::rotateRight(int d)
{
	Node* tempParent = searchHelp(root,d);
	char direction;
	if (tempParent->right == Nil && tempParent->left == Nil)
		return false;
	Node* temp;
	if (tempParent->right->data == d)
	{
		temp = tempParent->right;
		direction = 'r';
	}
	else
	{
		temp = tempParent->left;
		direction = 'l';
	}
	if (temp->left == Nil)
		return false;

	Node* beta = temp->left->right;
	if (direction == 'r')
	{
		tempParent->right = temp->left;
		if (tempParent == Nil)
			root = tempParent->right;
	}
	else
	{
		tempParent->left = temp->left;
		if (tempParent == Nil)
			root = tempParent->left;
	}
	temp->left->right = temp;
	temp->left = beta;
	return true;
}

void RBTree::redBlackInsertFixup(Node* n)
{
	Node* nParent0 = searchHelp(root,n->data);
	if (nParent0 == root || nParent0->color == 'b')
		return;
	Node* nParent1 = searchHelp(root,nParent0->data);
	Node* nUncle;
	char direction;
	if (nParent1->left == nParent0)
	{
		nUncle = nParent1->right;
		direction = 'r';
	}
	else
	{
		nUncle = nParent1->left;
		direction = 'l';
	}


	if (nParent0->color == 'r' && nUncle->color == 'r')
	{
		nParent0->color = 'b';
		nUncle->color = 'b';
		if (nParent1 != root)
			nParent1->color = 'r';
		redBlackInsertFixup(nParent1);
	}
	else
	{
		if (nParent0->right == n)
		{
			rotateLeft(nParent0->data);
			redBlackInsertFixup(nParent0);
		}
		else
		{
			nParent0->color = 'b';
			nParent1->color = 'r';
			if (nParent1->left == nParent0)
				rotateRight(nParent1->data);
			else
				rotateLeft(nParent1->data);
			redBlackInsertFixup(n);
		}
	}
}