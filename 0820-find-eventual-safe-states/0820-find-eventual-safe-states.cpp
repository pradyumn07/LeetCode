class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> indegree(V,0);
        vector<vector<int>> graphrev(V);;
        for(int i=0;i<V;i++){
            for(auto it:graph[i]){
                graphrev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> safe;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe.push_back(node);
            for(auto it:graphrev[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(safe.begin(),safe.end());
        return safe;

    }
};