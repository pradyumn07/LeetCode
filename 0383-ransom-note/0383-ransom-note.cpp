class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> freq;
        for(int i=0;i<ransomNote.length();i++){
            freq[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.length();i++){
            if(freq.find(magazine[i])!=freq.end()){
                freq[magazine[i]]--;
            }
            
        }
        for(auto it:freq){
            if(it.second>0) return false;
        }
        return true;
    }
};