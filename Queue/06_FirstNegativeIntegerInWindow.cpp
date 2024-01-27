// gfg - https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
// tc : O(N)
// sc : O(K) , K is the window size

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {

    vector<long long int> result;
    
    //initialize queue
    queue<long long int > q;
    
    // process first window of size k
    for(long long int i =0 ; i < K ;i++){
        if(A[i] < 0){
            q.push(i);
        }
        
    }
    
    //process remainging windows
    for(long long int i = K ; i< N ;i++){
        if(!q.empty()){
            long long int index = q.front();
            result.push_back(A[index]);
        }
        else{
            result.push_back(0);
        }
        
        if((!q.empty()) && (i - q.front()  >= K)){
            q.pop();
        }
        
        if(A[i] < 0){
            q.push(i);
        }
        
        
    }
    
    // get result for last window
    if(!q.empty()){
        long long int index = q.front();
        result.push_back(A[index]);
    }
    else{
        result.push_back(0);
    }

    return result;
                                                 
 }
