/*
Time complexity : O(N)
Space complexity : O(N)
*/
#include<bits/stdc++.h>
class Solution {
public:

    void findNextSmaller(vector<int>& heights , vector<int>&next){
        stack<int> st;
        st.push(-1);

        for(int i = heights.size() -1 ;i >= 0;i--){

            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            
            next.push_back(st.top());

            st.push(i);

        }
    }

    void findPrevSmaller(vector<int>&heights , vector<int>& prev){
        stack<int> st;
        st.push(-1);

        for(int i = 0 ; i < heights.size();i++){
            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            
            prev.push_back(st.top());

            st.push(i);

        }
    }


    int largestRectangleArea(vector<int>& heights) {

        vector<int> prev;
        vector<int> next;

        


        findNextSmaller(heights,next);
        findPrevSmaller(heights,prev);

        reverse(next.begin(),next.end());

        // for(auto i : prev){
        //     cout<<i <<" ";
        // }cout<<endl;

        // for(auto i : next){
        //     cout<<i <<" ";
        // }cout<<endl;

        int mx = INT_MIN;
        int n = heights.size();


        for(int i = 0 ;i < n ;i++){
            if(next[i] == -1){
                next[i] = n;
            }
            mx = max ( (next[i] - prev[i] - 1) * heights[i] , mx);
        }

        return mx;
        
    }
};
