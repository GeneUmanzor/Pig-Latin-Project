#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

//**this code has the bonus feature included
//Genesis Umanzor
//2110 Data Structures

using namespace std;

string wToPL(string w)
{
	string vl = "aeiouAEIOU";
	string pun = ".,?!;:";
	string fL = w.substr(0,1);
	string lL = w.substr(w.length()-1,1);
	string nW = "";
	
	if(vl.find(fL) != string::npos)
	{
		nW = w + "way";
	}
	else
	{
		nW = w.substr(1,w.length()-1) + fL + "ay";
	}
	if(pun.find(lL) != string::npos)
	{
		nW = nW.substr(0,nW.length()-1) + lL;
	}
	w = nW;
	return w;
}

string senToPL(string &sen)
{
	vector<string> wds;
	string w = "";
	for(int i = 0; i < sen.length(); i++)
	{
		if(sen[i] == ' ')
		{
			wds.push_back(w);
			w = "";
		}
		else
		{
			w += sen[i];
		}
	}
	wds.push_back(w);
	sen = "";
	
	for(int i = 0; i < wds.size(); i++)
	{
		sen += wToPL(wds[i]) + " ";
	}
	
	sen = sen.substr(0, sen.length()-1);
	return sen;
};

void printPL(string &sen)
{
	senToPL(sen);
	cout << sen << endl;
}

int main()
{
	string sen;
	
	cout << "Enter a sentence to turn into Pig Latin: "<<endl;
	getline(cin, sen);

	while(sen != "quit")
	{
		printPL(sen);
	
		cout<<"Enter a sentence to turn into Pig Latin: "<<endl;
		getline(cin, sen);
	}
	return 0;
}
