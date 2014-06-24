#include "HCT.h"
#include <iostream>

using namespace std;


HCT::HCT(int size)
{
	code = new char[1000];
	codeCount = 0;
	Node** dataBase = new Node*[size];
	char c;
	int f;
	for (int i=0 ; i<size ; i++)
	{
		cout<<"Enter character and its frequency: ";
		cin>>c>>f;
		dataBase[i] = new Node(f,0,0);
		dataBase[i]->data = c;
	}
	MinHeap HCTHeap(dataBase,size,size);

	Node* temp1;
	Node* temp2;
	Node* temp3;

	while (HCTHeap.size() >= 1)
	{
		temp1 = HCTHeap.removeMin();
		temp2 = HCTHeap.removeMin();
		temp3 = new Node(temp1->weight+temp2->weight,temp1,temp2);
		HCTHeap.insert(temp3);
	}

	root = temp3;
}

void HCT::printCodesHelp(Node* n)
{
	if (n->data != '\0')
	{
		code[codeCount] = '\0';
		cout<<n->data<<" : "<<code<<"\n\n";
		return;
	}
	if (n->left != 0)
	{
		code[codeCount] = '0';
		codeCount++;
		printCodesHelp(n->left);
	}
	codeCount--;
	if (n->right != 0)
	{
		code[codeCount] = '1';
		codeCount++;
		printCodesHelp(n->right);
	}
	codeCount--;
	return;
}

void HCT::printCodes()
{
	codeCount = 0;
	cout<<"\n\nCodes:\n\n";
	printCodesHelp(root);
}

void HCT::deCode(char* s)
{
	cout<<"\n\n"<<s<<" : ";
	codeCount = 0;
	Node* temp = root;
	while(s[codeCount] != '\0')
	{
		if (temp->data != '\0')
		{
			cout<<temp->data;
			temp = root;
		}
		else
		{
			if (s[codeCount] == '0')
			{
				temp = temp->left;
				codeCount++;
			}
			else
			{
				temp = temp->right;
				codeCount++;
			}
		}
	}
	cout<<temp->data<<"\n\n";
	return;
}

void HCT::enCodeHelp(char s , Node* n)
{
	if (n->left != 0)
	{
		code[codeCount] = '0';
		codeCount++;
		enCodeHelp(s,n->left);
	}
	if (n->right != 0)
	{
		code[codeCount] = '1';
		codeCount++;
		enCodeHelp(s,n->right);
	}
	if (n->data == s)
	{
		code[codeCount] = '\0';
		cout<<code;
		return;
	}
	else
		codeCount--;
	return;
}

void HCT::enCode(char* s)
{
	cout<<"\n\n"<<s<<endl;
	while (s[0] != '\0')
	{
		codeCount = 0;
		enCodeHelp(s[0],root);
		s++;
	}
	cout<<endl;
	return;
}