class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> pq;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            pq.push(piles[i]);
            sum += piles[i];
        }
        for (int i = 1; i <= k; i++) {
            int mx = pq.top();  
            pq.pop();           
            int remove = mx / 2; 
            sum -= remove;      
            mx -= remove;       
            pq.push(mx);        
        }
        return sum; 
    }
};