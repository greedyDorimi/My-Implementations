void dfs(int node, int parent, vector<int> adj[], vector<int>& vis, int& cycle) {
    vis[node] = 1;
    for(int child: adj[node]) {
        if(!vis[child]) {
            dfs(child, node, adj, vis, cycle);
        } else if(child != parent) {
            cycle = 1;
        }
    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
    int n = A;
    vector<int> vis(n+1, 0);
    vector<int> adj[n+1];
    for(auto it: B) {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cycle = 0;
    for(int i = 1; i <= A; i++) {
        if(!vis[i]) {
            dfs(i, -1, adj, vis, cycle);
        }
    }
    return cycle;
}
