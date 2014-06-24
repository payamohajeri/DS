#include "HCT.h"
#include <iostream>

using namespace std;


int main()
{
	HCT myHCT0(8);
	myHCT0.printCodes();
	myHCT0.deCode("10100101");
	myHCT0.deCode("111111001110111101");
	myHCT0.enCode("deed");
	myHCT0.enCode("muck");
	return 0;
}