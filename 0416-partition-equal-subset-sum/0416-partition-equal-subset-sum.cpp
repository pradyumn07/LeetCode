class Solution {
public:
    bool subsetSum(int n, int k, vector<int>& arr) {
        vector<bool> prev(k + 1, false), cur(k + 1, false);
        prev[0] = true; // Subset sum 0 is always possible

        if (arr[0] <= k) {  // Ensure the first element does not exceed the target
            prev[arr[0]] = true;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                bool notTake = prev[target];
                bool take = false;
                if (arr[ind] <= target) {
                    take = prev[target - arr[ind]];
                }
                cur[target] = take || notTake;
            }
            prev = cur;
        }
        return prev[k];
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }
        if (total % 2 != 0) {
            return false;
        }
        int target = total / 2;
        return subsetSum(n, target, nums);
    }
};
