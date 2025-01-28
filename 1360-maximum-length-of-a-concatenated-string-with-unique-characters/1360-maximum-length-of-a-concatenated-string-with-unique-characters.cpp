class Solution {
public:
    int n;
    bool unique(string &s1,string &s2){
        vector<int> freq(26, 0);
        for (char c:s1) freq[c-'a']++;
        for (char c:s2) {
            if (freq[c-'a']>0) return false;
            freq[c-'a']++;
        }
        return true;
    }
    int solve(vector<string>& arr,int idx,string ans){
        if(idx==n) return ans.size();
        int adding=0;
        if(unique(ans,arr[idx])){
            adding=solve(arr,idx+1,ans+arr[idx]);
            
        }
        int woadding=solve(arr,idx+1,ans);
        return max(adding,woadding);
    }
    int maxLength(vector<string>& arr) {
        n=arr.size();
        string ans="";
        if(n==0) return 0;
        return solve(arr,0,ans);
    }
};