class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        for (int row=n - 2;row >= 0;row--) {
            for (int col=0;col<n;col++) {
                int minSum=matrix[row+1][col];
                if (col>0) minSum=min(minSum,matrix[row+1][col-1]); 
                if (col<n-1) minSum=min(minSum,matrix[row+1][col+1]); 
                matrix[row][col]+=minSum;
            }
        }
        for (int col=0;col<n;col++) {
            ans=min(ans,matrix[0][col]);
        }
        return ans;
    }
};
