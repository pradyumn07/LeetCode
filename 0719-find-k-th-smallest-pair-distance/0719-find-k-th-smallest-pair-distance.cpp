class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.back() - nums.front();

        
        while (left < right) {
            int mid = (left + right) >> 1; 
            if (countPairsWithDistance(nums, mid) >= k)
                right = mid;
            else 
                left = mid + 1;
        }

        
        return left;
    }

private:
    
    int countPairsWithDistance(const vector<int>& nums, int dist) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int target = nums[i] - dist;
            int j = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

            
            count += i - j;
        }
        return count;
    }
};