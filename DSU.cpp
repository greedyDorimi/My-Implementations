vector<int> parent(300005, 0); 
vector<int> ranks(300005, 1);

void build(int A) {
    for(int i = 1; i <= A; i++) {
        parent[i] = i;
    }
}

int find_parent(int node) {
    if(parent[node] == node)return node;
    return parent[node] = find_parent(parent[node]);
}

void merge(int node1, int node2) {
    if(ranks[node1] > ranks[node2]) {
        parent[node2] = node1;
        ranks[node1] += ranks[node2];
    } else {
        parent[node1] = node2;
        ranks[node2] += ranks[node1];
    }
}

void _union(int node1, int node2) {
    int p1 = find_parent(node1);
    int p2 = find_parent(node2);
    if(p1 != p2) {
        merge(p1, p2);
    } 
}

int Solution::solve(int A, vector<vector<int> > &B) {
    build(A);
    for(int i = 0; i < B.size(); i++) {
        int u = B[i][0], v = B[i][1];
        if(find_parent(u) == find_parent(v))return 1;
        _union(u, v);
    }
    return 0;
}
