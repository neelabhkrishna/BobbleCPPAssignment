#include<bits/stdc++.h> 
#include<vector>
#include<cstring>
using namespace std;

int main(int argc, char *argv[])
{
	// Creating the file pointer for reading csv file
	ifstream ifile;
	string str1, str2;
	int flag;
	// To open the file in read mode, the file name is passed from the command line
	ifile.open("EnglishDictionary.csv", ios::in);
	
	// To create the vector for storing the string
	vector<string> row;
	
	string line, word, temp;
	
	// To take the input from the console
	cout<<"Enter the String:"<<endl;
	cin>>str1;
	
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
		
		// To compare the given string with the vector string
		if(strcmp(str1.c_str(), str2.c_str())==0)
		{
			flag = 1;
			break;
		}
	}
	
	// To check the condition, if the word is available or not in the given dictionary
	if(flag == 1)
		cout<<"YES,"<<row[1]<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
