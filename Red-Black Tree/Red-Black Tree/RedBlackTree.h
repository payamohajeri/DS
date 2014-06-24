#include "Node.h"


class RedBlackTree
{

private:
	Node* root;
	Node* nil;
	int nodeCounter;
	Node* searchHelp(Node*,int);
	void traverse(Node*,char);
	void rotateLeft(Node*);
	void rotateRight(Node*);
	void redBlackInsertFixup(Node*);
	void transplant(Node*,Node*);
	void redBlackRemoveFixup(Node*);

public:
	RedBlackTree(int);
	bool search(int);
	int minimum();
	int maximum();
	int successor(int);
	int predecessor(int);
	int size();
	void preorder();
	void inorder();
	void postorder();
	void insert(int);
	bool remove(int);

};