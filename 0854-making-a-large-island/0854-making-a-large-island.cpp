class DisjointSet{
    public:
        vector<int> rank,parent,size;
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
                size[i]=1;

            }
        }
        int findUPar(int node){
            if(node==parent[node]) return node;
            return parent[node]=findUPar(parent[node]);
        }
        void unionBySize(int u,int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);
            if(ulp_u==ulp_v) return;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }

};
class Solution {
public:
    bool isValid(int row, int col, int n) {
        return row >= 0 && col >= 0 && row < n && col < n;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;
                int dr[] = {-1, 0, +1, 0};
                int dc[] = {0, -1, 0, +1};
                for (int i = 0; i < 4; i++) {
                    int newrow = row + dr[i];
                    int newcol = col + dc[i];
                    if (isValid(newrow, newcol, n) && grid[newrow][newcol] == 1) {
                        int nodeno = row * n + col;
                        int adjnode = newrow * n + newcol;
                        ds.unionBySize(nodeno, adjnode);
                    }
                }
            }
        }
        int mx = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) {
                    int dr[] = {-1, 0, +1, 0};
                    int dc[] = {0, -1, 0, +1};
                    set<int> components;
                    for (int i = 0; i < 4; i++) {
                        int newrow = row + dr[i];
                        int newcol = col + dc[i];
                        if (isValid(newrow, newcol, n) && grid[newrow][newcol] == 1) {
                            components.insert(ds.findUPar(newrow * n + newcol));
                        }
                    }
                    int sizeT = 1; 
                    for (auto it : components) {
                        sizeT += ds.size[it];
                    }
                    mx = max(mx, sizeT);
                }
            }
        }
        for (int cell = 0; cell < n * n; cell++) {
            mx = max(mx, ds.size[ds.findUPar(cell)]);
        }
        return mx;
    }
};