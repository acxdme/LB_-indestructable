// group anagrams
// O(N^2) approach

class Solution { // this solution is giving TLE
public:
    bool isEqual( string s1 , string s2){
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if( s1 == s2 ){
            return true;
        }
        return false;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int totalStrings = strs.size();
        vector<vector<string>> res;

        if(totalStrings == 1){
            res.push_back(strs);
            return res;
        }
        vector<int>visited(totalStrings,0);
        
        int i = 0;
        while(i < totalStrings) {
            string lead = strs[i];
            int k = i;
            vector<string> ans;
            while( k < totalStrings){
                if(!visited[k] && isEqual(lead,strs[k])){
                    ans.push_back(strs[k]);
                    visited[k] = 1;
                }
                k++;
            }
               if(ans.size() > 0)
                res.push_back(ans);

            i++;
        }
        
        return res;
    }
};


//attempt-2 

class Solution { // also giving TLE error
public:
    bool isEqual( string s1 , string s2){
        int a[26] ={0};
        
        for(int i = 0 ; i < s1.length() ; i++){
            a[s1[i] - 'a']++;
        }
        for(int i = 0 ; i < s2.length() ; i++){
            a[s2[i] - 'a']--;
        }

        for(int i =0 ; i < 26 ;i++){
            if(a[i] != 0) return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int totalStrings = strs.size();
        vector<vector<string>> res;

        if(totalStrings == 1){
            res.push_back(strs);
            return res;
        }
        vector<int>visited(totalStrings,0);
        
        int i = 0;
        while(i < totalStrings) {
            string lead = strs[i];
            int k = i;
            vector<string> ans;
            while( k < totalStrings){
                if(!visited[k] && isEqual(lead,strs[k])){
                    ans.push_back(strs[k]);
                    visited[k] = 1;
                }
                k++;
            }
               if(ans.size() > 0)
                res.push_back(ans);

            i++;
        }
        
        return res;
    }
};
