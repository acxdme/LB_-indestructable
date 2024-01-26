/*
gfg : https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
Time complexity : O(26*N)
space complexity : O(N)
*/		

string FirstNonRepeating(string A){
		    string ans;
		    if(A.size() == 0 ) return ans;
		    map<char,int> mp;
		    queue<char> q;
		    
		    for(auto c : A){
		        if(mp.find(c) == mp.end()){
		            q.push(c);
		        }
		        mp[c]++;
		        
		        while( !q.empty() && mp[q.front()] > 1 ){
		            q.pop();
		        }
		        
		        if(q.empty()){
		            ans += "#";
		        }else{
		            ans += q.front();
		        }
		        
		    }
		    
		    return ans;
		}
