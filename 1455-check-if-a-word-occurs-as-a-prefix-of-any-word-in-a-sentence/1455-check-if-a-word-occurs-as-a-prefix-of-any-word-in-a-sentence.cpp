class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string s;
        int ans=0;
        stringstream sst(sentence);
        while(sst>>s){
            ans++;
            if(s.find(searchWord)==0) return ans;
            
        }
        return -1;
        
    }
};