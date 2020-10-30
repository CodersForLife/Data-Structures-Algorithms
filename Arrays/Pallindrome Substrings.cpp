/*
Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.
Input Format :

String S

Output Format :

count of palindrome substrings

Constraints :
1 <= Length of S <= 1000
Sample Input :

aba

Sample Output :

4

**Note : Here 4 corresponds to ("a","b","a","aba").

*/

#include <bits/stdc++.h>
using namespace std;


int countPalindromeSubstrings(char s[]) {
	// Write your code here
    string st(s);
    int c=0;
    
    //First Considering palindroms odd case
    for(int i=0;i<st.size();i++){
        int k=0;
        while (i-k>=0 && i+k<st.size()){
            if(st[i-k]==st[i+k])
                c++;
            else
                break;
            k++;
            }
        }
    
    //Now considering the even palindroms
    for(int i=0;i<st.size()-1;i++){
        
        if(st[i]==st[i+1]){
            int k=0;
            while (i-k>=0 && i+1+k<st.size()){
            if(st[i-k]==st[i+1+k])
                c++;
            else
                break;
            k++;
            }
        }
    }
    
    return c;
	
}

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;
}
