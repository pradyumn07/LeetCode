class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()) return false;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(int i=0;i<word1.length();i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }
        for (auto &it : mp1) {
            if (mp2.find(it.first) == mp2.end()) return false;
        }
        multiset<int> st;
        for(auto it:mp2){
            st.insert(it.second);
        }
        for(auto it:mp1){
             auto pos = st.find(it.second);
            if (pos != st.end()) {
                st.erase(pos);   // erase just one
            } else {
                return false;
            }
        }
    if(st.size()==0) return true;
    return false;
    }
};