class Solution {
public:
    int getLucky(string s, int k) {
        string transformed;
        for (char c : s) {
            transformed += to_string(c - 'a' + 1);
        }
        while (k--) {
            int sumDigits = 0;
            for (char digitChar : transformed) {
                sumDigits += digitChar - '0';
            }
            transformed = to_string(sumDigits);
        }
        return stol(transformed);
    }
};