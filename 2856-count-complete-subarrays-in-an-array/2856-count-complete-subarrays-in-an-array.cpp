class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        int n=nums.size();
        for(int i=0;i<nums.size();i++) st.insert(nums[i]);
        int count=st.size();
        // unordered_set<int> stt;
        // stt.insert(nums[0]);
        // int c=0;
        // int i=0,j=i+1;
        // while(i<n){
        //     if(count==stt.size()) c++;
        //     // while(stt.size()>count){
        //     //     stt.erase(stt.begin());
        //     //     i++;
        //     // }
        //     if(j==n && i<n-1){
        //         stt.clear();
        //         stt.insert(nums[i+1]);

        //         i++;
        //         j=i+1;
        //         continue;
        //     }
        //     stt.insert(nums[j]);
        //     j++;


        // }
        // return c;
        int c=0;
        for(int i=0;i<n;i++){
            unordered_set<int> stt;
            for(int j=i;j<n;j++){
                stt.insert(nums[j]);
                if(stt.size()==count) c++;
            }
        }
        return c;
    }
};