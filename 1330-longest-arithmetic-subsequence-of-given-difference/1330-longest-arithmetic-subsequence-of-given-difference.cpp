class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> mp;
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int curr=arr[i];
            int prev=curr-difference;
            int length=mp[prev];
            int curr_length=length+1;
            mp[curr]=curr_length;
            ans=max(ans,mp[curr]);  
        }
        return ans;
    }
};