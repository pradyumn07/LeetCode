class Solution {
public:
    int n;
    bool isDistinct(vector<int> &nums){
        unordered_set<int> st(nums.begin(),nums.end());
        return st.size()==nums.size();
    }
    int minimumOperations(vector<int>& nums) {
        n=nums.size();
        int count=0;
        
        while(!isDistinct(nums)){
            int remove= min(3,(int)nums.size());
            nums.erase(nums.begin(), nums.begin() + remove);
            count++;
        
        }
        return count;
    }
};