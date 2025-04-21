class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n=differences.size();
        int curr=0;
        int minv=0,maxv=0;

        for(int i=0;i<n;i++){
            curr=curr+differences[i];
            minv=min(minv,curr);
            maxv=max(maxv,curr);
            if((upper-maxv)-(lower-minv)+1<=0) return 0;
        }
        return (upper-maxv)-(lower-minv)+1;
    }
};