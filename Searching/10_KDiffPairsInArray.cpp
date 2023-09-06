// lc - 532
// binary search problem good one

class Solution {
public:
    int binarySearch(vector<int>& nums , int start , int end , int target){
        int mid = start + (end-start)/2;
        // cout<<start <<" "<<end <<" " << target<<endl;

        while(start <= end){
            if(nums[mid] == target){
                return mid;
            }
            else if (nums[mid] > target){
                end = mid -1 ;
            }
            else{
                // nums[mid] < target
                start = mid + 1;
            }
            mid = start + (end-start)/2;
        }

        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<pair<int,int>> res;
        int i = 0 ;
        int j = i + 1;
        while(j < n){
            int it = binarySearch(nums,j,n-1,nums[i]+k);
            // cout<<"k->"<<it<<endl;
            if(it != -1){
                // cout<< nums[i]<< " - "<<nums[it]<<endl;   
                res.insert({nums[i],nums[it]});
            }
            i++;
            j++;
        }
        return res.size();
    }
};
