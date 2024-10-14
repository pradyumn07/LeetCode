class Solution {
public:
    
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(begin(nums),end(nums));
        
        long long total=0;
        int topp;
        int maxEl;
        int ind;
        int nextEl;
        while(k>0){
            maxEl=pq.top();
        
            total+=pq.top();
            pq.pop();
            nextEl=ceil(maxEl/3.0);
            pq.push(nextEl);
            k--;
            
        }
        return total;
    }
};