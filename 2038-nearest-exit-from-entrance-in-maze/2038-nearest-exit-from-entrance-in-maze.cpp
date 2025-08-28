class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{entrance[0],entrance[1]}});
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[entrance[0]][entrance[1]] = 1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int dist=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                   && maze[nrow][ncol]=='.' && !vis[nrow][ncol]){
                    if(nrow==0 || nrow==n-1 || ncol==0 || ncol==m-1) return dist+1;
                    pq.push({dist+1,{nrow,ncol}});
                    vis[nrow][ncol]=1;
                }
            }

        }
        return -1;
    }
};