class Node
{

	friend class RBTree;

private:
	int data;
	Node* left;
	Node* right;
	char color;

public:
	Node(int,Node*,Node*);

};