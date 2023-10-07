// tc : O(N)
// sc : O(N)
// lc-8

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        long long int ans = 0;
        bool negative = false;
        while( i  < n && s[i] == ' ' ){
            i++;
        }
        if(i >= n){
            return ans;
        }else{
            if(s[i] == '-' || s[i] == '+') {
                if(s[i] == '-') negative = true;
                i++;
            }
            while(i < n && (s[i] - '0' >= 0  && s[i] - '0'  <= 9)){
                int digit = s[i] - '0' ;
                ans = ans * 10 + digit;
                if( ans > INT_MAX  or  -ans < INT_MIN) break;
                i++;
            }
        }
        if(negative && ans != 0 ){
            ans = - ans;
            if(ans < INT_MIN) return INT_MIN;
            
        }
        if( ans > INT_MAX)  ans = INT_MAX;

        return ans;
    }
};
