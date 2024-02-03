// tc : O(k log k) , k = n+m
//sc : O(log k)

class Solution{
    public:
    
    void heapify(vector<int>& result,int currPos,int size){
        
        
        int largestPos = currPos;
        int leftPos = 2 * currPos;
        int rightPos = 2 * currPos + 1;
        
        if((leftPos <= size) && result[leftPos] > result[largestPos] ){
            largestPos = leftPos;
        }
        
        if((rightPos <= size) && result[rightPos] > result[largestPos]){
            largestPos = rightPos;
        }
        
        if(largestPos != currPos){
          swap(result[currPos],result[largestPos]);
          heapify(result,largestPos ,size);
            
        }
        
        
    }
    
    void buildHeap(vector<int>& result , int size){
        int k = (size) /2;
        for(int i = k ; i > 0 ;i-- ){
            heapify(result,i,size);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> result;
        result.push_back(-1);
        for(int i = 0 ; i < n;i++)
        {
            result.push_back(a[i]);
        }
        
        for(int i = 0 ; i < m;i++){
            result.push_back(b[i]);
        }
        
        int size = result.size();
        
        buildHeap(result,n+m);
        result.erase(result.begin());
        
        
        return result;
        
    }
};
