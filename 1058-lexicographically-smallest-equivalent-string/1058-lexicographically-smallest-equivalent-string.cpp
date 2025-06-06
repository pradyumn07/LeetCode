class Solution {
public:
    char dfs(unordered_map<char,vector<char>> &adj,char ch,vector<int> &vis){
        vis[ch-'a']=1;
        char mini=ch;
        for(char &c:adj[ch]){
            if(vis[c-'a']==0){
                mini=min(mini,dfs(adj,c,vis));
            }
        }
        return mini;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.length();
        int m=baseStr.length();
        unordered_map<char,vector<char>> adj;
        for(int i=0;i<n;i++){
            char ch1=s1[i];
            char ch2=s2[i];
            adj[ch1].push_back(ch2);
            adj[ch2].push_back(ch1);
        }
        string ans;
        for(int i=0;i<m;i++){
            char ch=baseStr[i];
            vector<int> vis(26,0);
            char minC=dfs(adj,ch,vis);
            ans.push_back(minC);
        }
        return ans;
    }
};