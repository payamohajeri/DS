#include "MinHeap.h"


class HCT
{

private:
	Node* root;
	char* code;
	int codeCount;
	void printCodesHelp(Node*);
	void enCodeHelp(char,Node*);

public:
	HCT(int);
	void printCodes();
	void deCode(char*);
	void enCode(char*);

};