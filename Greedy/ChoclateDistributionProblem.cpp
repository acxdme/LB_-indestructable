// time-complexity : O(NlogN)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
     long long int ans = INT_MAX;
     int start = 0 ;
     int end = m-1;
     sort(a.begin(),a.end()); // 1 3 4 7 9 9 12 56
     
     while(end < n){
         ans = min(ans,a[end] - a[start]);
         start++;
         end++;
     }
     
     
     return ans;
    
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends
