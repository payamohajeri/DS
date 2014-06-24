#include "Node.h"

class RBTree
{

private:
	Node* root;
	Node* Nil;
	int nodeCount;
	void insertHelp(Node*,int);
	Node* searchHelp(Node*,int);
	void traverse(Node*,char);
	bool rotateLeft(int);
	bool rotateRight(int);
	void redBlackInsertFixup(Node*);

public:
	RBTree(int);
	void insert(int);
	bool search(int);
	int minimum();
	int successor(int);
	int size();
	int parent(int);
	void preorder();
	void inorder();
	void postorder();

};