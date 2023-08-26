// Square Root using binary search


// below case failing for val = 458 mine-22 , ans - 21
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
       long long int  ans = -1;
       
       long long  int start = 1;
       long long  int end =  x;
       long long mid = start + (end - start) /2;
       
       while(start <= end){
           
           if(mid * mid  == x || start == end){
              return mid;
           }
           else if( mid * mid  > x){
                end = mid -1;
           }
           else{
               start = mid +1 ;
           }
           
            mid = start + (end - start) /2;
       }
       
       return mid;
    }
};
