/**
 Time complexity : O(N)
 Space complexity : O(N) , considering recursive
**/

class Solution {
public:

    void solve(string& num1 ,string &num2,int p1 ,int p2,int carry ,string& result){
        if(p1 < 0 && p2 < 0 && carry == 0) return;
        int sum = 0;
        if(p1 >= 0){
            sum += num1[p1] -'0';
            p1--;
        }
        if(p2 >= 0 ){
            sum += num2[p2] - '0';
            p2--;
        }
        
        sum = sum + carry;
        carry = sum / 10;
        sum = sum % 10;

        string t = to_string(sum);
        result += t;

        solve(num1,num2,p1,p2,carry,result);

        
    }
    string addStrings(string num1, string num2) {

        int carry = 0;
        string result;
        int p1 = num1.size()-1;
        int p2 = num2.size()-1;
        solve(num1,num2,p1,p2,carry,result);
        reverse(result.begin(),result.end());
        return result;
        
    }
};
