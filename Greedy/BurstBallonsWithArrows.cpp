//leetcode 452
// time-complexity : O(n log n)

class Solution {
public:
    static bool cmp(vector<int>&a , vector<int>&b){
        return a[1] < b[1];
    }

    int solve(vector<vector<int>>& points){
        int count = 1;
        int endPoint = points[0][1];
        for(int i = 1; i<points.size();i++ ){
            if(points[i][0] > endPoint){
                count++;
                endPoint =  points[i][1];
            }
        }

        return count;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),cmp);
        int ans = solve(points);
        return ans;
    }
};
