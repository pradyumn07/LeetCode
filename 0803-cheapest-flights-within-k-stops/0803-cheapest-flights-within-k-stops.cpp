class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it:flights){
            adj[it[0]].push_back({it[1],it[2]});

        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>k) continue;
            for(auto &e:adj[node]){
                int newnode=e.first;
                int newcost=e.second;
                if(newcost+cost<dist[newnode]){
                    dist[newnode]=newcost+cost;
                    q.push({stops+1,{newnode,dist[newnode]}});
                }
            }
        }
        if(dist[dst]!=1e9) return dist[dst];
        return -1;
    }
};