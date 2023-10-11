// tc : O(2^n) 
// sc : o(n)
// lc-1239

class Solution {
public:

    bool uniqueChecker(string& permutation){
        int mp[26] = {0};
        for(int i=0 ; i< permutation.size() ; i++){
            mp[permutation[i] - 'a']++;
            if(mp[permutation[i] -'a'] > 1){
                return false;
            }
        }
        return true;
    }
    int permute(vector<string>& arr ,int& mask, int& size){
        string permutation = "";
        int i =0;
        while(i < size){
            if(mask & (1 << i)){
                permutation += arr[i];
            }
        
            i++;
        }

        bool checkUnique = uniqueChecker(permutation);
        if(checkUnique) return permutation.size();

        return 0;
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int res  = 0;
        for(int i = 0 ; i < (1<<n);i++){
            int ans = permute(arr,i,n);
             res = max(res,ans);

        }

        return res;
        
    }
};
