class Solution {
public:
    int digits(int n){
        int c=0;
        for(int i=n;i>0;i=i/10){
            c++;
        }
        return c;
    }
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(digits(nums[i])%2==0) count++;
        }
        return count;
    }
};