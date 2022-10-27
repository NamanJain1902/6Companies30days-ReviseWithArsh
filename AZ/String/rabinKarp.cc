#include<bits/stdc++.h>
using namespace std;

bool compare(string pat, string txt, int i) {
    for(int j=i; j<pat.length(); ++j) {
        if(pat[j] != txt[j]) {
            return false;
        }
    }
    return true;
}
vector <int> search(string pat, string txt)
{
    //code here.
    vector<int> ret;
    long ht = 0, hp = 0;
    int power = 1;
    int p = 31;
    int MOD = 1e9 + 7;
    int len = min(pat.length(), txt.length());

    for(int i=0; i<len; ++i) {
        hp = (hp + (pat[i] - 'a' + 1) * power) % MOD;
        power = power * p;
    }
    // txt = pat + txt;
    power = 1;
    vector<int> powers(len);
    for(int i=0; i<len; ++i) {
        powers[i] = power;
        ht = (ht + (txt[i] - 'a' + 1) * power) % MOD;
        power = power * p;
    }

    for(int i=pat.length(); i<=txt.length(); ++i) {
        cout << "i: " << i << " " << i - pat.length() + 2 << " " << ht << endl;
        if(hp == ht) {
            if(compare(pat, txt, i)) {
                ret.push_back(i - pat.length() + 1);
            }
        }
        if(i == txt.length()) break;

        // cout << ht << " " << txt[i - pat.length()] << " ";
        // exclude first char
        // ht -= (txt[i - pat.length()] - 'a' + 1);

        ////
        // ht = (ht - (txt[i - pat.length()] - 'a' + 1) + MOD) % MOD; // pinv;
        // // cout << ht << " " ;
        // ht /= power;
        // ht += (txt[i] - 'a' + 1) * powers[len-1];
        // ht %= MOD;
        /////
        // cout << txt[i] << " ";
        ht = ((ht - (txt[i - pat.length()] - 'a' + 1) * p + MOD) % MOD) % MOD;
        // include ith char
        // cout << ht << " ";
        ht = (ht + ((txt[i] - 'a' + 1) * p) % MOD) % MOD;
        // cout << ht << endl;
    }
    // vector<int> temp;
    // for(int i=1; i<ret.size(); ++i) {
    //     temp.push_back(ret[i] - 1);
    // }
    return ret;
}

int main() {
    string s, t;
    cin >> s>> t;

    vector<int> ret = search(t, s);
    for(auto x: ret) cout << x << ' ';
    cout << endl;
}
