class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<int> ans;
        vector<int> last(26,-1);
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            last[idx]=i;
        }
        int i=0;
        while(i<n){
            int end=last[s[i]-'a'];
            int j=i;
            while(j<end){
                end=max(end,last[s[j]-'a']);
                j++;
            }
            ans.push_back(j-i+1);
            i=j+1;
        }
        return ans;
    }
};