class Solution {
public:
    int maxelement(vector<vector<int>>& mat,int n,int m,int mid){
        int maxi=INT_MIN,index=-1;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>maxi){
                maxi=mat[i][mid];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0,r=m-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int row=maxelement(mat,n,m,mid);
            int left=mid-1>=0?mat[row][mid-1]:-1;
            int right=mid+1<m?mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right) return {row,mid};
            else if(mat[row][mid]<left) r=mid-1;
            else l=mid+1;
        }
        return {-1,-1};
    }
};