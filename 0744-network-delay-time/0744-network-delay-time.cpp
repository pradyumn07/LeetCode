class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int time=times[i][2];
            adj[u].push_back({v,time});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> ans(n+1,INT_MAX);
        ans[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto p=pq.top();
            int wt=p.first;
            int node=p.second;
            pq.pop();
            for(auto &vec:adj[node]){
                int adjnode=vec.first;
                int weight=vec.second;
                if(wt+weight<ans[adjnode]){
                    ans[adjnode]=wt+weight;
                    pq.push({wt+weight,adjnode});
                }
            }
        }
        int result=INT_MIN;
        for(int i=1;i<=n;i++){
            result=max(result,ans[i]);
        }
        return result==INT_MAX?-1:result;
    }
};