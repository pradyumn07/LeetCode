class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        unordered_map<int,int> freq;
        unordered_map<int,int> prevcolor;
        for(int i=0;i<queries.size();i++){
            int ball=queries[i][0];
            int color=queries[i][1];
            if(prevcolor.find(ball)!=prevcolor.end()){
                int prev=prevcolor[ball];
                freq[prev]--;
                if(freq[prev]==0){
                    freq.erase(prev);
                }
            }
            prevcolor[ball]=color;
            freq[color]++;
            ans[i]=freq.size();
        }
        return ans;
    }
};