#include <iostream>
using namespace std;

class TrieNode{
public: 
 char data;
 TrieNode* children[26];
 bool isTerminal;

 TrieNode(char data){
   this->data = data;
   for(int i =0 ; i < 26 ;i++){
    children[i] = NULL;
   }
   this->isTerminal = false;
 }

};

void insert(TrieNode* root , string str){
  //base-case
  if(str.size() == 0 ){
    root->isTerminal = true;
    return;
  }
  // initialize child
  TrieNode* child = NULL;
  // current char
  char ch = str[0];

  if(root->children[ch - 'A']){ // child exist
     child = root->children[ch - 'A'];
  }
  else{// child does not exists
      child = new TrieNode(ch);
      root->children[ch - 'A'] = child;
  }

  insert(child,str.substr(1));

}

bool search(TrieNode* root, string str)
{
  // base-case
  if(str.size() == 0){
     return root->isTerminal;
  }

  TrieNode* child = NULL;
  char ch = str[0];
  if(root->children[ch -'A']){
    child = root->children[ch -'A'];
  }
  else{
    return false;
  }

  return  search(child,str.substr(1));
}
int main() {
  TrieNode* root = new TrieNode('-');
  insert(root,"CODE");
  insert(root,"CODER");
  insert(root,"CODING");

  cout<< "isPresent: " << search(root,"CODING") <<endl;

  return 0;
}
