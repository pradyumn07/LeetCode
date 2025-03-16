class Solution {
public:
    typedef long long ll;

    bool isPossible(vector<int>& ranks, ll mid, int cars) {
        ll carFixed = 0;
        for (int i = 0; i < ranks.size(); i++) {
            carFixed += (ll)sqrt(mid / (double)ranks[i]); // Ensure correct integer division
            if (carFixed >= cars) return true; // Early exit for optimization
        }
        return carFixed >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        ll l = 0, r = 1LL * (*min_element(ranks.begin(), ranks.end())) * cars * cars;
        ll ans = r; // Set to max possible value initially

        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (isPossible(ranks, mid, cars)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
