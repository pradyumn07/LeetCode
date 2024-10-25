class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st(begin(folder),end(folder));
        vector<string> ans;
        for(string current:folder){
            bool isSub=false;
            string temp=current;
            
            while(!current.empty()){
                auto position=current.find_last_of('/');
                current=current.substr(0,position);
                if(st.find(current)!=st.end()){
                    isSub=true;
                    break;
                }
            }
            if(!isSub){
                ans.push_back(temp);
            }
        }
        return ans;
    }
};