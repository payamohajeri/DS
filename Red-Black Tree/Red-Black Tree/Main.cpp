#include "RedBlackTree.h"
#include <iostream>

using namespace std;


int main()
{
	RedBlackTree myRBT(100);
	myRBT.insert(200);
	myRBT.insert(300);
	myRBT.insert(50);
	myRBT.insert(75);
	myRBT.insert(400);
	myRBT.insert(350);
	myRBT.insert(25);
	myRBT.insert(55);
	myRBT.remove(55);
	myRBT.remove(50);
	myRBT.insert(110);
	myRBT.insert(95);
	myRBT.remove(100);
	myRBT.remove(75);
	myRBT.remove(200);
	myRBT.preorder();
	return 0;
}