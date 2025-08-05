class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=baskets.size();
        vector<bool> vis(n,false);
        int c=0;
        for(int i=0;i<fruits.size();i++){
            int f=0;
            for(int j=0;j<n;j++){
                if(vis[j]==false && fruits[i]<=baskets[j]){
                    vis[j]=true;
                    f=1;
                    break;
                    
                }
                
            }
            if(f==0) c++;
        }
        return c;
    }
};