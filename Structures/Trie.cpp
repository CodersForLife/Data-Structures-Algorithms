#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define p pair<ll,ll>

struct Trie{
	bool  isEndOfWord;
	unordered_map<char,Trie*> mp;
};
Trie* getNewTrieNode(){
	Trie* node=new Trie;
	node->isEndOfWord=false;
	return node;
}
void  insert(Trie* &root,const string &s){
	if(root==NULL){
		root=getNewTrieNode();
	}
	Trie* temp=root;
	for(int i=0;i<s.length();i++){
		char c=s[i];
		if(temp->mp.find(c)==temp->mp.end()){
			temp->mp[c]=getNewTrieNode();
		}
		temp=temp->mp[c];
	}
	temp->isEndOfWord=true;
}
bool isEmpty(Trie* root){
	for(auto x:root->mp){
		if(x){
			return false;
		}
	}
	return true;
}

Trie* delete_node(Trie* root,string key,int depth){
	if(!root){
		return NULL;
	}
	if(depth==key.size()){
		if(root->isEndOfWord){
			root->isEndOfWord=false;
		}
		if(hasnochild(root)){
			delete(root);
			root=NULL;
		}
		return root;
	}
	root->mp[key[depth]]=delete_node(root->mp[key[depth]],key,depth+1);
	if(isEmpty(root)&& root->isEndOfWord==false){
		delete (root);
		root=NULL;
	}
	return root;
}
bool Search(Trie* root,const string &s){
	if(root==NULL){
		return false;
	}
	Trie* temp=root;
	for(int i=0;i<s.length();i++){
		temp=temp->mp[s[i]];
		if(temp==NULL){
			return false;
		}
	}
	return temp->isEndOfWord;
}
int main(){
	Trie* root=NULL;
	while(true){
		cout<<"Enter  \n1.insert\n2.Search\n3.delete\n4.Exit\n";
		int choice;
		cin>>choice;
		if(choice!=1 or choice!=2 or choice!=3){
			break;
		}
		string x;
		cin>>x;
		if(choice==1){
			insert(root,x);
		}
		else if(choice==2){
			if(Search(root,x)){
				cout<<"found\n";
			}
			else{
				cout<<"Not found\n";
			}
		}
		else if(choice==3){
			delete_node(root,x,0);
		}
	}
	return 0;
}
// int main(){
// 	fast;

// 	return 0;
// }
