class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i;
        }
        int mini = INT_MAX;
        for (int i = 0; i < m; i++) {
            int last = INT_MIN;
            for (int j = 0; j < n; j++) {
                int ele = mat[i][j];
                int idx = mp[ele];
                last = max(last, idx);
            }
            mini = min(mini, last);
        }
        for (int i = 0; i < n; i++) {
            int last = INT_MIN;
            for (int j = 0; j < m; j++) {
                int ele = mat[j][i];
                int idx = mp[ele];
                last = max(last, idx);
            }
            mini = min(mini, last);
        }
        return mini;
    }
};
