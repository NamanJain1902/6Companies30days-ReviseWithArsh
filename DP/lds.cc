#include<bits/stdc++.h>
using namespace std;

int main(){

int n;
cin >> n;
vector<int> v(n);
for(auto &x: v)cin>>x;

vector<int> lds(n, 1);
int cnt=0;
int omax = 0;
for(int i=n-1; i>=0; --i){

    for(int j=n-1; j>i; --j){  
        if(v[i] > v[j]){
            if(lds[i] > lds[j]){
                lds[i] = lds[j];
            }
        }
        //cnt+=1;
    }
//    else{cnt=0;}
lds[i] += 1;
omax = max(omax, lds[i]);
}


cout << omax << endl;
//for(auto x: dp)cout << x << ' ';
//puts("");

return 0;
}
