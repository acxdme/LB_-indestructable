// Minimum window substring
// lc -76

class Solution {
public:
    string minWindow(string s, string p) {
        int n = s.size();
        int m = p.size();
        int startIndex = 0;
        int minLen = INT_MAX;
        int ansIndex = -1;

        if(m > n){
            return "";
        }

        unordered_map<char,int> sMap;
        unordered_map<char,int> pMap;

        for(int i = 0 ; i < m ;i++){
            pMap[p[i]]++;
        }

        int count = 0 ;
        for(int i = 0  ;i < n; i++){
            sMap[s[i]]++;
            if( sMap[s[i]] <= pMap[s[i]]){
                count++;
            }

            if(count == m){
               
               while( sMap[s[startIndex]]  > pMap[s[startIndex]] || pMap[s[startIndex]] == 0 )
               {
                   if(sMap[s[startIndex]]  > pMap[s[startIndex]])
                    sMap[s[startIndex]]--;
                   startIndex++;
               }
               
                int lengthOfWindow = i - startIndex + 1;
                if(lengthOfWindow < minLen ) {
                    minLen = lengthOfWindow;
                    ansIndex = startIndex;
                }


            }

        }

        if(minLen == INT_MAX){
            return "";
        }
        // cout<<minLen<<" "<<startIndex<<endl;

        return s.substr(ansIndex,minLen);
    }
};
