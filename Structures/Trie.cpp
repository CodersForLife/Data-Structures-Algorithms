//This a tries programme.
//To add a string, firstly declare a tries as tries {name}. Then to add a string s, call {name}.add_string{s}.
//To find count of a particular string, call {name}.find_count.


#include<bits/stdc++.h>


using namespace std;


class node{
    vector<node *> vec;
    char ch;
    int str_count;
public:
    node():str_count(0){
        vec.resize(26);
        for(int i=0;i<26;i++){
            vec[i]=NULL;
        }
    }
    node(char character){
        vec.resize(26);
        for(int i=0;i<26;i++){
            vec[i]=NULL;
        }
        ch=character;
        str_count=0;
    }
    friend class tries;
};

class tries{
    node* root;
public:
    tries(){
        root=new node('\0');
    }

    void add_string(string str){
        node* curr_node=root;
        for(int i=0;i<=str.size();i++){
            char curr_ch=str[i];
            if(curr_ch=='\0'){
                curr_node->str_count++;
                return;
            }
            if(!curr_node->vec[curr_ch-97]){
                curr_node->vec[curr_ch-97]=new node(curr_ch);
                curr_node=curr_node->vec[curr_ch-97];
            }
            else{
                curr_node=curr_node->vec[curr_ch-97];
            }
        }
    }

    int find_count(string str){
        node *curr_node=root;
        for(int i=0;i<=str.size();i++){
            char curr_ch=str[i];
            if(!str[i]){
                return curr_node->str_count;
            }
            if(!curr_node->vec[curr_ch-97]){
                return 0;
            }
            curr_node=curr_node->vec[curr_ch-97];
        }
    }
};

