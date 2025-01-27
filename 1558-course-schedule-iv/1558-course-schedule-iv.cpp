class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &adj,int u,int v,vector<bool> &vis){
        vis[u]=true;
        if(u==v) return true;
        bool reachable=false;
        for(auto &node:adj[u]){
            if(!vis[node]){
                reachable=reachable || dfs(adj,node,v,vis);
            }
        }
        return reachable;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        for(auto &edge:prerequisites){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        int n=queries.size();
        vector<bool> ans(n);
        for(int i=0;i<n;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            vector<bool> vis(numCourses,false);
            ans[i]=dfs(adj,u,v,vis);

        }
        return ans;
    }
};