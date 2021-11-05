void dfs(int cur_node, vector<vector<int>>& rooms, vector<int>& vis) {
    int n = rooms.size();
    vis[cur_node] = 1;
    for(int child: rooms[cur_node]) {
        if(!vis[child]) {
            dfs(child, rooms, vis);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<int> vis(n, 0);
    dfs(0, rooms, vis);
    for(int is_vis: vis) {
        if(!is_vis)return false;
    }
    return true;
}
