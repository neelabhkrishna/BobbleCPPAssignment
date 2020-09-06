#include<bits/stdc++.h> 
#include<vector>
#include<string>
#include<cstring>
#define CHAR_SIZE 128
#define MAX 4999
using namespace std;

string str[MAX];
int k = 1;

class Trie
{
	public:
		// Data member of the class
		bool isLeaf;
		Trie *character[CHAR_SIZE];
		
		// Constructor
		Trie()
		{
			this->isLeaf = false;
			for(int i=0; i<CHAR_SIZE; i++)
				this->character[i] = NULL;
		}
		
		//Method of the Trie class
		void insert(string);
		bool search(string);
		string print(int);
};

void Trie::insert(string key)
{
	str[k] = key;
	k++;
	// start from the root node
	Trie *curr = this;
	for(int i=0; i<key.length();i++)
	{
		if(curr->character[key[i]] == NULL)
			curr->character[key[i]] = new Trie();
	
		// go to the next node
		curr = curr->character[key[i]];
	}
	curr->isLeaf = true;
}
// To print the string at the given index passed from the user
string Trie::print(int N)
{
	int k = MAX-1;
	for(;k>=1;k--)
	{
		if(k == N)
			return str[k];
	}
}

// Logic for searching
bool Trie::search(string key)
{
	Trie* curr = this;
	if(this==NULL)
		return false;
	for(int i=0; i<key.length(); i++)
	{
		curr = curr->character[key[i]];
		if(curr == NULL)
			return false;
	}
	return curr->isLeaf;	
}

int main(int argc, char *argv[])
{
	Trie obj;
	
	// Creating the file pointer for reading csv file
	ifstream ifile;
	string str1, str2;
	int flag, i = 0, N;
	// To open the file in read mode, the file name is passed from the command line
	ifile.open("EnglishDictionary.csv", ios::in);
	
	// To create the vector for storing the string
	vector<string> row;
	
	string line, word, temp;
	
	// Reading from the file row by row
	while(ifile >> temp)
	{
		// It is used to test the given string is available or not
		flag = 0;
		
		// To clear the row variable of vector
		row.clear();
		
		//To read the row from the EnglishDictionary.csv file and copy it into line variable
		getline(ifile, line);
		
		// It is used to break the word from the csv file
		stringstream s(temp);
		
		// To read column data from the row and store each into the word variable
		while(getline(s, word, ','))
		{
			row.push_back(word); // store each word in the vector<string>
		}
		str2 = row[0]; // To store the vector string into the string variable
		
		obj.insert(str2);
		
	}
	cout<<"Enter Number:"<<endl;
	cin>>N;
	
	// To check the string using given number and print the string
	string str = obj.print(N);
	
	if(obj.search(str))
		cout<<"String:"<<str<<endl;
	else
		cout<<"Not Found"<<endl;
	return 0;
}
