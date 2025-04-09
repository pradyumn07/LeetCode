class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // int n=nums.size();
        // set<int> st(nums.begin(), nums.end());
        // vector<int> sorted(st.begin(), st.end());
        // int m=st.size();
        unordered_set<int> st;
        for(int num:nums){
            if(num<k) return -1;
            else if(num>k) st.insert(num);
        }
        return st.size();
    }
};