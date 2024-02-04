// gfg - https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
// tc : k^2 log(k)
// sc : O(k^2)

class Info{
  public:
  
   int data;
   int row;
   int col;
   
   
   // intialization list
   Info(int d , int r ,int c) : data(d) , row(r) , col(c) {};
   
};

class compare{
    public:
     bool operator ()(Info* a , Info* b) {
        return  (a->data) > (b->data);
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> result;
        // min-heap with custom ordering.
        priority_queue<Info* , vector<Info*> , compare> pq;
        
        for(int i =0 ; i < K ; i++){
            Info* newInfo = new Info(arr[i][0],i,0);
            pq.push(newInfo);
        }
        
        while(!pq.empty()){
            Info* top = pq.top();
            pq.pop();
            
            int data = top->data;
            int row = top->row;
            int col = top->col;
            
            result.push_back(data);
            if(col + 1 < arr[row].size()){
              Info* newInfo = new Info(arr[row][col+1],row,col+1);
              pq.push(newInfo);  
            }
            
        }
        
        
        return result;
        
    }
};
