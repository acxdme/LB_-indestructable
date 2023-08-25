// lc - 153
// alag alag flavours hai iske , find min ,find max , find pivot
// not able to make the conditions , had to watch solution , after watching find pivot solution need to run 5 test cases to absorb.

//Find minimum in rotated sorted array
// readability can be improved.
class Solution {
public:
    int findMin(vector<int>& nums) {
      int size = nums.size();
      int start = 0 ;
      int end = size -1;
      int mid = start + (end-start)/2;

      while(start <= end){
          // 11 13 15 17
          if(mid +1 <= size - 1 && nums[mid] > nums[mid +1])
          {
              return nums[mid+1];
          }
          if(mid - 1 >= 0 && nums[mid] < nums[mid-1]){
              return nums[mid];
          }
          if(nums[mid] > nums[start]){
              start = mid +1;
          }
          else{
              // 7 0 1 2 4 5 6
              end = mid -1;
          }

          mid = start + (end -start)/2;
      }

      return nums[0];
        
    }
};
