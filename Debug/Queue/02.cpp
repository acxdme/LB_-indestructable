// Index of first non-repeating character

#include <iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;


int firstUniqChar(string s) {
  vector<int> c(26,0);
  queue<char> q;
  
  for(auto i:s){
      c[i - 'a']++; //fix: index is numbering based a - 0 , b -1 .... , z -25;
      q.push(i);
  }
  
  int idx=0;

  while(!q.empty()){
      auto elem = q.front();
      q.pop();
      
      if(c[elem -'a'] != 1){ //fix: index is numbering based a - 0 , b -1 .... , z -25;
          idx++;
      }
      else{
          break; // fix :  if unique break.
      }
  }
  for(int i =0 ; i < 26 ;i++){
    cout<<c[i]<< " ";
  }cout<<endl;
 return idx;
}

int main() {

  string s = "aabbccddeeffgghhiijjkklmmnnooppqqrrssttuuvvwwxxyyzz";
  int index =  firstUniqChar(s);
  if(index >= s.size()){
     cout<<"all characters are duplicate"<<endl;
  }
  else{
  cout<<"index is : "<<index<<endl;
  }
  
  return 0;
}


//----------------------------------------------------------------------------------------------------------------

//official answer

int firstUniqChar(string s) {
        vector<int> c(26,0);
        queue<char> q;
       
        for(auto i:s){
            c[i-'a']++;
            q.push(i);
        }
        
        int idx=0;
      
        while(!q.empty()){
            auto elem=q.front();
            q.pop();
            
            if(c[elem-'a']==1){
               return idx; // better return if found
            }else{
                idx++;
            }
        }
        return -1; // return -1 if not found
    }
