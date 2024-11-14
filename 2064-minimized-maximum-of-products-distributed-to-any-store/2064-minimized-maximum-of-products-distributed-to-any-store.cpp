class Solution {
public:
    bool possible(int x,vector<int>& quantities,int shop){
        for(int& products:quantities){
            shop-=(products+x-1)/x;
            if(shop<0) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        int l=1;
        int r=*max_element(begin(quantities),end(quantities));
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(possible(mid,quantities,n)){
                ans=mid;
                r=mid-1;
                
            } else {
                l=mid+1;
            }
        }
        return ans;
    }
};