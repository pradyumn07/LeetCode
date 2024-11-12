class Solution {
public:
    
    int binSearch(vector<vector<int>>& items,int price){
        int l=0;
        int r=items.size()-1;
        int mid;    
        int maxi=0;
        while(l<=r){
            mid=l+(r-l)/2;
            if(items[mid][0]>price){
                r=mid-1;
            } else {
                maxi=max(maxi,items[mid][1]);
                l=mid+1;
                
            }
        }
        return maxi;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=items.size();
        int m=queries.size();
        vector<int> ans(m);
        sort(begin(items),end(items));
        int maxBeauty=items[0][1];
        for(int i=0;i<n;i++){
            maxBeauty=max(maxBeauty,items[i][1]);
            items[i][1]=maxBeauty;
            
        }
        for(int i=0;i<m;i++){
            int price=queries[i];
            ans[i]=binSearch(items,price);
        }
        return ans;
    }
};