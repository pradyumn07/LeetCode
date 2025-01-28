class Solution {
public:
    int m,n;
    vector<vector<int>> direction={{-1,0},{1,0},{0,-1},{0,1}};
    int bfs(int i,int j,vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        int count=grid[i][j];
        grid[i][j]=0;
        while(!q.empty()){
            i=q.front().first;
            j=q.front().second;
            q.pop();
            for(auto& d:direction){
                int new_i=i+d[0];
                int new_j=j+d[1];
                if(new_i>=0 && new_j>=0 &&new_i<m && new_j<n && grid[new_i][new_j]>0){
                    q.push({new_i,new_j});
                    count+=grid[new_i][new_j];
                    grid[new_i][new_j]=0;
                }
            }
        }
        return count;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int maxFish=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0) maxFish=max(maxFish,bfs(i,j,grid));
            }
        }
        return maxFish;
    }
};