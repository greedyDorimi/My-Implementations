    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> vis(V+1, 0);
        vector<int> ans;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()) {
            int cur_node = q.front();
            ans.push_back(cur_node);
            q.pop();
            for(int i = 0; i < adj[cur_node].size(); i++) {
                if(!vis[adj[cur_node][i]]) {
                    vis[adj[cur_node][i]] = 1;
                    q.push(adj[cur_node][i]);
                }
            }
        }
        return ans;
    }
