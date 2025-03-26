class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> arr;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr.push_back(grid[i][j]);
            }
        }
        int l=arr.size();
        sort(begin(arr),end(arr));
        
        int target=arr[l/2];
        int ans=0;
        for(int num:arr){
            if(num%x != target%x) return -1;
            ans+=abs(target-num)/x;
        }
        return ans;
    }
};