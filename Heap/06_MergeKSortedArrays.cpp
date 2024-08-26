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


//----------------------------------------------------------------------------------------------------------------------
// using pair<int,pair<int,int>> to manage the <value,<row,column>> data

    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> result;
        // pair<int,pair<int,int>> = <value,<row,col>>
        priority_queue< pair<int,pair<int,int>>,vector< pair<int,pair<int,int>>>,greater< pair<int,pair<int,int>>>> minHeap;
        
        for(int r =0; r < K ; r++){
            minHeap.push({arr[r][0] , {r,0}});
        }
        
        while(!minHeap.empty()){
            auto top = minHeap.top();
            auto val = top.first;
            auto row = top.second.first;
            auto col = top.second.second;
            minHeap.pop();
            result.push_back(val);
            if(col + 1 < K)
             minHeap.push({arr[row][col + 1],{row,col+1}});
            
        }
        
        return result;
        
    }
