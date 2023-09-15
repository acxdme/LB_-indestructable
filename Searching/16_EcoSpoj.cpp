// spoj

#include <iostream>
#include<algorithm>
using namespace std;
bool checkCondition(long long int tree[], long long int n ,long long int m , long long int mid ){
	long long int sum = 0;
	for(long long int i =0 ;i < n ;i++){
		if(mid < tree[i]){
			sum += (tree[i] - mid);
		}
		if( sum >= m ) return true;
	}
	
	return false;
}
int main() {
	
	long long int n;// trees
	long long int m;// wood
	cin >> n >> m;
	long long int tree[n];
	for(long long int i =0 ;  i < n; i++){
		cin>> tree[i];
	}
	
	sort(tree,tree+n);
	long long int start = 0;
	long long int end = tree[n-1];
	long long int mid = start + (end-start)/2;
	long long int ans = -1;
	while(start <= end){
		if(checkCondition(tree,n,m,mid)){
			ans = mid;
			start = mid +1;
		}
		else{
			end = mid - 1;
		}
		 mid = start + (end-start)/2;
	}
	
	cout<< ans ;
	
	return 0;
}
