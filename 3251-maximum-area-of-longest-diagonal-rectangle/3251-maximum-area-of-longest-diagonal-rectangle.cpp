class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        int maxi=INT_MIN;
        int maxarea=INT_MIN;
        int ind;
        for(int i=0;i<n;i++){
            int len=dimensions[i][0];
            int wid=dimensions[i][1];
            int diag=(len*len)+(wid*wid);
            int area=len*wid;
            if(maxi<diag || (maxi==diag && maxarea<area)){
                maxi=diag;
                maxarea=area;
            }
        }
        return maxarea;
    }
};