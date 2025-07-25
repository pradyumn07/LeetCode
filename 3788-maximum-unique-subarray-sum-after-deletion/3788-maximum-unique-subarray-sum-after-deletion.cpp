class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        int maxNeg=INT_MIN;
        int sum=0;
        for(int& num:nums){
            if(num<=0){
                maxNeg=max(maxNeg,num);
            } else if(!st.count(num)){
                sum+=num;
                st.insert(num);
            }
        }
        return sum==0?maxNeg:sum;
    }
};