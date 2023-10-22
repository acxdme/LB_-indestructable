//  TC : O(N)
// SC : O(1)

class Solution
{
	public:
    int gcd(int A, int B) 
	{ 
	    int res = 1;
	    while(A > 0 && B > 0){
	        if( A > B){
	            A = A - B;
	        }
	        else{
	            B = B - A;
	        }
	    }
	      
	    res = max(A,B);
	    
	    return res;
	} 
};
