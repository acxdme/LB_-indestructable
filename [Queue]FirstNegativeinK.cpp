/*
 Time complexity : O(N)
 Space complexity : O(N) 
*/
#include <iostream>
#include<queue>
#include<vector>

using namespace std;

void findFirstNegativeInK(vector<int>& v,vector<int>& ans, int& k) {
    queue<int> q;
    for (int i = 0;i < v.size();i++) {
        if (v[i] < 0) {
            q.push(i);
        }

    }
    int i = 0;
    while (i < v.size()) {
        for (int j = i; j < i + k; j++) {
            if (v[i] < 0) {
                q.push(i);
            }
            while ((!q.empty()) && (j - q.front() >= k)) {
                q.pop();
            }
            if (j >= v.size())
                return;

        }i++;

        if (q.empty()) {
            ans.push_back(0);
        }
        else {
            
            ans.push_back(v[q.front()]);
        }
    }
    
}
void solve(vector<int>& v, vector<int>& ans, int& k) {
    queue<int> q;
    // process first window of k
    for (int i = 0; i < k; i++) {
        if (v[i] < 0) {
            q.push(i);
        }
    }

    for (int i = k; i < v.size(); i++) {

        if (!q.empty()) {
            ans.push_back(v[q.front()]);
        }
        else {
            ans.push_back(0);
        }

        if (!q.empty() && i - q.front() >= k) {
            q.pop();
        }

        if (v[i] < 0) {
            q.push(i);
        }

    }

    //checking for last window
    if (!q.empty()) {
        ans.push_back(v[q.front()]);
    }
    else {
        ans.push_back(0);
    }
    
}
int main()
{
    vector<int> v = { 12,-1,-7,8,-15,30,16,28 };

    cout << "original vector" << endl;
    for (auto i : v) {
        cout << i << " ";

    }cout << endl;

    int k = 3;

    vector<int> ans;
    // brute-bhasad approach
    //findFirstNegativeInK(v,ans, k);

    //optimized approach 
    solve(v, ans, k);

    for (auto i : ans) {
        cout << i << " ";

    }cout << endl;

    return 0;
}
