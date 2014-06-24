class Node
{

	friend class RedBlackTree;

private:
	Node* parent;
	Node* left;
	Node* right;
	int data;
	char color;

public:
	Node(Node*,Node*,Node*,int);

};