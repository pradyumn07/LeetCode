class Solution {
public:
    int c=0;
    void dfs(int node,vector<bool> &vis,unordered_map<int,vector<pair<int,int>>> &adj){
        vis[node]=true;
        for(auto &p:adj[node]){
            int i=p.first;
            int j=p.second;
            if(!vis[i]){
                if(j==1) c=c+1;
                dfs(i,vis,adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &v:connections){
            int a=v[0];
            int b=v[1];
            adj[a].push_back({b,1});
            adj[b].push_back({a,0});

        }
        vector<bool> vis(n,false);
        dfs(0,vis,adj);
        return c;
    }
};