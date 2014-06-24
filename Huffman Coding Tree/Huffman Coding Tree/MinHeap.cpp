#include "MinHeap.h"


MinHeap::MinHeap(Node** dataBase , int m , int c)
{
	maxSize = m;
	current = c;
	heap = new Node*[maxSize];
	for (int i=0 ; i<current ; i++)
	{
		heap[i] = new Node(dataBase[i]->weight,dataBase[i]->left,dataBase[i]->right);
		heap[i]->data = dataBase[i]->data;
	}

	for (int i=(current/2) ; i>=0 ; i--)
		siftDown(i);
}

int MinHeap::leftChild(int pos)
{
	if (pos >= current || pos < 0)
		return -1;
	if (2*pos+1 < current)
		return (2*pos+1);
	return -1;
}

int MinHeap::rightChild(int pos)
{
	if (pos >= current || pos < 0)
		return -1;
	if (2*pos+2 < current)
		return (2*pos+2);
	return -1;
}

int MinHeap::parent(int pos)
{
	if (pos >= current || pos < 0)
		return -1;
	if (pos == 0)
		return -1;
	return ((pos-1)/2);
}

int MinHeap::littleChild(int pos)
{
	if (leftChild(pos) == -1)
		return -1;
	if (rightChild(pos) == -1)
		return leftChild(pos);
	if (heap[leftChild(pos)]->weight <= heap[rightChild(pos)]->weight)
		return leftChild(pos);
	return rightChild(pos);
}

void MinHeap::siftDown(int pos)
{
	int child = littleChild(pos);
	if (child == -1)
		return;
	if (heap[pos]->weight >= heap[child]->weight)
	{
		Node* temp = heap[child];
		heap[child] = heap[pos];
		heap[pos] = temp;
		siftDown(child);
	}
	return;
}

void MinHeap::siftUp(int pos)
{
	int p = parent(pos);
	if (p == -1)
		return;
	if (heap[p]->weight >= heap[pos]->weight)
	{
		Node* temp = heap[pos];
		heap[pos] = heap[p];
		heap[p] = temp;
		siftUp(p);
	}
	return;
}

Node* MinHeap::removeMin()
{
	if (current == 0)
		return 0;
	Node* temp = heap[0];
	heap[0] = heap[--current];
	siftDown(0);
	return temp;
}

void MinHeap::insert(Node* n)
{
	heap[current] = new Node(n->weight,n->left,n->right);
	heap[current]->data = n->data;
	current++;
	siftUp(current-1);
}

int MinHeap::size()
{
	return current-1;
}