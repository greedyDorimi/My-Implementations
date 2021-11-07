int MAX = 10000007;

void shortest_distance(vector<vector<int>>&ar){
    int n = ar.size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(ar[i][j] == -1) {
                ar[i][j] = MAX;
            }
        }
        ar[i][i] = 0;
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(ar[i][k] != MAX && ar[k][j] != MAX) {
                    ar[i][j] = min(ar[i][j], ar[i][k] + ar[k][j]);
                }
            }
        }
    }
}
