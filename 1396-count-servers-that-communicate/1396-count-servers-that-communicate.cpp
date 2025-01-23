class Solution {
public:
    int m,n;
    bool check(int i,int j,vector<vector<int>>& grid){
        for(int k=0;k<n;k++){
            if(grid[i][k]==1 && k!=j) return true;
        }
        for(int k=0;k<m;k++){
            if(grid[k][j]==1 && k!=i) return true;
        }
        return false;
    }
    int countServers(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && check(i,j,grid)) count++;
            }
        }
        return count;
    }
};