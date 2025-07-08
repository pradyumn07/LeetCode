class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set st(nums.begin(),nums.end());
        priority_queue<int> pq;
        for(int num:st){
            pq.push(num);
        }
        int ans;
        int k=3;
        if(pq.size()<3) return pq.top();
        else{
            while(k--){
                
                ans=pq.top();
                pq.pop();
                
            }
        }
        return ans;
    }
};