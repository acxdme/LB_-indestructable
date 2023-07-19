// time-complexity : O(N* log(N) )
// lc-2144
class Solution {
public:
    int minimumCost(vector<int>& cost) { // 1 3 3 3
        int n = cost.size();
        if( n == 1 ) return cost[0];
        if( n == 2 ) return cost[0] + cost[1];
        sort(cost.begin(),cost.end());
        int end = n-1;
        int totalCost = 0;
        while(end >= 0){
            totalCost += cost[end--];
            if(end >= 0){
             totalCost += cost[end--]; 
            }else{
                break;
            }
            end--;
        }
    return totalCost;
    }
};
