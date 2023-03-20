	    void findPermutations (int i , string &s , vector<string> &res){
	        //base case
	        if( i >= s.size()) {
	            res.push_back(s);
	            return;
	        };
	        
	        for(int j = i ; j < s.size();j++){
	            swap(s[i],s[j]);
	            findPermutations(i+1,s,res);
	            swap(s[i],s[j]);
	        }
	        
	    }
		vector<string>find_permutation(string S)
		{
		   int i =0 ;
		   vector<string> res ;
		   findPermutations(i,S,res);
		  // sort(res.begin(),res.end());
		   
		   return res;
		}
