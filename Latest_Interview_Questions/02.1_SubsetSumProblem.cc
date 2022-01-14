#include<bits/stdc++.h>
using namespace std;


bool isSubset(vector<int> v, int n, int sm){

    if(sm == 0){
        return true;
    }
    if(n == 0){
        return false;
    }



    if(v[n-1] > sm){
        return isSubset(v, n-1, sm);
    }

    return isSubset(v, n-1, sm + v[n-1]) || isSubset(v, n-1, sm - v[n-1]);
}

int main()
{
    vector<int> v = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    if (isSubset(v, v.size(), sum) == true)
         cout <<"Found a subset with given sum" << endl;
    else
        cout <<"No subset with given sum" << endl;
    return 0;
}

