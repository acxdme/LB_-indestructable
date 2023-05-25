class Solution {
public:
    
    void heapify(vector<int>& nums , int i ,int n){
        if(i > n) return;
        

         int largest = i;
         int leftChild = 2*i + 1;
         int rightChild = 2*i + 2;

         if(leftChild <= n && nums[i] < nums[leftChild]){
             largest = leftChild;
         }
         if(rightChild <=n && nums[i] < nums[rightChild]){
             largest = rightChild;
         }

         if(largest == i) return;

         swap(nums[i],nums[largest]);

         heapify(nums,largest,n);
    }

    void heapsort(vector<int>& nums){
        int first = 0;
        int n = nums.size()-1;
        int last = n;

        
        while(last > 0){
            // cout<<nums[first]<<" "<<nums[last];
            cout<<endl;
            swap(nums[first],nums[last]); //0 1 1 2 0 
            last--;

            heapify(nums,0,last);
            for(int i = 0 ; i <= nums.size()-1 ; i++){
                cout<<nums[i]<<" ";
            }cout<<endl;
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        //build heap
        int n = nums.size()-1;
        for(int i = n/2 ; i > 0 ; i--){
            heapify(nums,i,n);
        }
        for(auto i : nums){
            cout<<i<<" ";
        }cout<<endl;

        heapsort(nums);

        return nums;
        
    }
};
