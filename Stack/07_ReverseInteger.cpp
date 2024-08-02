// gfg : https://www.geeksforgeeks.org/problems/reverse-digit0316/

// TC : O(log N)
// SC : O(N) , space for taking the stack

class Solution
{
	public:
	
	  void pushNumbers(stack<int> &st ,long long int n){
	        while(n > 0){
	            int digit = n % 10;
	            st.push(digit);
	            n = n /10;
	        }
	    }

		long long int reverse_digit(long long int n)
		{
		    long long int res = 0;
		    long long int i = 1;
		    
		    stack<int> st;
		    
		    pushNumbers(st,n);
		    
		    while(!st.empty()){
		        long long int top = st.top();
		        st.pop();
		        res += (top*i);
		        i *=10;
		    }
		    
		    return res;
		}
};
