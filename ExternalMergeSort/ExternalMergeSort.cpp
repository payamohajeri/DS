#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

//#define RAND_MAX 500;
#define MAX_MEMORY 100;
#define MAX_FILE 1000;
#define BUFFER 40;

int TempFileNo = 48;

void bubbleSort(int* A , int low , int high)
{
	for (int i=high ; i>=0 ; i--)
	{
		for (int j=i ; j<high-1 ; j++)
		{
			if (A[j+1] < A[j])
			{
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
	return;
}
void merge(int a[], const int low, const int mid, const int high)
{
 
	int * b = new int[high+1-low];
	int h,i,j,k;
	h=low;
	i=0;
	j=mid+1;

	while((h<=mid)&&(j<=high))
	{
		if(a[h]<=a[j])
		{
			b[i]=a[h];
			h++;
		}
		else
		{
			b[i]=a[j];
			j++;
		}
		i++;
	}
	
	if(h>mid)
	{
		for(k=j;k<=high;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	else
	{
		for(k=h;k<=mid;k++)
		{
			b[i]=a[k];
			i++;
		}
	}

	for(k=0;k<=high-low;k++) 
	{
		a[k+low]=b[k];
	}
	delete[] b;
}

void merge_sort(int a[], const int low, const int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(a, low,mid);
		merge_sort(a, mid+1,high);
		merge(a, low,mid,high);
	}
}

void create_rand_file(char * filename)
{
	
	ofstream MyFile (filename , ios::out | ios::trunc);
	int size = MAX_FILE;
	if(MyFile.is_open())
	{
		srand(time(0));
		for (int i=0 ; i< size ; i++)
		{
			MyFile << rand()%10000 << endl;
		}	
	}
	else
	{
		cout << "Unable To Create a random file !!!" << endl;
	}
}

void create_temp_file(int * array)
{
	int size = MAX_MEMORY;
	int number = TempFileNo;
	
	char ext[] = ".txt";
	
	string filename = "output-";
	filename.push_back(char(number));
	filename.append(ext);
	
	//cout << filename << endl;
	
	int size2 = filename.size();
	char temp[100];
	for (int j=0;j<size2+1;j++)
	{
		temp[j]=filename[j];
	}
	temp[size2+1] = '\0';
	char * filename2 = temp;
	cout<< filename2 << "\t Successfully Created! :D" << endl ;
	//char temp = (char) number;
	//char txt = ".txt";
	
	//char filename[100];
	
	//strcpy(filename, temp);
	//strcat(filename, txt);
	
	ofstream MyFile (filename2,ios::out);
	if(MyFile.is_open())
	{
		for (int i=0;i<size;i++)
		{
			MyFile << array[i] <<"\n";
		}
		MyFile.close();
		number++;
		TempFileNo = number ;
	}
	else
	{
		cout << "Unable To Create a temp file named : " << temp << endl;
	}
}

void create_sorted_file(int * array , int array_size)
{
	int size = array_size;
	ofstream MyFile ("SortedOutput.txt",ios::out | ios::ate | ios::app);
	if(MyFile.is_open())
	{
		for (int i=0;i<size;i++)
		{
			MyFile << array[i] << endl;
		}
		cout << "Sorted File Created Successfully! :D" << endl;
	}
	else
	{
		cout << "Unable to Open Sorted file ! " << endl;
	}
}

int main()
{
	char * filename2 = "random.txt";
	create_rand_file(filename2);
	int size = MAX_MEMORY;
	int filesize = MAX_FILE;
	string line;
	ifstream MyFile (filename2 , ios::in);
	char ch;
	int array[101];
	
	if (MyFile.is_open())
	{
		for (int i=1;i<(filesize/size)+1;i++)
		{
				for (int i=0;i<size;i++)
				{
					if (MyFile.eof())
						break;
					getline(MyFile,line);
					//cout << line << endl;//
					int number2 = line.size();
					char temp[100];
					for (int j=0;j<number2;j++)
					{
						temp[j]=line[j];
					}
					//cout << temp << endl;//
					array[i]=atoi(temp);
					//cout << array[i] << endl ;
				}
			//merge_sort(array , 0 , 99);
			bubbleSort(array,0,100);
			//cin >> ch ;
			//int * array2 = array;
			create_temp_file(array);
			//delete[] array2;
		}
	}
	else
	{
		cout << "unable to open file for read from !" << endl;
	}
	
	////////////////////////////////////////////////////////////
	
	int count;
	count=0;
	
	ifstream outFile0("output-0.txt",ios::in);
	int temp0[101];
	count = 0;
	while (outFile0>>temp0[count])
		count++;
	temp0[count]=123456789;	
	ifstream outFile1("output-1.txt",ios::in);
	int temp1[101];
	count = 0;
	while (outFile1>>temp1[count])
		count++;
	temp1[count]=123456789;
	ifstream outFile2("output-2.txt",ios::in);
	int temp2[101];
	count = 0;
	while (outFile2>>temp2[count])
		count++;
	temp2[count]=123456789;
	ifstream outFile3("output-3.txt",ios::in);
	int temp3[101];
	count = 0;
	while (outFile3>>temp3[count])
		count++;
	temp3[count]=123456789;
	ifstream outFile4("output-4.txt",ios::in);
	int temp4[101];
	count = 0;
	while (outFile4>>temp4[count])
		count++;
	temp4[count]=123456789;
	ifstream outFile5("output-5.txt",ios::in);
	int temp5[101];
	count = 0;
	while (outFile5>>temp5[count])
		count++;
	temp5[count]=123456789;
	ifstream outFile6("output-6.txt",ios::in);
	int temp6[101];
	count = 0;
	while (outFile6>>temp6[count])
		count++;
	temp6[count]=123456789;
	ifstream outFile7("output-7.txt",ios::in);
	int temp7[101];
	count = 0;
	while (outFile7>>temp7[count])
		count++;
	temp7[count]=123456789;
	ifstream outFile8("output-8.txt",ios::in);
	int temp8[101];
	count = 0;
	while (outFile8>>temp8[count])
		count++;
	temp8[count]=123456789;
	ifstream outFile9("output-9.txt",ios::in);
	int temp9[101];
	count = 0;
	while (outFile9>>temp9[count])
		count++;
	temp9[count]=123456789;


	fstream outFile("SortedOutput.txt",ios::out);
	int counts[10] = {0,0,0,0,0,0,0,0,0,0};
	for (int c=1 ; c<=1000 ; c++)
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
		cout << counts[index] << endl;
		outFile<<min<<endl;
		//if (c%10 == 0)
		//	outFile<<"\n";
	}
	
	outFile.close();
	cout<<"Output file (\""<<"SortedOutput.txt"<<"\") created successfully!"<<endl;
	
	////////////////////////////////////////////////////////////
	
	/*
	int FileArray[10011];
	char ext[] = ".txt";
	string filename1 = "output-";
	int size2;
	char temp1[100];
	int count = 0 ;
	int index[filesize/size+1];
	index[0]=0;
	////////////////////////////////////////
	for (int i=0;i<(filesize/size);i++)
	{
		int number1 = i+48;
		
		filename1 = "output-";
		filename1.push_back(char(number1));
		filename1.append(ext);
		
		size2 = filename1.size();
		
		for (int j=0;j<size2+1;j++)
		{
			temp1[j]=filename1[j];
		}
		
		temp1[size2+1] = '\0';
		char * tempp1 = temp1;
		
		//////////////////////////////////
		cout << "Opening File name : \t" <<tempp1 << endl;
		
		ifstream MyFile1 (tempp1 , ios::in);
		
		while (MyFile1>>FileArray[count])
		{
			count++;
		}

		index[i+1]=count+1;
		FileArray[count]=1234567890;
	}
	
	int SortedArray[filesize+1];
	int Fileindex;
	int NO;
	int min;
	
	FileArray[0] = 9999;
	
	for (int i=0;i<count;i++)
	{
		//cout << FileArray[i] << endl;
		min = FileArray[index[0]];
		cout << index[0] << endl;
		
		for (int k=1 ; k<(filesize/size) ; k++)
		{
			//cout << "FOR" << endl;
			Fileindex = index[k];
			cout << "\t" <<index[k] << endl;
			NO = FileArray[Fileindex];
			//cout << "\t" << NO << endl;
			//cout << min << endl;
			if ( NO < min)
			{
				cout << NO << "\t" << min << endl;
				//cout << "OOMAD" << endl;
				//cout << "\t" << index[j] << endl;
				min = NO;
				index[k]+=1;
				//cout << index[j] <<endl;
			}
			if (NO == min)
			{
				index[k]+=1;
			}
		}
		index[0]=index[0]+1;
		cout << min << endl ;
		SortedArray[i] = min;
	}
	*/

	/*
	cout << count << endl;
	//merge_sort(FileArray , 0 , count);
	create_sorted_file(SortedArray,count);
	*/
	return 0;
}
