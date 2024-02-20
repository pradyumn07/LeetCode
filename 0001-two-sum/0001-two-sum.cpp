class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr;
        int f=0;
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(f==0)
            for(int j=i+1;j<len;j++){
                if((nums[i]+nums[j])==target)
                {
                    arr.push_back(i);
                    arr.push_back(j);
                    f=1;
                    break;
                }
            }
        }
        return arr;
    }
};