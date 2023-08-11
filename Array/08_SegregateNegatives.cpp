// gfg - Segregate negatives
// tc : O(N)
// sc : O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        vector<int> pos;
        vector<int> neg;
        
        for(int i = 0 ; i< n ;i++){
            if(arr[i]  >= 0){
                pos.push_back(arr[i]);
            }else{
                neg.push_back(arr[i]);
            }
        }
        
        int index = 0;
        for(int  i = 0 ; i < pos.size(); i++){
            arr[index++] = pos[i];
        }
        
        for(int i = 0 ; i < neg.size();i++){
            arr[index++] = neg[i];
        }
    }
};
