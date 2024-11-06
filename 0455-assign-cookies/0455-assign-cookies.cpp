class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        int count=0;
        int i=0,j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(j<m && i<n){
            if(s[j]>=g[i]){
                count++;
                i++;
                j++;
            }
            else{
                
                j++;
            }
        }
        return count;
    }
};