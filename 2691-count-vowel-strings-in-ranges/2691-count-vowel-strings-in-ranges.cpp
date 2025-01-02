class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
         unordered_set<char> set;
        set.insert('a');
        set.insert('e');
        set.insert('i');
        set.insert('o');
        set.insert('u');
        vector<int> uptos;
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            int n = words[i].size();
            if (set.find(words[i][0]) != set.end() &&
                set.find(words[i][n - 1]) != set.end()) {
                count++;
            }
            uptos.push_back(count);
        }
        vector<int> result;
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] == 0) {
                result.push_back(uptos[queries[i][1]]);
            } else
                result.push_back(uptos[queries[i][1]] -
                                 uptos[queries[i][0] - 1]);
        }
        return result;
    }
};