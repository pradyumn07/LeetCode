class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long,vector<long>,greater<long>> pq(begin(nums),end(nums));
        int count=0;
        while(pq.top()<k && !pq.empty()){
            long mini1=pq.top();
            pq.pop();
            long mini2=pq.top();
            pq.pop();
            long n=min(mini1,mini2)*2+max(mini1,mini2);
            pq.push(n);
            count++;
        }
        return count;
    }
};