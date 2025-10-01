class Solution {
public:
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map<int,int> mp;
        vector<int> result;
        stack<int> st;
        int i=n-1;
        while(i>=0){
            while(!st.empty() && st.top()<nums2[i]) st.pop();
            if(st.empty()) mp[nums2[i]]=-1;
            else mp[nums2[i]]=st.top();
            
            st.push(nums2[i]);

            i--;
        }
        for(int j=0;j<nums1.size();j++){
            result.push_back(mp[nums1[j]]);
        }
        return result;
    }
};