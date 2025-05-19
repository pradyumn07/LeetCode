class Solution {
public:
    string triangleType(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);

        }
        if(nums[0]+nums[1]<=nums[2] || nums[0]+nums[2]<=nums[1] || nums[1]+nums[2]<=nums[0]) return "none";
        if(st.size()==3) return "scalene";
        else if(st.size()==1) return "equilateral";
        else return "isosceles";
    }
};