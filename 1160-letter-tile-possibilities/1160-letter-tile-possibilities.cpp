class Solution {
public:
    int n;
    void solve(string &tiles,vector<bool> &vis,unordered_set<string> &ans,string &curr){
        ans.insert(curr);
        for(int i=0;i<n;i++){
            if(vis[i]==true) continue;
            vis[i]=true;
            curr.push_back(tiles[i]);
            solve(tiles,vis,ans,curr);
            vis[i]=false;
            curr.pop_back();

        }
    }
    int numTilePossibilities(string tiles) {
        n=tiles.length();
        vector<bool> vis(n,false);
        unordered_set<string> ans;
        string curr="";
        solve(tiles,vis,ans,curr);
        return ans.size()-1;
    }
};