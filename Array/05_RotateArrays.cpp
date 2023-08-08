// gfg- Rotate Arrays
// time-complexity :O(N)
// Space-complexity : O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        int actualRotations = d % n;
        
        int brr[n];
        for(int i = 0 ; i < n ; i++){
            int updatedIndex = i - actualRotations;
            if(updatedIndex < 0) updatedIndex += n;
            // brr array ki updatedIndex mei arr ki value
            brr[updatedIndex] = arr[i];
            // cout<<brr[i]<<" ";
        }
        
        for(int i = 0 ; i< n; i++){
            arr[i] = brr[i];
        }
    }
};

//---------------------------------------------------------------------
// Brute force will be O(N^2) TC and O(1) space complexity.
