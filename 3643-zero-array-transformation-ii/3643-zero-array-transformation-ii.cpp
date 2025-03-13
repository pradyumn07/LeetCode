class Solution {
public:
    // Checks if after applying first 'count' queries, all nums[j] + diff <= 0
    bool isValid(vector<int>& nums, vector<vector<int>>& queries, int count) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);  // difference array

        // Apply first 'count' queries (0 to count-1)
        for (int k = 0; k < count; k++) {
            int l = queries[k][0];
            int r = queries[k][1];
            int val = queries[k][2];

            diff[l] -= val;
            if (r + 1 < n) {
                diff[r + 1] += val;
            }
        }

        // Calculate prefix sum from diff and check condition
        int cumSum = 0;
        for (int j = 0; j < n; j++) {
            cumSum += diff[j];
            if (nums[j] + cumSum > 0) {
                return false;  // Condition failed
            }
        }

        return true;  // Condition satisfied
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // Edge case: nums is already zero array
        bool alreadyZero = true;
        for (int x : nums) {
            if (x > 0) {
                alreadyZero = false;
                break;
            }
        }
        if (alreadyZero) return 0;

        int lo = 1, hi = queries.size(), answer = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (isValid(nums, queries, mid)) {
                answer = mid;
                hi = mid - 1;  // Try to find smaller number of queries
            } else {
                lo = mid + 1;  // Need more queries
            }
        }

        return answer;
    }
};
