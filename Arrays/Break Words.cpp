/*
You are given a sentence contained in given string S. Write a function which will replace all the words within the sentence whose length is even and greater than equal to 4, with a space between the two equal halves of the word.
Space complexity should be O(1).
Input Format :

String S

Output Format :

Updated string

Constraints :
1 <= Length of S <= 10000
Sample Input :

Helloo world good morniing

Sample Output :

Hel loo world go od morn iing


*/

#include <bits/stdc++.h>
using namespace std;

void splitWord(string &word){
    int mid=word.size()/2;
    word.insert(mid," ");
}

void breakWords(char* S)
{
	/*
	 * Don't write main.
	 * Don't return or print anything.
	 * Changes should be done in the given string.
	*/
    string ans="";
    string word="";
    for(int i=0;S[i]!='\0';i++){
        
        if(S[i]!=' ' && S[i]!='\0')
            word+=S[i];
        else{
            if (word.size()>=4 && word.size()%2==0){
                splitWord(word);
            }
            ans+=word+" ";
            word="";
        }
    }
    strcpy(S,ans.c_str());
    
}


#include<iostream>
#include<string.h>
using namespace std;
#include"solution.h"
int main()
{
	char str[100000];
	cin.getline(str,100000);
	breakWords(str);
	cout<<str;
}
