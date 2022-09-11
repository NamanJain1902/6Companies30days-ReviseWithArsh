#include<bits/stdc++.h>
using namespace std;


int block_size;

// O(1)
void update(vector<int> &v, vector<int> &block, int idx, int new_val) {
    int blockNumber = idx / block_size;
    block[blockNumber] += new_val - v[idx];
    v[idx] = new_val;
}

// O(sqrt(n))
int query(vector<int> &v, vector<int> &block, int l, int r) {
    int sum = 0;

    while(l < r and l % block_size != 0 and l!= 0) {
        sum += v[l];
        l++;
    }

    // // traversing completely overlapped blocks in range
    while(l + block_size <= r) {
        sum += block[l / block_size];
        l += block_size;
    }

    // traversing last block in range
    while(l <= r) {
        sum += v[l];
        l++;
    }

    return sum;
}

// fills block
void preprocess(vector<int> &v, vector<int> &block){
    int n = v.size();
    int blk_idx = -1;
    block_size = sqrt(n);
    block.resize(block_size);

    // building the decomposed vector
    for(int i=0; i<n; ++i){
        block[i / block_size] += v[i];

        // if(i % block_size == 0){
        //     blk_idx++;
        // }
        // block[blk_idx] += v[i];
    }
}

int main()
{
    vector<int> v = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10};
    vector<int> block;

    preprocess(v, block);

    for(auto x: block) cout << x << " ";
    cout << endl;

    cout << "query(3, 8) " << query(v, block, 3, 8) << endl;
    cout << "query(1,6) : " << query(v, block,1, 6) << endl;
    update(v, block, 8, 0);
    cout << "query(8,8) : " << query(v, block,8, 8) << endl;

    return 0;
}