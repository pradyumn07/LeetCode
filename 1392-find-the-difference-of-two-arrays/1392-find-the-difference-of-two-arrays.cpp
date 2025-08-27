class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        unordered_set<int> st1;
        unordered_set<int> st2;
        for(int i=0;i<nums2.size();i++) st1.insert(nums2[i]);
        for(int i=0;i<nums1.size();i++) st2.insert(nums1[i]);
        vector<int> temp1;
        for(int i=0;i<nums1.size();i++){
            if(st1.find(nums1[i])==st1.end()){
                st1.insert(nums1[i]);
                temp1.push_back(nums1[i]);
            }
        }
        ans.push_back(temp1);
        vector<int> temp2;
        for(int i=0;i<nums2.size();i++){
            if(st2.find(nums2[i])==st2.end()){
                st2.insert(nums2[i]);
                temp2.push_back(nums2[i]);
            }
        }
        ans.push_back(temp2);
        return ans;
    }
};