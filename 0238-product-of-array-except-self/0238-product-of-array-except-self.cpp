class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> suf(n,1);
        vector<int> pref(n,1);
        vector<int> ans;
        pref[0]=1;
        suf[n-1]=1;
        for(int i=1;i<nums.size();i++){
            pref[i]=nums[i-1]*pref[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            ans.push_back(suf[i]*pref[i]);
        }
        return ans;

    }
};