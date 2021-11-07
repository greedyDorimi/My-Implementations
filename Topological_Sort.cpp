vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];
    vector<int> topology_sort;
    vector<int> in_degree(numCourses, 0);
    for(int i = 0; i < prerequisites.size(); i++) {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        adj[v].push_back(u);
        in_degree[u]++;
    }
    queue<int> q;
    for(int i = 0; i < numCourses; i++) {
        if(in_degree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int node = q.front();
        topology_sort.push_back(node);
        q.pop();
        for(int child: adj[node]) {
            in_degree[child]--;
            if(in_degree[child] == 0) {
                q.push(child);
            }
        }
    }

    for(int i = 0; i < numCourses; i++) {   // detecting cycle - Approach-1
        if(in_degree[i] != 0) {
            topology_sort.clear();
        }
    }

    // if(topology_sort.size() != numCourses) {    // detecting cycle - Approach-2
    //     topology_sort.clear();
    // }

    return topology_sort;
}
