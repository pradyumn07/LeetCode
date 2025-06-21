class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n=word.length();
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[word[i]-'a']++;
        }
        sort(freq.begin(),freq.end());
        int i=0,j=n-1;
        int count=0;
        int ans=INT_MAX;
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            int target=freq[i];
            int deletions=0;
            for(int j=0;j<26;j++){
                if(freq[j]>target+k){
                    deletions+=freq[j]-(target+k);
                } else if(freq[j]<target){
                    deletions+=freq[j];
                }
            }
            ans=min(ans,deletions);
        }
        return ans;
    }
};