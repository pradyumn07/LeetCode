class Solution {
public:
    vector<vector<int>> dir={{0,-1},{0,1},{-1,0},{1,0}}; 
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int col:{0,n-1}){ 
                pq.push({heightMap[i][col],{i,col}});
                vis[i][col]=true;
            }
        }
        for(int i=0;i<n;i++){
            for(int row:{0,m-1}){ 
                pq.push({heightMap[row][i],{row,i}});
                vis[row][i]=true;
            }
        }
        int ans=0;
        while(!pq.empty()){
            auto ele=pq.top();
            pq.pop();
            int height=ele.first;
            int i=ele.second.first;
            int j=ele.second.second;
            for(vector<int>&d:dir){
                int new_i=i+d[0];
                int new_j=j+d[1];
                if(new_i>=0 && new_j>=0 && new_i<m && new_j<n && !vis[new_i][new_j]){
                    ans+=max((height-heightMap[new_i][new_j]),0);
                    vis[new_i][new_j]=true;
                    pq.push({max(height,heightMap[new_i][new_j]),{new_i,new_j}});
                    

                } 
            }
        }
        return ans;
    }
};