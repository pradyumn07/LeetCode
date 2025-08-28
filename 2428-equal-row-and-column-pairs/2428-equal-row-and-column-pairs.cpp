class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int cnt=0;
        map<vector<int>,int> mp;
        for(int i=0;i<n;i++){
            mp[grid[i]]++;
        }
        for(int c=0;c<n;c++){
            vector<int> temp;
            for(int r=0;r<n;r++){
                temp.push_back(grid[r][c]);

            }
            cnt+=mp[temp];
        }
        return cnt;
    }
};