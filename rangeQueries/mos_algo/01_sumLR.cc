#include<bits/stdc++.h>
using namespace std;

int block_size;

bool compare(vector<int> &a, vector<int> &b) {
    if(a[0] / block_size != b[0] / block_size) {
        return a[0] / block_size < b[0] / block_size;
    }
    return a[1] < b[1];
}

void query(vector<int> &v, vector<vector<int>> &queries) {

    int n = v.size();
    int q = queries.size();
    block_size = sqrt(n);

    sort(queries.begin(), queries.end(), compare);

    // initialize current l, r and sum
    int cl=0, cr=0, csum=0;

    for(int i=0; i<q; ++i) {
        int l = queries[i][0];
        int r = queries[i][1];

        while(cl < l){
            csum -= v[cl];
            cl++;
        }

        // add elements of current range
        while(cl > l) {
            csum += v[cl - 1];
            cl--;
        }

        while(cr <= r) {
            csum += v[cr];
            cr++;
        }

        // Remove elements of previous range.  For example
        // when previous range is [0, 10] and current range
        // is [3, 8], then a[9] and a[10] are subtracted
        while (cr > r+1) {
            csum -= v[cr - 1];
            cr--;
        }

        // print sum of current range
        {
            /* code */
            cout << "Sum of [" << l << ", " << r << "] is " << csum << endl;
        }
        
    }
}



int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;

    int q; cin >> q;
    vector<vector<int>> queries(q, vector<int>(3, 0));
    
    for(auto &x: queries) {
        cin >> x[0] >> x[1];
    }

    query(v, queries);
}