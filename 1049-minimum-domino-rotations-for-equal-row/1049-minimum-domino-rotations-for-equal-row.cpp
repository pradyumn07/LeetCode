class Solution {
public:
    int solve(vector<int>& tops,vector<int>& bottoms,int ele){
        int top=0,bottom=0;
        for(int i=0;i<tops.size();i++){
            if(tops[i]!=ele && bottoms[i]!=ele) return -1;
            if(tops[i]!=ele) top++;
            if(bottoms[i]!=ele) bottom++;
        }
        return min(top,bottom);
        

    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_set<int> st;
        for(int i=0;i<tops.size();i++){
            st.insert(tops[i]);
            st.insert(bottoms[i]);
        }
        
        for(int val:st){
            int ans=solve(tops,bottoms,val);
            if(ans!=-1) return ans;
        }
        return -1;
    }
};