#include<iostream>
#include<deque>
#include<list>
#include<algorithm>
#include<stack>
#include<queue>
#include<unordered_map>
#include"Perssonne.h"
///-----------EX2---------
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
template<class T>
stack<T>& Reverse_stack_DEL(stack<T>& orj) {
	stack<T>* St = new stack<T>();
	while (!orj.empty())
	{
		St->push(orj.top());
		orj.pop();
	}
	return *St;
}
void Remove_Ponc_Esp(stack<char>& orj)
{
	stack<char> temp;
	while (!orj.empty())
	{
		char t = orj.top();
		if (!isspace(t) && !ispunct(t))temp.push(t);
		orj.pop();
	}
	orj = Reverse_stack_DEL(temp);
}




void Prgr2()
{
	stack<char> St;
	char buff;
	do
	{
		buff = getchar();
		if (buff == '\n')break;
		St.push(buff);
	} while (true);
	cout << "Inverser:";
	Print_Stack(St);
	stack<char>& Orj = Reverse_stack(St);
	Remove_Ponc_Esp(Orj);
	Remove_Ponc_Esp(St);
	if (Orj == St)
	{
		cout << endl << "la phrase originale est un palindrome";
	}
	else {
		cout << endl << "la phrase originale n'est pas un palindrome";
	}
}

void Prgrm3() {
	priority_queue<string, vector<string>, less<string>> Inst;
	string buff;
	cout << "Donner les Mots (Stop. pour finir)"<< endl;
	do
	{
		cin >> buff;
		if (buff == "Stop.")break;
		for_each(buff.begin(), buff.end(), [](char& car) {car = tolower(car); });
		Inst.push(buff);
	} while (true);
	while (!Inst.empty())
	{
		cout << " " << Inst.top();
		Inst.pop();
	}
}
//EXERCICE 2-------------------------------------
void Print_List(list<string>& Lst) 
{
	for (auto it : Lst)
	{
		cout << it << endl;
	}
}
string TransString(string& S) {
	string Sst=S;
	transform(S.begin(), S.end(), Sst.begin(), [](const char& c) 
		{
			if (c == 'e' || c == 'a' || c == 'o' || c == 'i' || c == 'u' || c == 'y')return '*'; return c; 
		});
	return Sst;
}
void Ex2_Prgrm() 
{
	list<string> Lst = {"Hich","Soro","ceri","Sesse"};
	list<string> L2(Lst.size());
	list<string> L3(Lst.size()); 
	Print_List(Lst);
	transform(Lst.begin(), Lst.end(),L3.begin(), TransString);
	Print_List(L3);
	transform(Lst.begin(), Lst.end(), L2.begin(), [](string S) {string D = S; transform(S.begin(), S.end(), D.begin(), toupper); return D; });
	Print_List(L2);
}



/*-----------------------EX3-------------------------*/
template<class T,class e>
priority_queue<T, vector<T>, greater<T>>& GET_Ordered_Keys(unordered_multimap<T, e>& E)
{
	priority_queue<T,vector<T>,greater<T>>* EE = new priority_queue<T,vector<T>,greater<T>>();
	for (auto i : E)
	{
		EE->push(i.first);
	}
	return *EE;
}


int main() {
	
	unordered_multimap<string, Personne*> SE;
	Personne* eP = new Personne("Hicham Sentel", "Charaf", "0607459927");
	SE.insert(make_pair("Hicham",eP));
	SE.insert(make_pair("Sentel",eP));
	SE.insert(make_pair("Hamza",new Personne("Hamza", "Saada", "0752452427")));
	SE.insert(make_pair("Zak",new Personne("Zak", "Casa", "0645123498")));
	priority_queue<string, vector<string>, greater<string>>& ST = GET_Ordered_Keys<string,Personne*>(SE);
	while(!ST.empty())
	{
		auto it = SE.find(ST.top());
		cout << "Nom :" << it->first;
		it->second->Afficher_add_num();
		ST.pop();
	}
	return 0;	 
}