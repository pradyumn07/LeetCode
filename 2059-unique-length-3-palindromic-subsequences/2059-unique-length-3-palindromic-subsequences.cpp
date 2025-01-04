class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        unordered_set<char> letters;
        for(int i=0;i<n;i++){
            letters.insert(s[i]);
        }
        int ans=0;
        for(char letter:letters){
            int left=-1;
            int right=-1;
            for(int i=0;i<n;i++){
                if(s[i]==letter){
                    if(left==-1){
                        left=i;
                    }
                    right=i;
                }
            }
            unordered_set<char> st;
            for(int j=left+1;j<=right-1;j++){
                st.insert(s[j]);
            }
            ans+=st.size();
        }
        return ans;
    }
};