#include<bits/stdc++.h>
using namespace std;

int block_size;

void update(vector<int> &v, vector<int> &block, int old_val, int new_val) {
    // Method 1: brute force to find the idx of the elememnt
    int n = v.size(), i;
    for(i=0; i<n; ++i) {
        if(v[i] == old_val) {
            v[i] = new_val;
            break;
        }
    }

    int blockNumber = i / block_size;

    if(old_val & 1) block[blockNumber]--;
    if(new_val & 1) block[blockNumber]++;    
}

int query(vector<int> &v, vector<int> &block, int l, int r) {
    int odd_cnt = 0;
    while(l < r and l % block_size != 0 and l != 0) {
        odd_cnt += (v[l] & 1);
        l++;
    }
    while(l + block_size <= r) {
        odd_cnt += block[l/block_size];
        l += block_size;
    }
    while(l <= r) {
        odd_cnt += (v[l] & 1);
        l++;
    }
    return odd_cnt;
}


// fills block
void preprocess(vector<int> &v, vector<int> &block){
    int n = v.size();
    int blk_idx = -1;
    block_size = sqrt(n);
    block.resize(block_size);

    // building the decomposed vector
    for(int i=0; i<n; ++i){
        block[i / block_size] += (v[i] & 1);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x: v) cin >> x;
    int q;
    cin >> q;
    vector<int> block;
    preprocess(v, block);

    for(int i=0; i<q; ++i){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1) {
            update(v, block, l, r);
        } else {
            cout << query(v, block, l-1, r-1) << endl;
        }
    }
    return 0;
}
