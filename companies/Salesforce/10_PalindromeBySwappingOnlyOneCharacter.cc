#include<bits/stdc++.h>
using namespace std;

bool equiPair(string &str, int p, int q, int r, int s){
    // p != q
    // r != s
    cout << str[p] << ' ' << str[q] << ' ' << str[r] << ' ' << str[s] << endl;
    if(str[q] == str[r]){
        cout << str[p] << ' ' << str[q] << ' ' << str[r] << ' ' << str[s] << endl;
        swap(str[p], str[r]);
        if(str[p] == str[q] && str[r] == str[s]){
            return true;
            cout << "yes" << endl;
        }
    }
    return false;
}

bool isPossible(string &s){
    int n = s.length();

    if(n%2 == 1){
        int mid = n/2;
        int low = mid - 1;
        int high = mid + 1;
        int p=-1, q=-1, r=-1, ss=-1;

        while(low>=0 and high < n){

            while(low >= 0 and high < n and  s[low] == s[high]) {
                low--;high++;
            }
            cout << "Low: " << low  << "\tHigh: " << high << endl;
            if(p!= -1 and r==-1 and ss==-1){
                r = low;
                ss = high;
            }
            if(p == -1 and q == -1){
                p = low;
                q = high;
            }

            cout << "p: " << s[p] << "\tq: " << s[q] << endl;
            
            cout << "r: " << s[r] << "\tss: " << s[ss] << endl;

            if(p != -1 and r != -1){
                cout << p << " " <<q << " "<< r  <<" "<< ss << endl;
                if(equiPair(s, p, q, r, ss)){
                    continue;
                } else{
                    return false;
                }

            }

            // if(s[mid] == s[p]){
            //     swap(s[mid], s[p]);
            // }
            // if(s[mid] == s[q]){
            //     swap(s[mid], s[q]);
            // }
            
            // if(s[p] == s[q]){
            //     continue;
            // } 
            // else{
            //     return false;
            // }
            cout << p << " " <<q << " "<< r  <<" "<< ss << endl;
            low--; high++;
        }
    } else {
        int high = n/2;
        int low = high - 1;
        int p=-1, q=-1, r=-1, ss=-1;

        while(low>=0 and high < n){

            while(low >= 0 and high < n and  s[low] == s[high]) {
                low--;high++;
            }

            if(p == -1 and q == -1){
                p = low;
                q = high;
            }
            if(p!= -1 and r==-1 and ss==-1){
                r = low;
                ss = high;
                continue;
            }

            if(p != -1 and r != -1){
                if(equiPair(s, p, q, r, ss)){
                    continue;
                } else{
                    return false;
                }
            }

            low--; high++;
        }
    }
    cout  << "here" << endl;
    return true;
}

int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        cout << (isPossible(s) ? "true" : "false") << endl;
    }
}
