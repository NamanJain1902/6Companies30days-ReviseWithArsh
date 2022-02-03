#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
// #define NDEBUG
#include<cassert>
using namespace std;


template <class T>
void print(vector<T> &v){
    for(T x: v)cout<<x<<' ';
    cout << "\n";
}

template <class T>
void print(vector<vector<T>> &v){
    for(auto u: v){
        for(auto x: u){
            cout<<x<<' ';
        }
        cout << "\n";
    }
}

/**
 * @brief polynomial rolling hash function.
 * @link https://cp-algorithms.com/string/string-hashing.html
 * @param s 
 * @return long long 
 */
long long compute_hash(string const& s){
    /*
        It is reasonable to make  a prime number roughly equal to the 
        number of characters in the input alphabet. For example, if 
        the input is composed of only lowercase letters of the English 
        alphabet, is a good choice. If the input may contain both 
        uppercase and lowercase letters, then  is a possible choice.
    */
    const int p = 31;
    const int mod = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;

    for(char c: s) {
        hash_value = (hash_value  + (c - 'a' + 1) * p_pow) % mod;
        p_pow = (p_pow * p);
    }

    return hash_value;
}

// search for duplicate strings in the array of strings
vector<vector<int>> group_identical_strings(vector<string> const& s) {

    /**
     * 1. Calculate hash value for each string
     * 2. Sort them
     * 3. Group indices having equal hash value.
     */
    int n = s.size();
    vector<pair<long long, int>> hashes(n);

    for(int i=0; i<n; ++i){
        hashes[i] = {compute_hash(s[i]), i};
    }

    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;

    for(int i=0; i<n; ++i) {
        if(i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();

        groups.back().push_back(hashes[i].second);
    }
    return groups;
}

vector<int> findPattern_RabinKarp(string &T, string &P)
{
    int nt = T.length();
    int np = P.length();

    assert(np <= nt && "Pattern Length Exceeds Text Length");

    vector<int> start_indices;

    int phash = compute_hash(P);

    for(;;) {

    }

}

vector<int> findPattern__simpleHash(string &T, string &P)
{
    /**
     * @brief h(ch) = ch - 'a' + 1
     *  a -> 1
     *  b -> 2
     *  .   .
     *  .   .
     *  .   .
     *  z -> 26
     */
    int nt = T.length();
    int np = P.length();

    assert(np <= nt && "Pattern Length Exceeds Text Length");

    vector<int> start_indices;

    auto hash = [&](char ch){
        return ch - 'a' + 1;
    };

    // finding pattern hashValue
    int pval = 0;
    int tval = 0;
    for(int i=0; i<np; ++i)
    {
        pval += hash(P[i]);
        tval += hash(T[i]);
    }

    // finding match in text with hash value by traversind in sliding fashion
    for(int i=np; i<nt; ++i) 
    {
        if(tval == pval) {
            bool found = true;
            for(int j=0; j<np; j++){
                if(T[i+j] != P[j]) {
                    found = false;
                    break;
                } 
            } 
            if(found) start_indices.push_back(i);
        }
        
        tval += hash(P[i]) - hash(T[i-np]);
    }
    return start_indices;
}

// returns list of indexes from T where P starts
vector<int> findPattern__slidingWindow(string T, string P) {

    int nt = T.length();
    int np = P.length();

    assert(np <= nt && "Pattern Length Exceeds Text Length");

    vector<int> start_indices;

    // sliding window O((nt - np + 1) * (nt - np)) 
    // since np << nt in most of the cases --=> O(nt^2)
    for(int i=0; i<=(nt-np); ++i) {
        bool found = true;
        for(int j=0; j<np; j++){
            if(T[i+j] != P[j]) {
                found = false;
                break;
            } 
        }
        if(found) start_indices.push_back(i);
    }

    return start_indices;
}



int main()
{
    // string T, P;
    // cin >> T >> P;

    // vector<int> res = findPattern__slidingWindow(T, P);
    // vector<int> res = findPattern__simpleHash(T, P);
    // print<int>(res);
    int n; cin >> n;
    vector<string> s(n);
    for(auto &x: s)cin>>x;
    vector<vector<int>> ret = group_identical_strings(s);
    print<int>(ret);
    return 0;
}