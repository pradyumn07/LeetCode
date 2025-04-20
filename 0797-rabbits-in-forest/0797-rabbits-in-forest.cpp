class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        int n=answers.size();
        int ans=0;
        for(int i=0;i<n;i++) mp[answers[i]]++;
        for(auto &p:mp){
            int count=p.second;
            int x=p.first;
            int gsize=x+1;
            int grp=ceil((double)count/gsize);
            ans+=grp*gsize;
        }
        return ans;
    }
};