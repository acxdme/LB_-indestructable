// gfg - https://www.geeksforgeeks.org/problems/sort-a-stack/1
// tc : O(N^2)
// sc : O(N)

void insert(stack<int> &s , int target){
    
    if(s.empty()){
        s.push(target);
        return;
    }
    
    if( s.top() > target ){
        int top = s.top();
        s.pop();
        insert(s,target);
        s.push(top);
    }
    else{
        s.push(target);
    }
    
}

void SortedStack :: sort()
{
   // find top 
   if(s.empty()){
       return;
   }
   int top = s.top();
   s.pop();
   
   // recursive call
   sort();
   
   // insert in stack as per order
   insert(s,top);
   return;
}
