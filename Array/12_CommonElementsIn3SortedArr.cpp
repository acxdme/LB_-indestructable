//gfg
// approach-1 , TC : O(N.logN) . SC : O(N)

   vector <int> commonElements (int A[], int B[], int C[], int a, int b, int c)
    {
        vector<int> ans;
        unordered_map<int,int> mpb;
        unordered_map<int,int> mpc;
        
        for(int i = 0 ; i <b; i++){
            mpb[B[i]]++;
        }
        
        for(int i = 0 ; i< c ;i++){
            mpc[C[i]]++;
        }
        
        for(int i = 0  ;i <a ;i++)
        {
            if(i != 0 && A[i-1] == A[i] ){
                continue;
            }
            if(mpb.find(A[i]) != mpb.end() && mpc.find(A[i]) != mpc.end()){
                ans.push_back(A[i]);
            }
        }
        
        
        return ans;
    }


// approach-2  , TC:O(N) , S.C : O(1) , take advantage of the fact that the arrays are sorted.

            vector<int> ans;
            int p1 = 0 , p2 = 0 ,p3 = 0;
            
            for(;p1 < a ;p1++){
                if(p1 !=0 &&  A[p1-1] == A[p1]){
                    continue;
                }
                int numA = A[p1];
                while(p2 < b && B[p2] < numA){
                    p2++;
                }
                while(p3 < c && C[p3] < numA){
                    p3++;
                }
                if( numA == B[p2] && numA == C[p3]){
                    ans.push_back(numA);
                }
                
            }
            
            return ans;
