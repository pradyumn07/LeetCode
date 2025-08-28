class Solution {
public:
    string removeStars(string s) {
      stack<char> st;
      int i=0;
      string ans="";
      while(i<s.length()){
        char ch=s[i];
        if(ch=='*' && !st.empty()){
            st.pop();
        }
        else{
            st.push(ch);
        }
        i++;
      } 
      while(!st.empty()){
        char ch=st.top();
        st.pop();
        ans+=ch;
      } 
      reverse(ans.begin(),ans.end());
      return ans;
    }
};