class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
            
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int ele=q.front();
            q.pop();
            topo.push_back(ele);
            for(int i=0;i<adj[ele].size();i++){
                indegree[adj[ele][i]]--;
                if(indegree[adj[ele][i]]==0) q.push( adj[ele][i]);
            }
        }
        return topo.size()==numCourses;
        
    }
};