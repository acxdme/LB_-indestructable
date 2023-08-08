// Segregate 0's & 1's
// Time complexity : O(N)
// space complexity : O(1)
class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        int start = 0 ;
        int end = n-1;
        
        // int i  = 0;
        // while (i < end){
        //     if(arr[i] == 0){
        //         swap(arr[i],arr[start]);
        //         start++;
        //         i++;
        //     }
        //     else{ // arr[i] == 1
        //         swap(arr[i],arr[end]);
        //         end--; 
        //     }
        // }
        
        while(start < end){
            if(arr[start] == 0){
                start++;
            }else{
                swap(arr[start],arr[end]);
                end--;
            }
        }
    }
};
