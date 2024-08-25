// gfg : https://www.geeksforgeeks.org/problems/longest-increasing-subarray3811/0
// tc : O(N)
// sc : O(1)

// maxLength , including the subarray.
    int lenOfLongIncSubArr(vector<int> &arr) {

        int maxLen = 1;
        int n = arr.size();
        int counter = 1;
        int startingIndex = 0;
        int pos  = 0;

        for(int i = 1; i < n ; i++){
            if(arr[i] > arr[i-1]){
                counter++;
                if(counter > maxLen){
                  pos = startingIndex;
                  maxLen = counter;   
                }
               
            }
            else{
                startingIndex = i;
                counter = 1;
            }
        }
        
        cout<< pos << " - "<< maxLen<<endl;
        
        
        return maxLen;
    }
