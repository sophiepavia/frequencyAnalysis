#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;
bool sortTop(const pair<string, int> &a, const pair<string, int> &b) 
{ return (a.second > b.second); } 
bool sortTopC(const pair<char, int> &a, const pair<char, int> &b) 
{ 
	if(a.second == b.second)
		return a.first < b.first;
	return (a.second > b.second); 
}
template <typename T>
void print(vector<pair<T,int>> v, string type);

void sort(unordered_map<string, int> m, vector<string> io, string type);
void sortC(unordered_map<char, int> m);
void readIn(unordered_map<char, int> &characters, 
			unordered_map<string, int> &words, 
			unordered_map<string, int> &numbers, 
			vector<string> &insertOrder,vector<string> &insertOrder2);

int main() 
{
	unordered_map<char, int> characters;
	unordered_map<string, int> words;
	unordered_map<string, int> numbers;
	vector<string> insertOrder;
	vector<string> insertOrder2;
	
	readIn(characters, words, numbers, insertOrder, insertOrder2);
	sortC(characters);
	sort(words, insertOrder, "words");
	sort(numbers, insertOrder2, "numbers");
}
void readIn(unordered_map<char, int> &characters, 
			unordered_map<string, int> &words, 
			unordered_map<string, int> &numbers, 
			vector<string> &insertOrder,vector<string> &insertOrder2)
{

	
	char ch;
	string word = "";
	string number = "";
	int i = 0;
	while(!cin.eof())
	{
		ch = cin.get();
		characters[ch]++;
		
		if(!cin.peek() && ch == '\n')
			break;
	
		if(isalpha(ch))
		{
			ch = tolower(ch);
			word += ch;
		}
		if(isdigit(ch))
			number += ch;
	
		if(word != "" && !isalpha(ch))
		{
			//int i =0;
			words[word]++;
			if(words[word] == 1)
				insertOrder.push_back(word);
			word = "";
		}
		if(number != "" && !isdigit(ch)) 
		{
			numbers[number]++;
			if(numbers[number] == 1)
				insertOrder2.push_back(number);
			number = "";
		}
	}
}
void sort(unordered_map<string, int> m, vector<string> io, string type)
{
	vector <pair<string, int>> v;
	
	for (int i = 0; i < io.size(); ++i)
	{
		const string &s = io[i];
		v.push_back(make_pair(s, m[s]));
	}
	cout << endl;
	
	stable_sort(v.begin(), v.end(), sortTop);

	print(v, type);
}

void sortC(unordered_map<char, int> m)
{
	
	vector <pair<char, int>> v;
	
	unordered_map<char, int>:: iterator itr;
	for(itr=m.begin(); itr!=m.end(); itr++)
	{
		v.push_back(make_pair(itr->first, itr->second));
	}
	
	sort(v.begin(), v.end(), sortTopC);
	print(v, "characters");
}

template <typename T>
void print(vector<pair<T,int>> v, string type)
{
	string front;
	int max = 10;
	if(v.size() < 10)
		max = v.size();
		
	cout << "Total " << v.size() << " different " << type << ", ";
	cout << max <<  " most used " << type << ": " << endl;
	for(int i = 0; i < max; i++)
	{
		front = v[i].first;
		if(front == "\n")
			front = "\\n";
			
		if(front == "\t")
			front = "\\t";
		
		cout << "No. " << i << ": " << front;
		cout << "\t\t" << v[i].second << endl;
		
	}
}
