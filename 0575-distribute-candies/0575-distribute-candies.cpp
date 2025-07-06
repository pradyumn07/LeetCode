class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;
        int n=candyType.size();
        for(int i=0;i<candyType.size();i++) st.insert(candyType[i]);
        if(n/2<st.size()) return n/2;
        else return st.size();
    }
};