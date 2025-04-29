class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<map<int,int>> mx(n+1),my(n+1);
        for(int i=0;i<buildings.size();i++){
            int x=buildings[i][0];
            int y=buildings[i][1];
            mx[x][y]++;
            my[y][x]++;
        }
        int count=0;
        for(int i=0;i<buildings.size();i++){
            int x=buildings[i][0];
            int y=buildings[i][1];
            auto it1=mx[x].upper_bound(y);
            auto it2=mx[x].lower_bound(y);
            auto it3=my[y].upper_bound(x);
            auto it4=my[y].lower_bound(x);
            if(it1!=mx[x].end() && it2!=mx[x].begin() && it3!=my[y].end() && it4!=my[y].begin()) count++;

        }
        return count;
    }
};