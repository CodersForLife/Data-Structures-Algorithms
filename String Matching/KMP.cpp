#include <bits/stdc++.h>

using namespace std;
void make_lps(int *lps, string &pattern){
    int j=0, i=1;
    lps[0]=0;
    while(i<pattern.length()){
        if(pattern[i]==pattern[j]){
            lps[i++]=(j++)+1;
        }
        else if(j>0){
            j=lps[j-1];
        }
        else{
            lps[i++]=0;
        }
    }
}

int match(string &orig, string &pattern, int *lps){
    int patt_index=0;
    int orig_index=0;
    while(orig_index<orig.length()){
        if(orig[orig_index]==pattern[patt_index]){
            orig_index++;
            patt_index++;
        }
        else if(patt_index==0){
            orig_index++;
        }
        else{
            patt_index=lps[patt_index-1];
        }
        if(patt_index==pattern.length()){
            return 1;
        }
    }
    return patt_index==pattern.length();
}

int main()
{
    // freopen("input.txt", "rd", stdin);
    string orig;
    cin>>orig;

    string pattern;
    cin>>pattern;
    int lps[pattern.length()];
    make_lps(lps, pattern);
    

    cout<<endl<<match(orig, pattern, lps);
    return 0;
}
