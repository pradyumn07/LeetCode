class Solution {
public:
    bool check(stack<char> &st,string &part,int n){
        stack<char> temp=st;
        for(int i=n-1;i>=0;i--){
            if(temp.top()!=part[i]) return false;
            temp.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        int n=part.length();
        int m=s.length();
        stack<char> st;
        for(int i=0;i<m;i++){
            st.push(s[i]);
            if(st.size()>=n && check(st,part,n)){
                for(int j=0;j<n;j++){
                    st.pop();
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};