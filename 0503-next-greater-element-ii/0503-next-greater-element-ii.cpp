class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        int n=nums.size();
        stack<int> st;
        int i=2*n-1;
        while(i>=0){
            while(!st.empty() && st.top()<=nums[i%n]) st.pop();
            if(i<n){
                if(st.empty()) ans[i]=-1;
                else ans[i]=st.top();
            }
            
            st.push(nums[i%n]);
            i--;
        }
        return ans;
    }
};