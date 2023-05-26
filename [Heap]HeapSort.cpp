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

-----
  //failed 2 time also , watched code , jeevan hai tuh sangarsh hai
    
class Solution {
public:
    void maxHeapify(vector<int>& nums, int n, int i){
        int largest = i;
        int left = (2 * i) + 1, right = (2 * i) + 2;
        if(left < n && nums[left] > nums[largest])
            largest = left;
        if(right < n && nums[right] > nums[largest])
            largest = right;
        if(largest != i){
            swap(nums[largest], nums[i]);
            maxHeapify(nums, n, largest);
        }
    }

    void heapSort(vector<int>& nums, int n){
        for(int i = n/2-1; i >= 0; i--)
            maxHeapify(nums, n, i);
        for(int i = n-1; i >= 0; i--){
            swap(nums[0], nums[i]);
            maxHeapify(nums, i, 0);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums, nums.size());
        return nums;
    }
};
-------------------------------------------
