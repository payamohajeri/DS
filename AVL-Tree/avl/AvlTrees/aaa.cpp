#include <iostream>
using namespace std;
#include <queue>

main(){
	queue<int> q;
	q.push(10);
	q.push(12);
	int a=q.front();
	cout<<a;
	q.pop();
	a=q.front();
	cout<<endl<<a;
	cin>>a;

}
