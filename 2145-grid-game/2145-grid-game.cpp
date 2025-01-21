class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long first_row=0;
        int n=grid[0].size();
        for(int i=0;i<n;i++){
            first_row+=grid[0][i];
        }
        long long second_row=0;
        long long maxi=LLONG_MIN;
        long long mini=LLONG_MAX;
        for(int i=0;i<n;i++){
            first_row-=grid[0][i];
            maxi=max(first_row,second_row);
            second_row+=grid[1][i];
            mini=min(mini,maxi);

        }
        return mini;
    }
};