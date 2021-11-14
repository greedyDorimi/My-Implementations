bool valid(long long time, int A, long long B, vector<int>& C) {
    int n = C.size();
    long long counter = 0,painters = 1;
    for(int i = 0; i < n; i++) {
        if(time >= (C[i] * B) + counter) {
            counter += (C[i] * B);
        } else if(C[i]*B <= time){
            counter = C[i]*B;
            painters++;
        } else {
            return false;
        }
    }
    if(painters <= A)return true;
    return false;
}

int Solution::paint(int A, int B, vector<int> &C) {
    int n = C.size();
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += C[i];
    }
    long long l = B, r = sum*B;
    long long ans = r;
    while(l <= r) {
        long long mid = (l + r) / 2;
        if(valid(mid, A, B, C)) {
            ans = min(ans, mid);
            r = mid - 1;;
        } else {
            l = mid + 1;;
        }
    }
    return ans % 10000003;
}
