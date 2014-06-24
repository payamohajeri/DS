#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;


void createInputFile(char*);
void createFiles(char*,string,char*);
void merge(int*,int,int,int);
void mergeSort(int*,int,int);
void multiWayMerge(char*);


int main()
{
		createInputFile("SynoN.txt");
		createFiles("SynoN.txt","Output",".txt");
		multiWayMerge("SayeroN.txt");
		return 0;
}


void createInputFile(char* s)
{
		fstream inFile;
		inFile.open(s,ios::out);
		if (inFile.is_open())
		{
			srand(time(0));
			for (int i=0 ; i<10000 ; i++)
			{
						for (int j=0 ; j<10 ; j++)
								inFile<<rand()%1000000000<<" ";
						inFile<<"\n";
			}
			inFile.close();
			cout<<"File \""<<s<<"\" created successfully!"<<endl;
		}
		else
			cout<<"Could not create file \""<<s<<"\"\nProcedure failed!"<<endl;
		return;
}

void createFiles(char* in , string name , char* ext)
{
		fstream inFile;
		inFile.open(in,ios::in);
		int temp[10000];
		int counter = 10000;
		int fileCounetr = 48;
		while (counter == 10000)
		{
					counter = 0;
					while(counter < 10000 && inFile>>temp[counter])
							counter++;
					if (!counter)
						break;
					mergeSort(temp,0,counter-1);
					fstream outFile;
					string tempName = name;
					tempName.push_back(char(fileCounetr));
					tempName.append(ext);
					fileCounetr++;
					outFile.open(tempName,ios::out);
					if (outFile.is_open())
					{
							for (int i=0 ; i<counter ; i++)
										outFile<<temp[i]<<" ";
							outFile<<2147483647;
							outFile.close();
							cout<<"File \""<<tempName<<"\" created!"<<endl;
					}
					else
							cout<<"Could not create file \""<<tempName<<"\"\n"<<"Procedure failed!"<<endl;
		}
		inFile.close();
		return;
}

void merge(int* A , int a , int b , int c)
{
		int *temp1 = new(int[b-a+2]);
		for(int i=0 ; i<b-a+1 ; i++)
					temp1[i] = A[a+i];
		temp1[b-a+1] = 2147483646;

		int* temp2 = new(int[c-b+1]);
		for(int i=0 ; i<c-b ; i++)
					temp2[i] = A[b+1+i];
		temp2[c-b] = 2147483646;

		int t1 = 0;
		int t2 = 0;
		for(int i=a ; i<=c ; i++)
		{
					if(temp1[t1] <= temp2[t2])
					{
							A[i] = temp1[t1];
							t1++;
					}
					else
					{
							A[i] = temp2[t2];
							t2++;
					}
		}
}

void mergeSort(int* A , int a , int b)
{
		if (a==b)
					return;
		mergeSort(A,a,(a+b)/2);
		mergeSort(A,((a+b)/2+1),b);
		merge(A,a,(a+b)/2,b);
		return;
}

void multiWayMerge(char* n)
{
	int count;

	fstream outFile0("Output0.txt",ios::in);
	int temp0[10001];
	count = 0;
	while (outFile0>>temp0[count])
		count++;
	fstream outFile1("Output1.txt",ios::in);
	int temp1[10001];
	count = 0;
	while (outFile1>>temp1[count])
		count++;
	fstream outFile2("Output2.txt",ios::in);
	int temp2[10001];
	count = 0;
	while (outFile2>>temp2[count])
		count++;
	fstream outFile3("Output3.txt",ios::in);
	int temp3[10001];
	count = 0;
	while (outFile3>>temp3[count])
		count++;
	fstream outFile4("Output4.txt",ios::in);
	int temp4[10001];
	count = 0;
	while (outFile4>>temp4[count])
		count++;
	fstream outFile5("Output5.txt",ios::in);
	int temp5[10001];
	count = 0;
	while (outFile5>>temp5[count])
		count++;
	fstream outFile6("Output6.txt",ios::in);
	int temp6[10001];
	count = 0;
	while (outFile6>>temp6[count])
		count++;
	fstream outFile7("Output7.txt",ios::in);
	int temp7[10001];
	count = 0;
	while (outFile7>>temp7[count])
		count++;
	fstream outFile8("Output8.txt",ios::in);
	int temp8[10001];
	count = 0;
	while (outFile8>>temp8[count])
		count++;
	fstream outFile9("Output9.txt",ios::in);
	int temp9[10001];
	count = 0;
	while (outFile9>>temp9[count])
		count++;


	fstream outFile(n,ios::out);
	int counts[10] = {0,0,0,0,0,0,0,0,0,0};
	for (int c=1 ; c<=100000 ; c++)
	{
		int index = 0;
		int min =  temp0[counts[0]];
		if (temp1[counts[1]] < min)
		{
			min = temp1[counts[1]];
			index = 1;
		}
		if (temp2[counts[2]] < min)
		{
			min = temp2[counts[2]];
			index = 2;
		}
		if (temp3[counts[3]] < min)
		{
			min = temp3[counts[3]];
			index = 3;
		}
		if (temp4[counts[4]] < min)
		{
			min = temp4[counts[4]];
			index = 4;
		}
		if (temp5[counts[5]] < min)
		{
			min = temp5[counts[5]];
			index = 5;
		}
		if (temp6[counts[6]] < min)
		{
			min = temp6[counts[6]];
			index = 6;
		}
		if (temp7[counts[7]] < min)
		{
			min = temp7[counts[7]];
			index = 7;
		}
		if (temp8[counts[8]] < min)
		{
			min = temp8[counts[8]];
			index = 8;
		}
		if (temp9[counts[9]] < min)
		{
			min = temp9[counts[9]];
			index = 9;
		}
		counts[index]++;
		outFile<<min<<" ";
		if (c%10 == 0)
			outFile<<"\n";
	}
	outFile.close();
	cout<<"Output file (\""<<n<<"\") created successfully!"<<endl;
	return;
}