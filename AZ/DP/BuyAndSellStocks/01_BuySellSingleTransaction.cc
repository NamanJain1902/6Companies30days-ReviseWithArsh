#include <iostream>
#include <vector>

using namespace std;

void Transaction(vector<int> arr){
    //write your code here
    int buying_day = 0;
    int selling_day = 0;
    int max_profit = 0;
    int total_days = arr.size();

    for(int i=1; i<total_days; ++i) {
        // considering each day as potential
        // selling day for the last lowest buying day
        selling_day = i;
        if(arr[selling_day] - arr[buying_day] > 0) {
            max_profit = max(max_profit, arr[selling_day] - arr[buying_day]);
        } else {
            buying_day = selling_day;
        } 
    }

    cout << max_profit << "\n";
}

int  main() {
    int n;
    cin>>n;
    vector<int>arr(n, 0);
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
    Transaction(arr);
    return 0;  
}
