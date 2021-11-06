int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
    vector<int> adj[n+1];
    vector<int> wt[n+1];
    vector<int> dis(n+1, INT_MAX);
    for(int i = 0; i < times.size(); i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        adj[u].push_back(v);
        wt[u].push_back(w);
    }
    q.push(make_pair(0, k));
    dis[k] = 0;
    while(!q.empty()) {
        pair<int, int> cur_node = q.top();
        q.pop();
        int node = cur_node.second;
        for(int i = 0; i < adj[node].size(); i++) {
            int child = adj[node][i];
            if(dis[child] > dis[node] + wt[node][i]) {
                dis[child] = dis[node] + wt[node][i];
                q.push(make_pair(dis[child], child));
            }
        }
    }
    int ans = INT_MIN;
    for(int i = 1; i <= n; i++) {
        if(dis[i] == INT_MAX) {
            ans = -1;
            break;
        }
        ans = max(ans, dis[i]);
    }
    return ans;
}
