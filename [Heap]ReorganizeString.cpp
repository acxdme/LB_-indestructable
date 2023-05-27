/*
 Time complexity : O(N + logN)
 Space complexity : O(N)
*/
class node{
public:
    char c;
    int count;

    node(char c ,int count){
        this->count = count;
        this->c = c;
    }
};

class compare {
    public:
    bool operator()(node* a, node* b) {
        return a->count < b->count;
    }
};

class Solution {
public:
    
    string reorganizeString(string s) {

        string ans = "";
        //map of character and occurences in s
        unordered_map<char,int> mp;
        for(int i = 0 ; i < s.size(); i++){
            mp[s[i]]++;
        }

        // make a custom max heap of <character,count>
        priority_queue<node*,vector<node*>,compare> pq;
        for(auto it : mp){
            node *t = new node(it.first,it.second);
            pq.push(t);
            // cout<<it.first <<" "<<it.second <<endl;
        }


        // while(q.size() > 1) remove 2 nodes and make string and insert back conditionally
        while(pq.size() > 1){
            node* first = pq.top();
            pq.pop();
            node* second = pq.top();
            pq.pop();

            ans += first->c;
            ans += second->c;

            first->count -= 1;
            second->count -= 1;

            if(first->count > 0){
                pq.push(first);
            }
            if(second->count > 0){
                pq.push(second);
            }
        }

        //check for the remaining node in max heap and return ans accordingly
        if(!pq.empty()){
            node* tp = pq.top();
            if(tp->count ==1) ans +=tp->c;
            else{
                return "";
            }
        }
        
        return ans;
    }
};
