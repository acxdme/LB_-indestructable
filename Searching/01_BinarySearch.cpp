// tc   o(log n)

int main (){
  int nums[] = { 1,2 , 6,7 ,9 ,19};
  int start = 0 ;
  int end = nums.size() -1;
  int mid = start + (end -start)/2;
  while(start <= end){
    if(nums[mid] == target){
      return mid;
    }
    else if (nums[mid] > target){
      start  = mid +1;
    }
    else{
      // nums[mid] < target
      end = mid -1;
  }

    return -1;
}
