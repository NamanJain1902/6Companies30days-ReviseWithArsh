#include<bits/stdc++.h>
using namespace std;


// let the person x solve given this soltion
int search1(string pat, string txt) {
  // code here
  int ans = 0;
  int K = pat.length();
  unordered_map<char, int> map;

    // store the pattern in map
  for (int i = 0; i < K; i++) {
    map[pat[i]]++;
  }

// check first K element and decrease from map
  for (int i = 0; i < K; i++) {
    map[txt[i]]--;
    if (map[txt[i]] == 0)
      map.erase(txt[i]);
  }
 // if map's empty pattern is found
  if (map.size() == 0)
    ans++;

// slide the window and remove element if its 0 and if map is empty we found a pattern
  for (int j = K; j < txt.length(); j++) {
    map[txt[j - K]]++;
    map[txt[j]]--;

    if (map[txt[j - K]] == 0)
      map.erase(txt[j - K]);

    if (map[txt[j]] == 0)
      map.erase(txt[j]);

    if (map.size() == 0)
      ans++;
  }

  return ans;
}


// My solution
int main(){
    string s1, s2;
    cin >> s1 >> s2; 

    unordered_map<char, int> hmap1, hmap2;

    int m=s1.length(),n=s2.length();

    for(int i=0; i<n; ++i){
        hmap2[s2[i]]++;
    }
    int i;
    for(i=0; i<n; ++i){
        hmap1[s1[i]]++;
    }

    if(hmap1 == hmap2){
        cout << 0 << endl;
    }
    for(i=n; i<m;  ++i){
        hmap1[s1[i-n]]--;
        if(hmap1[s1[i-n]] == 0){
            hmap1.erase(s1[i-n]);
        }
        hmap1[s1[i]]++;

        if(hmap1 == hmap2){
            cout << i - n + 1 << endl;
        }
    }
}