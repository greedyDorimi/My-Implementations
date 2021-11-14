//  saare comparison ulte krne hote hai isme mtlb agar increasing krna hai to decreasing ka bnao vice-versa
auto cmp = [](pair<int, string> a, pair<int, string> b) {
    if(a.first > b.first)return true;
    else if(a.first == b.first) {
        if(a.second < b.second) {
            return true;
        }
    }
    return false;
};

priority_queue<pair<int, string>, vector<pair<int, string> >, decltype(cmp) > pq(cmp);
