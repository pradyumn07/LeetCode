class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int idx=0;
        int i=0;
        while(i<n){
            char curr=chars[i];
            int count=0;
            while(i<n && chars[i]==curr){
                i++;
                count++;
            }
            chars[idx]=curr;
            idx++;
            if(count>1){
                string countstr=to_string(count);
                for(char& ch:countstr){
                    chars[idx]=ch;
                    idx++;
                }
            }
        }
        return idx;
    }
};