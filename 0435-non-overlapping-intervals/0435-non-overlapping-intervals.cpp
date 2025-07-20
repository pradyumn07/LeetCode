class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> inter;
        for(int i=0;i<intervals.size();i++){
            vector<int> arr={intervals[i][1],intervals[i][0]};
            inter.push_back(arr);
        }
        sort(inter.begin(),inter.end());
        int count=0;
        int free=inter[0][0];
        for(int i=0;i<inter.size();i++){
            if(i==0 || free<=inter[i][1]){
                count++;
                free=inter[i][0];
            }
        }
        return inter.size()-count;
    }
};