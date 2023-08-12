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
