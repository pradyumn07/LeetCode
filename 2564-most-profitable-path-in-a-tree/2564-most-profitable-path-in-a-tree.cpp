class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        // Build graph as an adjacency list.
        vector<vector<int>> graph(n);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        // Step 1: Compute parent array via BFS starting at node 0.
        vector<int> parent(n, -1);
        queue<int> q;
        q.push(0);
        parent[0] = -1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                q.push(v);
            }
        }
        
        // Step 2: Compute Bob's arrival times along the unique path from bob to 0.
        // For nodes on Bob's path, bobTime[node] is the time at which Bob reaches that node.
        // For nodes not on Bob's path, bobTime remains -1.
        vector<int> bobTime(n, -1);
        int t = 0;
        int node = bob;
        while (node != -1) {
            bobTime[node] = t;
            node = parent[node];
            t++;
        }
        
        // Step 3: DFS for Alice starting from node 0.
        int maxi = INT_MIN;
        int income = 0;
        dfsAlice(0, -1, 0, income, maxi, graph, bobTime, amount);
        return maxi;
    }
    
private:
    // DFS function that uses backtracking on the income.
    void dfsAlice(int u, int par, int time, int &income, int &maxi, 
                  const vector<vector<int>> &graph, 
                  const vector<int> &bobTime, 
                  const vector<int> &amount) {
        // Compute the additional income at node u.
        int addVal = 0;
        if (bobTime[u] == -1) {
            // Bob never visits this node.
            addVal = amount[u];
        } else {
            if (time < bobTime[u])
                addVal = amount[u];         // Alice arrives before Bob.
            else if (time == bobTime[u])
                addVal = amount[u] / 2;       // They arrive at the same time.
            // If time > bobTime[u], Bob reached earlier; addVal remains 0.
        }
        
        // Add the computed value to income.
        income += addVal;
        
        // If u is a leaf (other than the root), update the maximum income.
        if (u != 0 && graph[u].size() == 1) {
            maxi = max(maxi, income);
        }
        
        // Recurse for all children (neighbors) except the parent.
        for (int v : graph[u]) {
            if (v == par) continue;
            dfsAlice(v, u, time + 1, income, maxi, graph, bobTime, amount);
        }
        
        // Backtracking step: revert the income change.
        income -= addVal;
    }
};
