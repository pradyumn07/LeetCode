class Solution {
public:
    int bfs(int start,unordered_map<int,vector<int>> &mp,vector<bool>&visited){
        queue<pair<int,int>> q;
        q.push({start,0});
        int maxd=0;
        while(!q.empty()){
            auto[curr,dist]=q.front();
            q.pop();
            for(auto &it:mp[curr]){
                if(!visited[it]){
                    visited[curr]=true;
                    q.push({it,dist+1});
                    maxd=max(maxd,dist+1); 
                }
            }
        }
        return maxd;
    }
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            int u=i;
            int v=favorite[i];
            mp[v].push_back(u);
        }
        int longest=0;
        int happy=0;
        vector<int> vis(n,false);
        for(int i=0;i<n;i++){
            unordered_map<int,int> mpp;
            int curr=i;
            int count=0;
            while(!vis[curr]){
                vis[curr]=true;
                mpp[curr]=count;
                int next=favorite[curr];
                count++;
                if(mpp.count(next)){
                    int length=count-mpp[next];
                    longest=max(longest,length);
                    if(length==2){
                        vector<bool> visited(n,false);
                        visited[curr]=true;
                        visited[next]=true;
                        happy+=2+bfs(curr,mp,visited)+bfs(next,mp,visited);
                    }
                    break;
                }
                curr=next;

            }
        }
        return max(happy,longest);
    }
};