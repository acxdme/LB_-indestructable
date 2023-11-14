// tc : O(2^N)
// sc : O(log N)

#include <iostream>
using namespace std;
void util(string &name , int i , int &n ,string ans){
  if(i >= n ){
    cout << ans<<",";
    return;
  }
  
  // exclude
  util(name,i+1,n ,ans);

  //include
  util(name,i+1,n,ans + name[i]);


}

void printSubsequences(string &name){
  int i = 0 ;
  int n = name.size();
  string ans;
  util(name,i,n,ans);
  cout << endl;
}


int main() {
   
  string name = "ab";
  printSubsequences(name);
  return 0;
}


//----------------------------------------------------------------
// is there any change if the sequence of include exlcude is changed  -> I could not observe any change.


// tc : O(2^N)
// sc : O(log N)

#include <iostream>
using namespace std;
void util(string &name , int i , int &n ,string ans){
  if(i >= n ){
    cout << ans<<",";
    return;
  }
  
    //include
  util(name,i+1,n,ans + name[i]);

  // exclude
  util(name,i+1,n ,ans);




}

void printSubsequences(string &name){
  int i = 0 ;
  int n = name.size();
  string ans;
  
  util(name,i,n,ans);
  cout << endl;
}


int main() {
   
  string name = "abc";
  printSubsequences(name);
  return 0;
}
