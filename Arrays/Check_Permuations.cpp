/*
Given two strings, check if they are permutations of each other. Return true or false.
Permutation means - length of both the strings should same and should contain same set of characters. Order of characters doesn't matter.
Note : Input strings contain only lowercase english alphabets.
Input format :

Line 1 : String 1
Line 2 : String 2

Sample Input 1 :

abcde
baedc

Sample Output 1 :

true

Sample Input 2 :

abc
cbd

Sample Output 2 :

false


*/

// input1 - first input string
// input2 - second input string
#include <bits/stdc++.h>
using namespace std;

bool isPermutation(char input1[], char input2[]) {
    // Write your code here
    int size1=strlen(input1),size2=strlen(input2);
    sort(input1,input1+size1);
    sort(input2,input2+size2);
    
    if(!strcmp(input1,input2))
        return true;
    else
        return false;

}

#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    char input1[1000], input2[1000];
    cin.getline(input1, 1000);
    cin.getline(input2, 1000);
    if(isPermutation(input1, input2) == 1) {
        cout << "true";
    }
    else {
        cout << "false";
    }
}

