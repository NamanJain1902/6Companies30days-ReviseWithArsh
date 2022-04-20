#include<bits/stdc++.h>
using namespace std;

int using_maps(string s) {

}
int lengthOfLongestSubstring(string s) {
    vector<int> chars(128);

    int left  = 0;
    int right = 0;
    int res = 0;
    
    while (right < s.length()) {
        char r = s[right];
        chars[r]++;

        while (chars[r] > 1) {
            char l = s[left];
            chars[l]--;
            left++;
        }

        res = max(res, right - left + 1);

        right++;
    }

    return res;
}

// @lightmark solution: O(n) :)
int lengthOfLongestSubstring(string s) {

    vector<int> dict(256, -1);
    const int n      = s.length();
    int start  = -1;
    int maxlen = 0;
    for(int i=0; i<n; ++i) {
        if(dict[s[i]] > start) {
            start = dict[s[i]];
        } 
        dict[s[i]] = i;
        maxlen = max(maxlen, i - start);
    }
    return maxlen;
}
int brute(string s) {
    int ans = 0;
    int n = s.length();
    int i = 0;
    int j = 0;
    while(i < n) {
        set<char> st;
        int cnt = 0;
        bool breakit = false;
        for(j = i; j<n; ++j) {
            char ch = s[j];
            if(i != j) {
                if(st.count(ch) > 0) {
                    breakit = true;
                    // break;
                }
            }
            st.insert(ch);
            if(breakit) break;
            cnt++;
            ans = max(ans, cnt);
        }
        i++;
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;

    cout << brute(s) << endl;
    cout << lengthOfLongestSubstring(s) << endl;
}