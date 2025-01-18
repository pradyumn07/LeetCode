class Solution {
public:
    vector<vector<int>> direction={{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        vector<vector<int>> ans(m,vector<int>(n,INT_MAX));
        pq.push({0,0,0});
        ans[0][0]=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int currCost=curr[0];
            int i=curr[1];
            int j=curr[2];
            for(int dir=0;dir<4;dir++){
                int new_i=i+direction[dir][0];
                int new_j=j+direction[dir][1];
                if(new_i>=0 && new_j>=0 && new_i<m && new_j<n){
                    int gridDir=grid[i][j];
                    int dCost=((gridDir-1!=dir)?1:0);
                    int newCost=currCost+dCost;
                    if(newCost<ans[new_i][new_j]){
                        ans[new_i][new_j]=newCost;
                        pq.push({newCost,new_i,new_j});
                    }
                }
            }
        }
        return ans[m-1][n-1];
    }
};