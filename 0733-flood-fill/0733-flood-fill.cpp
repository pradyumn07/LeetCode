class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int start=image[sr][sc];
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        if(image[sr][sc]==color) return image;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            vis[row][col]=1;
            image[row][col]=color;

            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && image[nrow][ncol]==start){
                    q.push({nrow,ncol});

                }
            }
        }
        return image;
    }
};