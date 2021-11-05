void dfs(int node, vector<int> adj[], vector<int>& vis, int& ans) {
    vis[node] = 1;
    for(int child: adj[node]) {
        if(!vis[child]) {
            dfs(child, adj, vis, ans);
        } else if(vis[child] == 1) {
            ans = 0;
        }
    }
    vis[node] = 2;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int n = numCourses;
    vector<int> adj[n];
    vector<int> vis(n, 0);
    for(auto it: prerequisites) {
        adj[it[1]].push_back(it[0]);
    }
    int ans = 1;
    for(int i = 0; i < numCourses; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis, ans);
        }
    }
    return ans;
}
