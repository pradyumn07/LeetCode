class Solution {
public:
    vector<int> nge(vector<int> &nums){
        int n=nums.size();
        vector<int> ans(n);
        stack<int> st;
        int i=n-1;
        while(i>=0){
            while(!st.empty() && st.top()<nums[i]) st.pop();
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(nums[i]);

            i--;
        }
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        vector<int> ans=nge(nums2);
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]) result.push_back(ans[j]);
            }
        }
        return result;
    }
};