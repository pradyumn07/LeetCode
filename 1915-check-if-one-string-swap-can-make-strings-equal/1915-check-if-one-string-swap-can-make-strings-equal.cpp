class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        if(m!=n) return false;
        vector<int> diff;
        for(int i=0;i<m;i++){
            if(s1[i]!=s2[i]){
                diff.push_back(i);
                if(diff.size()>2) return false;
            }
        }
        if(diff.size()==0) return true;
        if(diff.size()!=2) return false;
        return (s1[diff[0]]==s2[diff[1]] && s1[diff[1]]==s2[diff[0]]);
    }
};