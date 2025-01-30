class Solution {
public:
    bool isBipartite(unordered_map<int,vector<int>>& adj,int curr,vector<int>& colors,int currColor){
        colors[curr]=currColor;
        for(int &i:adj[curr]){
            if(colors[i]==colors[curr]) return false;
            if(colors[i]==-1){
                if(isBipartite(adj,i,colors,1-currColor)==false) return false;

            }
        }
        return true;
    }
    int bfs(unordered_map<int,vector<int>>& adj,int currNode,int n){
        queue<int> q;
        vector<bool> vis(n,false);
        q.push(currNode);
        vis[currNode]=true;
        int level=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int curr=q.front();
                q.pop();
                for(int &ad:adj[curr]){
                    if(vis[ad]) continue;
                    q.push(ad);
                    vis[ad]=true;
                }
            }

            level++;
        }
        return level-1;

    }
    int getMax(unordered_map<int,vector<int>>& adj,int curr,vector<bool>& vis,vector<int>& levels){
        int maxG=levels[curr];
        vis[curr]=true;
        for(int &ad:adj[curr]){
            if(!vis[ad]){
                maxG=max(maxG,getMax(adj,ad,vis,levels));
            }
        }
        return maxG;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto& edge:edges){
            int u=edge[0]-1;
            int v=edge[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> colors(n,-1);
        for(int node=0;node<n;node++){
            if(colors[node]==-1){
                if(isBipartite(adj,node,colors,1)==false) return -1;

            }
        }
        
        vector<int> levels(n,0);
        for(int node=0;node<n;node++){
            levels[node]=bfs(adj,node,n);
        }
        int maxGrp=0;
        vector<bool> vis(n,false);
        for(int node=0;node<n;node++){
            if(!vis[node]){
                maxGrp+=getMax(adj,node,vis,levels);
            }
        }
        return maxGrp;
    }
};