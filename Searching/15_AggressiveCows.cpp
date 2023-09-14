// tc : O(Nlog M) 
// Sc :  O(1)
// gfg : aggressive cows

bool checkCondition(vector<int>& stalls, int n, int k, int sol) {
    int count = 1;
    int post = stalls[0];
    for (int i = 1; i < n; i++) {
        if (stalls[i] - post >= sol) {
            count++;
            post = stalls[i];
        }

        if (count >= k) return true;
    }

    return count == k;

}

int solve(int n, int k, vector<int>& stalls) {

    int start = 0;
      sort(stalls.begin(),stalls.end());
    int end = stalls[n - 1];
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end) {
        if (checkCondition(stalls, n, k, mid)) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }
    // cout << ans << endl;
    return ans;
}
