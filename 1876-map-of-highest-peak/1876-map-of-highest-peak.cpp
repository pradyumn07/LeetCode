class Solution {
public:
    vector<vector<int>> dir{{0,1},{0,-1},{-1,0},{1,0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
       int m=isWater.size();
       int n=isWater[0].size();
       queue<pair<int,int>> q;
       vector<vector<int>> ans(m,vector<int>(n,-1));
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(isWater[i][j]==1){
                ans[i][j]=0;
                q.push({i,j});

            }
        }
       }
       while(!q.empty()){
        auto curr=q.front();
        q.pop();
        int i=curr.first;
        int j=curr.second;
        for(auto &d:dir){
            int new_i=i+d[0];
            int new_j=j+d[1];
            if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && ans[new_i][new_j]==-1){
                ans[new_i][new_j] =1+ans[i][j];
                q.push({new_i,new_j});
            }
        }

       }
       return ans;
    }
};