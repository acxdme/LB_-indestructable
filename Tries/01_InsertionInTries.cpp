// insertion in tries
// Time complexity : O(L) , L is the length of the string input.
// Space complexity : O(L*K) , K is the number of string and L is the length of the string.

#include <iostream>
using namespace std;

// data is ranging b/w [A,Z]

class TrieNode{
 public:
   char data;
   TrieNode* children[26];
   bool isTerminal;

   TrieNode(char data){
        this->data = data;
        for(int i =0 ; i < 26 ; i++){
          children[i] = NULL;
        }
        this->isTerminal = false;
   }
};

void insert(TrieNode* root , string str){
  // cout<<str<<" -"<<endl;
  if(str.size() == 0){
     cout<<root->data<<" "<<endl;
     root->isTerminal  = true;
     return;
  }
  char ch = str[0];
  TrieNode* child = NULL;
  
  // children present
  if(root->children[ch - 'A']){
     child = root->children[ch - 'A'];
  }
  else{ // children absent
      child = new TrieNode(ch);
      root->children[ch - 'A'] = child;
  }

  // recursive call
  insert(child,str.substr(1));

}

int main() {
  TrieNode* root = new TrieNode('-');
  // cout<<root->data;

  insert(root,"AYUSH");
  insert(root,"AYUSHI");
  insert(root,"PIYUSH");
  return 0;
}
