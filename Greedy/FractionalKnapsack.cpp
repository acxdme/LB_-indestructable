//logic is ok , but TLE on gfg

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool  cmp(vector<double>&a  ,vector<double>&b){
        return a[2] > b[2];
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans = 0.0;
        vector<vector<double>>  rarr;
        for(int i = 0 ; i<n ;i++){
            vector<double> temp;
            temp.push_back(arr[i].value);
            temp.push_back(arr[i].weight);
             double ratio = (arr[i].value + 0.0) / (arr[i].weight + 0.0);
             temp.push_back(ratio);
             rarr.push_back(temp);
             
        }
        
        sort(rarr.begin(),rarr.end(),cmp);
        
        for(int i  = 0 ;i< n; i++){
            if(W == 0) break;
            if(rarr[i][1] <= W) {
                ans += rarr[i][0];
                W = W - rarr[i][1];
            }
            else{
                ans += W * rarr[i][2];
                W = 0;
            }
        }
        return ans;
    }
        
};

// reason for TLE also understood , because i can just check ratio on the fly , no need to store it.
