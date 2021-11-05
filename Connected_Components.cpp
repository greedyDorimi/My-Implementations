void dfs(int cur_friend, vector<vector<int>>& friends, vector<int>& vis) {
    vis[cur_friend] = 1;
    for(int frnd: friends[cur_friend]) {
        if(!vis[frnd]) {
            dfs(frnd, friends, vis);
        }
    }
}

int solve(vector<vector<int>>& friends) {
    int n = friends.size();
    vector<int> vis(n, 0);
    int groups = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            groups++;
            dfs(i, friends, vis);
        }
    }
    return groups;
}
