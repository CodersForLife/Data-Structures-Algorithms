/*
Given a string S, reverse each word of a string individually. For eg. if a string is "abc def", reversed string should be "cba fed".
Input Format :

String S

Output Format :

Updated string

Constraints :
1 <= Length of S <= 1000
Sample Input :

Welcome to Coding Ninjas

Sample Output:

emocleW ot gnidoC sajniN

*/

// input - given string
// Update in the given input itself. No need to return or print anything

#include <bits/stdc++.h>
using namespace std;

void swap(string &s,int i,int j){
    char temp=s[i];
    s[i]=s[j];
    s[j]=temp;
}

void reverse(string &s){
    int i=0;
    int j=s.size()-1;
    while (i<=j){
        swap(s,i,j);
        i++;
        j--;
    }
}

void reverseEachWord(char input[]) {
    // Write your code here
    string ans="";
    string word="";
    int start_flag=1;
    
    int size=strlen(input);
    
    for(int i=0;i<=size;i++){
        
        if(input[i]!=' ' && input[i]!='\0')
            word+=input[i];
        
        else{
            reverse(word);
            if(start_flag){
                start_flag=0;
                ans+=word;
                word="";
                continue;
            }
            ans+=' '+word;
            word="";            
        }
    }
    strcpy(input,ans.c_str());

}

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseEachWord(input);
    cout << input << endl;
}
