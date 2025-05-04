class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int> mp;
        for(auto &d:dominoes){
            if(d[0]>d[1]) swap(d[0],d[1]);
            mp[{d[0],d[1]}]++;
        }
        int ans=0;
        for(auto &m:mp){
            int f=m.second;
            ans+=f*(f-1)/2;

        }
        return ans;
    }
};