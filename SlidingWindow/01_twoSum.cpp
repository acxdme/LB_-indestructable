/*
 lc : 1
 time complexity : O(N)
  */

class Solution {
public:

    static bool cmp(pair<int,int>& a , pair<int,int>& b){
        return a.first < b.first;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        vector<pair<int,int>> t;

        for(int i= 0 ; i< nums.size();i++){
            t.push_back({nums[i],i});

        }

        sort(t.begin(),t.end(),cmp);

        int start = 0 ;
        int end = t.size() -1;
        int  sum = 0;
        while(start < end){
            // cout<<t[start].first<<" "<<t[end].first<<endl;
            if(t[start].first + t[end].first == target){
                answer.push_back(t[start].second);
                answer.push_back(t[end].second);
                return answer;
            }
            else if(t[start].first + t[end].first > target){
                end--;
            }
            else{
                start++;
            }
        }

        return answer;
    }
};
