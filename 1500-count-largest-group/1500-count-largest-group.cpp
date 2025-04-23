class Solution {
public:
    int digits(int n){
        int sum=0;
        for(int j=n;j>0;j=j/10){
            int r=j%10;
            sum+=r;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
       
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            int s=digits(i);
            mp[s]++;
            
        }
        int maxima=0;
        for(auto m:mp){
            if(maxima<m.second) maxima=m.second;
        }
        int count=0;
        for(auto m:mp){
            if(m.second==maxima) count++;
        }
        return count;
    }
};