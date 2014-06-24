class Node
{

	friend class MinHeap;
	friend class HCT;

private:
	Node* left;
	Node* right;
	int weight;
	char data;

public:
	Node(int,Node*,Node*);

};