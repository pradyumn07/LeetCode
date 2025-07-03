class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while (word.length() < k) {
            string gen = "";
            for (char ch : word) {
                gen += (ch == 'z') ? 'a' : ch + 1;
            }
            word += gen;
        }
        return word[k - 1];
    }
};
