/*
Time complexity : O(a+b+c)
*/
class node{
public:
    char c;
    int count;
    node(char c, int count){
        this->c = c;
        this->count = count;
    }
};

class compare{
public:
 bool operator()(node* a , node* b){
    return a->count < b->count;
 }

};
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";

        node* a1 = new node('a',a);
        node* b1 = new node('b',b);
        node* c1 = new node('c',c);

        priority_queue<node* ,vector<node*>,compare> maxHeap;

        if(a1->count > 0)
        maxHeap.push(a1);
        if(b1->count > 0)
        maxHeap.push(b1);
        if(c1->count > 0)
        maxHeap.push(c1);

        while(maxHeap.size() > 1){
            node* first = maxHeap.top();
            maxHeap.pop();
            node* second = maxHeap.top();
            maxHeap.pop();

            if(first->count >=2){
               ans += first->c;
               ans += first->c;
               first->count -= 2;
            }else{
               ans+=first->c;
               first->count -= 1;
            }

            if(second->count >=2 && second->count >=first->count){
                ans += second->c;
                ans += second->c;
                second->count -=2;
            }else{
                ans += second->c;
                second->count -=1;
            }

            if(first->count > 0)
            maxHeap.push(first);
            if(second->count > 0)
            maxHeap.push(second);
        }

        if(!maxHeap.empty()){
            node* first = maxHeap.top();
            if(first->count == 1){
                ans+=first->c;
            }
            else{
                ans+= first->c;
                ans+= first->c;
            }
            
        }

        return ans;

    }
};
