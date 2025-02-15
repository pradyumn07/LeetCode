class Solution {
public:
    bool solve(int k,int curr,string s,int num){
        if(k==s.length()) return curr==num;
        if(curr>num) return false;
        bool possible=false;
        for(int j=k;j<s.length();j++){
            string sub=s.substr(k,j-k+1);
            int val=stoi(sub);
            possible=possible||solve(j+1,curr+val,s,num);
            if(possible==true) return true;
        }
        return possible;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int sq=i*i;
            string s=to_string(sq);
            if(solve(0,0,s,i)==true){
                ans+=sq;
            }
        }
        return ans;
    }
};