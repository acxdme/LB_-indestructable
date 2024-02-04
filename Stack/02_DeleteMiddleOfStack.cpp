// gfg - https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1
// tc : O(N)
// sc : O(N)

class Solution
{
    public:
    //Function to delete middle element of a stack.
    
    void delMiddleHelper(stack<int>&s, int sizeOfStack ,int &middle){
        
        if(sizeOfStack == middle){
            s.pop();
            return;
        }
        
        int top = s.top();
        s.pop();
        
        delMiddleHelper(s,sizeOfStack - 1 ,middle);
        
        
        s.push(top);
        
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // get middle 
        int middle = floor((sizeOfStack + 1) /2 );
        
        delMiddleHelper(s,sizeOfStack,middle);
        
    }
};
