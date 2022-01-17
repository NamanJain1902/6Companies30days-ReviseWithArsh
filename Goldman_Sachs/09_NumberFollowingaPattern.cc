#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n;
    n = s.length();


    stack<int> st;
    int k = 1;
    for(int i=0; i<n; ++i){
        if(s[i] == 'D'){
            st.push(k);
        } else{
            st.push(k);
            while(!st.empty()){
                cout << st.top() << " ";
                st.pop();
            }
        }
        k++;
        if(i == n-1){
            st.push(k);
        }
    }
    while(!st.empty()){

        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
