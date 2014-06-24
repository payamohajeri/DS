#include "Node.h"


class MinHeap
{

private:
	Node** heap;
	int maxSize;
	int current;
	void siftDown(int);
	void siftUp(int);

public:
	MinHeap(Node**,int,int);
	int leftChild(int);
	int rightChild(int);
	int parent(int);
	int littleChild(int);
	Node* removeMin();
	void insert(Node*);
	int size();
};