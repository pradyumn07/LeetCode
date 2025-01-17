class Solution {
public:
    int reverse(int x) {
        long long r, sum = 0;
        while (x != 0) {
            r = x % 10;
            sum = sum * 10 + r;
            if (sum > INT_MAX || sum < INT_MIN) {
                return 0;
            }
            x /= 10;
        }
        return static_cast<int>(sum);
    }
};