class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mpp;
        for(auto i:word){
            mpp[i]++;
        }
        vector<int> v;
        for(auto i:mpp){
            v.push_back(i.second);
        }
        sort(v.begin(),v.end(),greater<int>());
        int ans=0,ct=0;
        for(auto i:v){
            ct++;
            if(ct<=8){
                ans+=1*i;
            }
            else if(ct<=16){
                ans+=2*i;
            }
            else if(ct<=24){
                ans+=3*i;
            }
            else{
                ans+=4*i;
            }
        }
        return ans;
    }
};