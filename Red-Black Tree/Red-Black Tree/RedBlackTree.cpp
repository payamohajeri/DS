#include "RedBlackTree.h"
#include <iostream>

using namespace std;


RedBlackTree::RedBlackTree(int d)
{
	root = new Node(0,0,0,d);
	nil = new Node(root,0,0,0);
	nodeCounter = 1;
	root->left = nil;
	root->right = nil;
	root->parent = nil;
	root->color = 'b';
	nil->color = 'b';
}

Node* RedBlackTree::searchHelp(Node* n , int d)
{
	if (root->data == d)
		return root;
	if (n == nil)
		return nil;
	if (n->left->data == d|| n->right->data == d)
		return n;
	if (d >= n->data)
		return searchHelp(n->right , d);
	else
		return searchHelp(n->left , d);
}

void RedBlackTree::traverse(Node* n , char c)
{
	switch (c)
	{
	case 'p':
		cout<<n->data<<"."<<n->color<<" ";
		if (n->left != nil)
			traverse(n->left,c);
		if (n->right != nil)
			traverse(n->right,c);
		break;
	case 'i':
		if (n->left != nil)
			traverse(n->left,c);
		cout<<n->data<<"."<<n->color<<" ";
		if (n->right != nil)
			traverse(n->right,c);
		break;
	case 'o':
		if (n->left != nil)
			traverse(n->left,c);
		if (n->right != nil)
			traverse(n->right,c);
		cout<<n->data<<"."<<n->color<<" ";
		break;
	default:
		break;
	}
	return;
}

void RedBlackTree::rotateLeft(Node* n)
{
	if (n->right == nil)
		return;
	Node* y = n->right;
	n->right = y->left;
	if (y->left != nil)
		y->left->parent = n;
	y->parent = n->parent;
	if (n->parent == nil)
		root = y;
	else
	{
		if (n == n->parent->left)
			n->parent->left = y;
		else
			n->parent->right = y;
	}
	y->left = n;
	n->parent = y;
	return;
}

void RedBlackTree::rotateRight(Node* n)
{
	if (n->left == nil)
		return;
	Node* y = n->left;
	n->left = y->right;
	if (y->right != nil)
		y->right->parent = n;
	y->parent = n->parent;
	if (n->parent == nil)
		root = y;
	else
	{
		if (n == n->parent->left)
			n->parent->left = y;
		else
			n->parent->right = y;
	}
	y->right = n;
	n->parent = y;
	return;
}

void RedBlackTree::transplant(Node* u , Node* v)
{
	if (u->parent == nil)
		root = v;
	else
	{
		if(u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
	}
	v->parent = u->parent;
	return;
}

bool RedBlackTree::search(int d)
{
	if (searchHelp(root,d) == nil)
		return false;
	return true;
}

int RedBlackTree::minimum()
{
	Node* temp = root;
	while (temp->left != nil)
		temp = temp->left;
	return temp->data;
}

int RedBlackTree::maximum()
{
	Node* temp = root;
	while (temp->right != nil)
		temp = temp->right;
	return temp->data;
}

int RedBlackTree::successor(int d)
{
	Node* temp = searchHelp(root,d);
	if (temp == nil)
		return -1;
	if (temp->left->data == d)
		temp = temp->left;
	if (temp->right->data == d)
		temp = temp->right;
	if (temp->right == nil)
		return -1;
	else
	{
		temp = temp->right;
		while (temp->left != nil)
			temp = temp->left;
		return temp->data;
	}
}

int RedBlackTree::predecessor(int d)
{
	Node* temp = searchHelp(root,d);
	if (temp == nil)
		return -1;
	if (temp->left->data == d)
		temp = temp->left;
	if (temp->right->data == d)
		temp = temp->right;
	if (temp->left == nil)
		return -1;
	else
	{
		temp = temp->left;
		while (temp->right != nil)
			temp = temp->right;
		return temp->data;
	}
}

int RedBlackTree::size()
{
	return nodeCounter;
}

void RedBlackTree::preorder()
{
	traverse(root,'p');
	cout<<endl;
}

void RedBlackTree::inorder()
{
	traverse(root,'i');
	cout<<endl;
}

void RedBlackTree::postorder()
{
	traverse(root,'o');
	cout<<endl;
}

void RedBlackTree::insert(int d)
{
	Node* temp0 = root;
	Node* temp1 = nil;
	while (temp0 != nil)
	{
		temp1 = temp0;
		if (d > temp0->data)
			temp0 = temp0->right;
		else
			temp0 = temp0->left;
	}
	Node* temp = new Node(0,0,0,0);
	temp->parent = temp1;
	if (temp1 == nil)
		root = temp;
	else
	{
		if (d < temp1->data)
			temp1->left = temp;
		else
			temp1->right = temp;
	}
	temp->left = nil;
	temp->right = nil;
	temp->data = d;
	temp->color = 'r';
	redBlackInsertFixup(temp);
	return;
}

void RedBlackTree::redBlackInsertFixup(Node* n)
{
	if (n == root || n->parent->color == 'b')
		return;
	Node* uncle;
	if (n->parent->parent->left == n->parent)
		uncle = n->parent->parent->right;
	else
		uncle = n->parent->parent->left;


	if (n->parent->color == 'r' && uncle->color == 'r')
	{
		n->parent->color = 'b';
		uncle->color = 'b';
		if (n->parent->parent != root)
			n->parent->parent->color = 'r';
		redBlackInsertFixup(n->parent->parent);
	}
	else
	{
		if (n->parent->right == n)
		{
			n = n->parent;
			rotateLeft(n);
			redBlackInsertFixup(n);
		}
		else
		{
			n->parent->color = 'b';
			n->parent->parent->color = 'r';
			if (n->parent->parent->left == n->parent)
				rotateRight(n->parent->parent);
			else
				rotateLeft(n->parent->parent);
			redBlackInsertFixup(n);
		}
	}
	return;
}

bool RedBlackTree::remove(int d)
{
	Node* temp = searchHelp(root,d);
	if (temp->left == nil &&  temp->right == nil)
		return false;
	if (temp->right->data == d)
		temp = temp->right;
	else
	{
	if (temp->left->data == d)
		temp = temp->left;
	}
	Node* yTemp = temp;
	Node* xTemp;
	char originalColor = yTemp->color;


	if (temp->left == nil)
	{
		xTemp = temp->right;
		transplant(temp,temp->right);
		if (originalColor == 'b')
			redBlackRemoveFixup(xTemp);
		return true;
	}

	if (temp->right == nil)
	{
		xTemp = temp->left;
		transplant(temp,temp->left);
		if (originalColor == 'b')
			redBlackRemoveFixup(xTemp);
		return true;
	}

	yTemp = temp->right;
	while (yTemp->left != nil)
		yTemp = yTemp->left;
	originalColor = yTemp->color;
	xTemp = yTemp->right;
	if (yTemp->parent == temp)
		xTemp->parent = yTemp;
	else
	{
		transplant(yTemp,yTemp->right);
		yTemp->right = temp->right;
		yTemp->right->parent = yTemp;
	}
	transplant(temp,yTemp);
	yTemp->left = temp->left;
	yTemp->left->parent = yTemp;
	yTemp->color = temp->color;
	if (originalColor == 'b')
		redBlackRemoveFixup(xTemp);
	return true;
}

void RedBlackTree::redBlackRemoveFixup(Node* n)
{
	Node* w;
	while (n != root && n->color == 'b')
	{
		if (n->parent->left == n)
			w = n->parent->right;
		else
			w = n->parent->left;
		if (w->color == 'r')
		{
			w->color = 'b';
			n->parent->color = 'r';
			if (n->parent->left == n)
			{
				rotateLeft(n->parent);
				w = n->parent->right;
			}
			else
			{
				rotateRight(n->parent);
				w = n->parent->left;
			}
		}
		if (w->left->color == 'b' && w->right->color == 'b')
		{
			w->color = 'r';
			n = n->parent;
		}
		else
		{
			if (w->right->color == 'b')
			{
				w->left->color = 'b';
				w->color = 'r';
				rotateRight(w);
				if (n->parent->left == n)
					w = n->parent->right;
				else
					w = n->parent->left;
			}
			w->color = n->parent->color;
			n->parent->color = 'b';
			w->right->color = 'b';
			if (n->parent->left == n)
				rotateLeft(n->parent);
			else
				rotateRight(n->parent);
			n = root;
		}
	}
	n->color = 'b';
	return;
}