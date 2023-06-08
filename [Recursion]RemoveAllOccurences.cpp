/*
  Time complexity : O(M*N), har index pe rakh ke compare kar rahe hai bhai.
  Space complexity : O(N)
*/


class Solution {
public:

    void solve(string& s, string& part){
    //    cout<<s<<" ";
       if(s.find(part)!= string::npos){
           int index = s.find(part);
             s = s.substr(0,index) + s.substr(index+part.length());

            solve(s,part);
       }
        
        
    }
    string removeOccurrences(string s, string part) {

        string ans;
        solve(s,part);


        return s;
        
    }
};
