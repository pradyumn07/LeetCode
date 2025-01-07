class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> st;
        vector<string> ans;
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(words[j].find(words[i])!=string::npos){
                    st.insert(words[i]);
                }
            }
        }
        for (auto it = st.begin(); it != st.end(); it++) ans.push_back(*it);
        return ans;


    }
};