class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<pair<int,int>>> adj;
        int n=grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        grid[0][0] = 1;
        int delrow[]={-1,0,1,-1,1,-1,0,1};
        int delcol[]={-1,-1,-1,0,0,1,1,1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int vis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 && col==n-1)  return vis;
            for(int i=0;i<8;i++){
                int newrow=row+delrow[i];
                int newcol=col+delcol[i];
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<n && grid[newrow][newcol]==0){
                    grid[newrow][newcol]=1;
                    q.push({vis+1,{newrow,newcol}});
                }
            }
        }
        return -1;
    }
};