class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<bool> vis(flowerbed.size(),false);
        int l=flowerbed.size();
        for(int i=0;i<l;i++){
            if(flowerbed[i]==1){
                if(i-1>=0) vis[i-1]=true;
                if(i+1<l) vis[i+1]=true;
                vis[i]=true;

            }
        }
        for(int i=0;i<l;i++){
            if(vis[i]==false && n>0){
                if(i-1>0 && vis[i-1]==false) vis[i-1]=true;
                if(i+1<l && vis[i+1]==false) vis[i+1]=true;
                vis[i]=true;
                n--;
            }
            if(n==0) return true;
        }
        return false;
    }
};