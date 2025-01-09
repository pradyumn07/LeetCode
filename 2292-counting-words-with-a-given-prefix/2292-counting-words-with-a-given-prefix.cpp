class Solution {
public:
    bool isPrefix(string &s1,string &s2){
        int m=s1.size();
        int n=s2.size();
        for(int i=0;s2[i]!='\0';i++){
            if(s1[i]!=s2[i]) return false;
        }
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(isPrefix(words[i],pref)) count++;
        }
        return count;
    }
};