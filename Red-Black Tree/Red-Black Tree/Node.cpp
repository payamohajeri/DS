#include "Node.h"

Node::Node(Node* p , Node* l , Node* r , int d)
{
	parent = p;
	left = l;
	right = r;
	data = d;
	color = 'r';
}