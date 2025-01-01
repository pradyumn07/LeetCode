class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int maxi = INT_MIN;
        for (int i = 1; i < n; i++) {
            int leftScore = 0, rightScore = 0;
            for (int j = 0; j < i; j++) {
                if (s[j] == '0') leftScore++;
            }
            for (int j = i; j < n; j++) {
                if (s[j] == '1') rightScore++;
            }
            maxi = max(maxi, leftScore + rightScore);
        }
        return maxi;
    }
};
