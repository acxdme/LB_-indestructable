/*
 just perform the level order traversal and make a mp of level, nodes.
 After populating the mp , reverse the level with odd value.
 now iterate over the mp and store nodes of levels in ans vector.
*/

class Solution{
    public:
    
    void getZigZagOrder(Node* root, map<int, vector<int>>& mp) {
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
    
        while (!q.empty()) {
            auto front = q.front();
            mp[front.second].push_back(front.first->data);
            q.pop();
            if (front.first->left) {
                q.push(make_pair(front.first->left, front.second + 1));
            }
            if (front.first->right) {
                q.push(make_pair(front.first->right, front.second + 1));
            }
        }
    }
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	    
    	vector<int> ans;
    	map<int, vector<int>> mp;
        getZigZagOrder(root, mp);
        for (auto it : mp) {
            if (it.first % 2 != 0) {
                reverse(it.second.begin(), it.second.end());
            }
            for (auto it1 : it.second) {
                ans.push_back(it1);
            }
        }
        
      return ans;
    }
};
