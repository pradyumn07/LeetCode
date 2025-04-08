class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int m=baskets.size();
        int count=0;
        vector<bool> vis(m,false);
        for(int i=0;i<n;i++){
            bool f=false;
            for(int j=0;j<m;j++){
                if(fruits[i]<=baskets[j] && vis[j]==false){
                    vis[j]=true;
                    f=true;
                    break;
                }
            }
            if(f==false) count++;
        }
        return count;
    }
};