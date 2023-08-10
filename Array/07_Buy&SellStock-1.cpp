// lc-121
// time-complexity : O(N)
// Space-complexity : O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n  = prices.size();
        int mxProfit = 0 ;
        int mn = prices[0];
        for(int i =0  ; i < n ; i++ ){
            if(prices[i] < mn){
                mn = prices[i];
            }
            else{
                mxProfit = max(mxProfit,prices[i]-mn);
            }
        }
        
        return mxProfit;
    }
};
