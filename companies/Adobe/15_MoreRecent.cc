/*
  Given two library versions of an executable: for example, 
  “10.1.1.3” and “10.1.1.9” or “10” and “10.1”. Find out 
  which one is more recent? Strings can be empty also.
*/
#include<bits/stdc++.h>
using namespace std;

void versions(vector<string> &v1, string &s1){
    int prev=0;
    for(int i=0; i<s1.length(); ++i){
        if(s1[i] == '.'){
            v1.push_back(s1.substr(prev, i-prev));
            prev = i+1;
        } else if(i == s1.length() - 1){
            v1.push_back(s1.substr(prev, i-prev+1));
        }
    }
}
void print(vector<string> &v){
    for(auto s: v)cout << s << ' ';
    cout << endl;
}
int main(int argc, char *argv[]){
    string s1, s2;cin>>s1>>s2;
    vector<string> v1, v2;
    
    versions(v1, s1);
    versions(v2, s2);   

//    print(v1);
//    print(v2);

    int n1=v1.size(), n2=v2.size();
    if(n1 == n2){
        int val1 = stoi(v1[n1-1]);
        int val2 = stoi(v2[n2-1]);
        
        if(val1 > val2) cout << s1 << endl;
        else cout << s2 << endl;
    } else if(n1 > n2){

        bool found = false;
        for(int i=0; i<n2; ++i){
            if(stoi(v1[i]) > stoi(v2[i])){
                cout << s1 << endl;
                found = true;
                break;
            } else if(stoi(v1[i]) < stoi(v2[i])){
                cout << s2 << endl;
                found = true;
                break;
            }
        }
        if(!found)
        cout << s1 << endl;
    } else {
        bool found = false;
        for(int i=0; i<n1; ++i){
            if(stoi(v1[i]) > stoi(v2[i])){
                cout << s1 << endl;
                found = true;
                break;
            } else if(stoi(v1[i]) < stoi(v2[i])){
                cout << s2 << endl;
                found = true;
                break;
            }
        }
        if(!found)
        cout << s2 << endl;
    }

    return 0;
}
