class Solution {
public:
    int lhist(vector<int>& heights) {
        stack<int> st;
        int maxi=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int ele=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxi=max(maxi,heights[ele]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int ele=st.top();
            st.pop();
            int nse=n;
            int pse=st.empty()?-1:st.top();
            maxi=max(maxi,heights[ele]*(nse-pse-1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> psum(n,vector<int>(m,0));
        int maxi=0;
        int sum;
        for(int j=0;j<m;j++){
            sum=0;
            for(int i=0;i<n;i++){
                if (matrix[i][j] == '1') {
                    sum += 1;
                } else {
                    sum = 0;
                }
                psum[i][j]=sum;
            }
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,lhist(psum[i]));
        }
        return maxi;

    }
};