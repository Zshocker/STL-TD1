#include<iostream>
#include<deque>
#include<list>
#include<algorithm>
#include<stack>
using namespace std;
void Prgr1() {
	string buff;
	deque<string> Deq;
	do
	{
		cin >> buff;
		if (buff == "Stop")break;
		Deq.push_back(buff);
	} while (true);
	list<string> lst;
	for_each(Deq.begin(), Deq.end(), [&](string v) {lst.push_back(v); });
	lst.sort();
	//sort(lst.begin(), lst.end());
	for_each(lst.begin(), lst.end(), [](string v) {cout << v << ","; });
}
template<class T>
void Print_Stack(stack<T> St) {
	while (!St.empty())
	{
		cout << St.top();
		St.pop();
	}
}
template<class T>
stack<T>& Reverse_stack(stack<T> orj) {
	stack<T>* St = new stack<T>();
	while (!orj.empty())
	{
		St->push(orj.top());
		orj.pop();
	}
	return *St;
}
void Prgr2()
{
	stack<char> St;
	char buff;
	do
	{
		cin >> buff;
		if (buff == '\n')break;
		St.push(buff);
	} while (getchar()!='\n');
	stack<char>& Orj = Reverse_stack(St);
	if (Orj == St)
	{
		cout << "yes"; 
	}
}
int main() {
	
	Prgr2();
	return 0;	 
}