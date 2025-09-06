class Solution {
public:
    vector<int> generaterows(int row){
        long long ans=1;
        vector<int> temp;
        temp.push_back(1);
        for(int i=1;i<row;i++){
            ans=ans*(row-i);
            ans=ans/i;
            temp.push_back(ans);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generaterows(i));
        }
        return ans;

    }
};