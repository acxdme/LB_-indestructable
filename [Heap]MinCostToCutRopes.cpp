/*
problem : min cost to cut ropes
Time complexity : O(N * log N)
*/

    long long minCost(long long arr[], long long n) {
       long long int cost = 0;
       if(n == 0) return cost;
       
       //min Heap
       priority_queue<long long int,vector<long long int>,greater<long long int>> minHeap;
       for(long long int i =0 ;i<n;i++){
           minHeap.push(arr[i]);
       }
       
       // take two min ropes and add 
       while(minHeap.size() > 1){
           long long int first = minHeap.top();
           minHeap.pop();
           long long int second = minHeap.top();
           minHeap.pop();
           long long int sum = first + second;
           
           minHeap.push(sum);
           
           cost += sum;
           
       }
       
       return cost;
       
    }
