// lc -424 , 1st attempt , missing some key logic , problem faced : alphabet can be anything from A to Z.
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        if(n <=2) return n;
        int mxLen = INT_MIN;
        int count = 0;
        int startIndex = 0;

        unordered_map<int,int> sMap;

        for(int i = 0 ; i < n; i++){
            sMap[s[i]]++;
            if(sMap[s[i]] == 1){
                count++;
                while(count > k){
                    sMap[s[startIndex]]--;
                    if(sMap[s[startIndex]] == 0){
                        count--;
                    }
                    startIndex++;
                }
            }
            mxLen = max(mxLen,i-startIndex+1);
        }

        return mxLen;
    }

};
//------------------------------------------------------------------------------------------
//Kafi non-intutive approach
// dry-run , marked as must revise.
int characterReplacement(string s, int k) {
        if(s.length() == 0) return 0;
        if(s.length() <= k) return s.length();
        unordered_map<char, int> m;
        int res = 0; int l = 0;
        int maxCount = 0;

        for(int i = 0; i < s.length(); i++){
            m[s[i]] ++;
            maxCount = max(maxCount, m[s[i]]);
            while(i - l + 1 - k > maxCount){
                m[s[l]] --;
                l++;
            }
            res = max(res, i-l+1);

        }
        return res;
    }
