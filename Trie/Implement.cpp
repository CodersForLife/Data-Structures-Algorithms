#include <bits/stdc++.h>
using namespace std;
#define MAX 26
class Node {
private:
  bool isEmpty()
  {
    for (size_t i = 0; i < MAX; i++) {
      if (this->child[i] != NULL)
      {
        return false;
      }
    }
    return true;
  }
public:
  Node *child[MAX]{NULL};
  int countWords;
  Node ()
  {
    this->countWords = 0;
  }
  void addWord(string s)
  {
    int ch;
    Node* tmp = this;
    for (int i = 0;i < s.size();i++)
    {
      ch = s[i] - 'a';
      if (tmp->child[ch] == NULL)
      {
        tmp->child[ch] = new Node();
      }
      tmp = tmp->child[ch];
    }
    tmp->countWords++;
  }

  bool findWord(string s)
  {
    int ch;
    Node *tmp = this;
    for (int i = 0;i < s.size();i++)
    {
      ch = s[i] - 'a';
      if (tmp->child[ch] == NULL)
      return false;
      tmp = tmp->child[ch];
    }
    return tmp->countWords > 0;
  }
  bool removeWord(string s,int level,int len)
  {
    if (!this)
      return false;
    int ch = s[level] - 'a';
    if (level == len)
    {
      if (this->countWords > 0)
      {
        this->countWords--;
        return true;
      }
      return false;
    }
    int flag = this->child[ch]->removeWord(s,level+1,len);
    if (flag && (this->child[ch]->countWords > 0 && (this->child[ch]->isEmpty())))
    {
      delete this->child[ch];
      this->child[ch] = NULL;
    }
    return flag;
  }
  void printWord(string s)
  {
    if (this->countWords > 0)
    {
      cout << s << endl;
    }
    for (int i = 0;i < MAX;i++)
    {
      if (this->child[i])
      {
        this->child[i]->printWord(s + char('a' + i));
      }
    }
  }
};

class Node;

int main() {
  Node *deck = new Node();
  deck->addWord("the");
  deck->addWord("bigo");
  deck->printWord("");
  // cout << "find big0" << endl;
  // cout << deck->findWord("bigo") << endl;
  // cout << "rm the" <<endl;
  // deck->removeWord("the",0,3);
  // cout << deck->findWord("the") << endl;
  delete deck;
  return 0;
}
