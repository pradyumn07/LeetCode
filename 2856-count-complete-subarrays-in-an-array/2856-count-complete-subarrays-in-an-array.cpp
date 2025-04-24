class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        int n=nums.size();
        for(int i=0;i<nums.size();i++) st.insert(nums[i]);
        int count=st.size();
        unordered_map<int,int> mp;
        int c=0;
        int i=0,j=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()==count){
                c+=n-j;
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return c;

    }
};