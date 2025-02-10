class Solution {
public:
    string clearDigits(string s) {
        stack<int> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            char ch=st.top();
            ans=ch+ans;
            st.pop();
        }
        return ans;
    }
};