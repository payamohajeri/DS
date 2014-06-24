#include "Node.h"


Node::Node(int w , Node* l , Node* r)
{
	weight = w;
	left = l;
	right = r;
	data = '\0';
}