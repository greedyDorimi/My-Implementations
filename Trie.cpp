struct node {
    int freq;
    node *ar[26];
    node() {
        freq = 0;
        for(int i = 0; i < 26; i++) {
            ar[i] = NULL;
        }
    }
};

void add(node* root, string s, int idx) {
    if(idx == s.size())return;
    if(root->ar[s[idx]-'a'] == NULL) {
        root->ar[s[idx]-'a'] = new node(); 
    }
    root->ar[s[idx]-'a']->freq++;
    add(root->ar[s[idx]-'a'], s, idx+1);
}

void find(node* root, string s, int idx, string& pref) {
    pref += s[idx];
    if(root->ar[s[idx]-'a']->freq == 1)return;
    find(root->ar[s[idx]-'a'], s, idx+1, pref);
}

vector<string> Solution::prefix(vector<string> &A) {
    vector<string> ans;
    node* root = new node();
    for(auto s: A) {
        add(root, s, 0);
    }
    for(auto s: A) {
        string pref = ""; 
        find(root, s, 0, pref);
        ans.push_back(pref);
    }
    return ans;
}
