class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(begin(intervals),end(intervals));
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][0]<ans.back()[1]){
                ans.back()[0]=min(ans.back()[0],intervals[i][0]);
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> hor;
        vector<vector<int>> ver;
        for(auto &coord:rectangles){
            int x1=coord[0];
            int y1=coord[1];
            int x2=coord[2];
            int y2=coord[3];
            hor.push_back({x1,x2});
            ver.push_back({y1,y2});
        }
        vector<vector<int>> result1=merge(hor);
        vector<vector<int>> result2=merge(ver);
        return result1.size()>=3 || result2.size()>=3;
    }
};