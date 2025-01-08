class Solution {
public:
    bool isPrefix(string &s1,string &s2){
        int m=s1.size();
        int n=s2.size();
        if(m>n) return false;
        for(int i=0;s1[i]!='\0';i++){
            if(s1[i]!=s2[i]) return false;
        }
        return true;
    }
    bool isSuffix(string &s1,string &s2){
        int m=s1.size();
        int n=s2.size();
        if(m>n) return false;
        for(int i=m-1;i>=0;i--){
            if(s1[i]!=s2[n-(m-i)]) return false;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(isPrefix(words[i],words[j] ) && isSuffix(words[i],words[j])){
                    count++;
                }
            }
        }
        return count;
    }

};