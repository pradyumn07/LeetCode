class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0,sum2=0,c1=0,c2=0;
        for(int i=0;i<nums1.size();i++){
            sum1+=nums1[i];
            if(nums1[i]==0) c1++;
        } 
        for(int i=0;i<nums2.size();i++){
            sum2+=nums2[i];
            if(nums2[i]==0) c2++;
        } 
        long long min1=sum1+c1;
        long long min2=sum2+c2;
        if(min1>min2 && c2==0) return -1;
        if(min1<min2 && c1==0) return -1;
        return max(min1,min2);
    }
};