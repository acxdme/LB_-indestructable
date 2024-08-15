// gfg : https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
// TC : O(N)
// SC : O(K)

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                                                        
    queue<long long int> q;
    vector<long long int> res;
    
    // process first window of size K
    
    for(long long int i =0 ; i < K ; i++){
        if(A[i] < 0){
            q.push(i);
        }
    }
    
    // store result for first window 
    if(q.empty()) res.push_back(0);
    else res.push_back(A[q.front()]);
    
    
    // process for remaining windows
    
    for(long long int i =K ; i < N ; i++){
        
        // remove out of range index from queue
        if(!q.empty() &&  i - q.front() >= K){
            q.pop();
        }
        
        // if current element is negative push in queue
        if(A[i] < 0){
            q.push(i);
        }
        
         // store result for current window
         if(q.empty()) res.push_back(0);
         else res.push_back(A[q.front()]);
        
    }
    
    
    return res;
    
                                                 
 }
