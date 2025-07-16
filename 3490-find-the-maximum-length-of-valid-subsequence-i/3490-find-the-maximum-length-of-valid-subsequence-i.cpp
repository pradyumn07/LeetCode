class Solution {
public:
    int maximumLength(vector<int>& nums) {
        if(nums.size()<3) return nums.size();
        int o=0,e=0,oe=0,eo=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                e++;
                oe=eo+1;
            } else {
                o++;
                eo=oe+1;
            }
        }
        return max({e,o,eo,oe});
    }
};