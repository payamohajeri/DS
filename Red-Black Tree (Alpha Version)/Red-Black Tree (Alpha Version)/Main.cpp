#include "RBTree.h"
#include <iostream>

using namespace std;


int main()
{
	RBTree myRBTree(100);
	myRBTree.insert(200);
	myRBTree.insert(300);
	myRBTree.insert(50);
	myRBTree.insert(75);
	myRBTree.insert(25);
	myRBTree.insert(400);
	myRBTree.insert(10);
	myRBTree.insert(5);
	myRBTree.preorder();
	cout<<endl;
	return 0;
}