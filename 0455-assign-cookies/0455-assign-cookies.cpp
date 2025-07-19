class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;
        if(s.size()==0) return 0;
        sort(s.begin(),s.end(),greater<int>());
        sort(g.begin(),g.end(),greater<int>());
        int i=0,j=0;
        while(i<g.size() && j<s.size()){
            if(g[i]<=s[j]){
                count++;
                i++;
                j++;
            } else i++;
        }
        return count;
    }
};