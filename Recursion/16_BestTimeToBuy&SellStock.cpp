// TC : O(N)
// SC : O(N)

class Solution {
public:
    void solveRe(vector<int>& prices,int &mn ,int& mxProfit,int i){
        if(i >= prices.size()) return;
        if(prices[i] < mn){
            mn = prices[i];
        }
        else{
            mxProfit = max(mxProfit,prices[i]-mn);
        }
        solveRe(prices,mn,mxProfit,i+1);

    }
    int maxProfit(vector<int>& prices) {
        int n  = prices.size();
        int mxProfit = 0 ;
        int mn = prices[0];
        solveRe(prices,mn,mxProfit,0);
        
        return mxProfit;
    }
};
