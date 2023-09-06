// lc-658
// my approach , giving TLE , find lower-bound and move left and right.

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int index = n-1;
        vector<int> res;
        auto lowerBound  = lower_bound(arr.begin(),arr.end(),x);
        if(lowerBound != arr.end()){
            index = lowerBound - arr.begin();
            res.push_back(arr[index]);
            k--;
        }
        int l  = 1;
        int r = 1;
        while(k > 0){
            int left = INT_MAX;
            int right = INT_MAX;
            if(index - l  >= 0  ){
                left = abs(arr[index-l] - k);
            }
            if(index + r < n){
                right = abs(arr[index+r] - k);
            }
            if(right < left){
                r++;
                res.push_back(arr[index + r]);
                k++;
            }
            else if (left >= right){
                l--;
                res.push_back(arr[index - l]);
                k++;
            }
        }
        
        return res;
    }
};
