// lc - 987 
// tc : O(N(logN)) , sorting based on level and node value
// sc : O(N) , auxillary space by map 


class node {
public:
    TreeNode* tn;
    int level;
    int hd;

    node(TreeNode* n, int l, int _hd) {
        this->tn = n;
        this->level = l;
        this->hd = _hd;
    }
};

class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if (a.second < b.second) {
            return true;
        } else if (a.second > b.second) {
            return false;
        } else {
            return a.first < b.first;
        }
    }

    void getVerticalTraversal(TreeNode* root, int hd, int level,
      map<int, vector<pair<int, int>>>& mapping) {
        // intialize queue <val,level,hd>
        queue<node*> q;
        // insert initial state : <root,0,0>
        node* n = new node(root, level, hd);
        q.push(n);

        while (!q.empty()) {
            node* front = q.front();
            q.pop();

            TreeNode* treeNode = front->tn;
            int val = treeNode->val;
            int level = front->level;
            int hd = front->hd;

            mapping[hd].push_back({val, level});

            if (treeNode->left) {
                node* n = new node(treeNode->left, level + 1, hd - 1);
                q.push(n);
            }
            if (treeNode->right) {
                node* n = new node(treeNode->right, level + 1, hd + 1);
                q.push(n);
            }
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> result;
        if (root == NULL)
            return result;

        int hd = 0;
        int level = 0;
        map<int, vector<pair<int, int>>> mapping;

        getVerticalTraversal(root, hd, level, mapping);

        for (auto v : mapping) {
            sort(v.second.begin(), v.second.end(), cmp);
            vector<int> temp;
            for (pair<int, int> p : v.second) {
                temp.push_back(p.first);
            }
            result.push_back(temp);
        }

        return result;
    }
};
