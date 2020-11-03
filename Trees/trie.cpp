#include<bits/stdc++.h>
using namespace std;
struct trienode{
        map<char,trienode*> children;
        bool endofword;
        trienode()
        {
            endofword=false;
        }
};
void insert(trienode *root,string word)
{
    trienode *current=root;
    for(int i=0;i<word.length();i++)
    {
        trienode *node=current->children[word[i]];
        if(!node)
        {
            node = new trienode();
            current->children[word[i]]=node;
        }
        current=node;
    }
    current->endofword=true;
}
bool prefixsearch(trienode *root, string word)
{
    trienode *current=root;
    for(int i=0;i<word.length();i++)
    {
        trienode *node=current->children[word[i]];
        if(!node)return false;
        current=node;
    }
    return true;
}
int main()
{
    trienode *root=new trienode();  
    insert(root,"harshita");
 	insert(root,"harsh");
 	insert(root,"sharma");
 	insert(root,"harry");
 	string p;
 	cout<<"Enter the prefix to be searched :";
 	cin>>p;
 	cout<<prefixsearch(root,p)<<endl;
 	return 0;

    return 0;
}