/*
Given a range [L, R], the task is to find the count of numbers 
from this range that satisfy the below conditions: 
 

1. All the digit in the number are distinct.
2. All the digits are less than or equal to 5.
*/

#include <bits/stdc++.h>
using namespace std;
 
// Maximum possible valid number
#define MAX 543210
 
// To store all the required number
// from the range [1, MAX]
vector<string> ans;
 
bool isValidNumber(string x) {
    unordered_map<int, int> m;

    for(int i=0;i <x.length(); ++i) {
        // if digit present in map
        if(m.find(x[i] - '0') != m.end()) {
            return false;
        }

        // if current digit is greater than 5
        else if(x[i]-'0' > 5){
            return false;
        } else {
            // put the digit in the map
            m[x[i] - '0'] = 1;
        }
    }
    return true;
}

void generate()
{
    queue<string> q;
    q.push("1");
    q.push("2");
    q.push("3");
    q.push("4");
    q.push("5");
    
    bool flag=true;

    ans.push_back("0");

    while(!q.empty()) {
        string x = q.front();
        q.pop();

        // if x satisfies the given conditions
        if(isValidNumber(x)) {
            ans.push_back(x);
        }

        // cannot append anymore digit as adding a digit will repeat
        // one of the already present digits
        if(x.length() == 6) {
            continue;
        }

        // append all the valid digits one by one and push the new
        // generated numbers to the queue.
        for(int i=0; i<=5; ++i) {
            string z = to_string(i);

            string temp = x + z;

            // push the newly generated number to the queue
            q.push(temp);
        }
    }
}

bool comp(string a, string b) {
    if(a.size() == b.size()) {
        return a < b;
    } else {
        return a.size() < b.size();
    }
}

int find_count_linear(string l, string r) {
    // generate all the valid numbers
    // in the range [1, MAX]
    generate();

    // to store the count of numbers in 
    // the range of [l, r]
    int cnt = 0;

    // for every valid number in the 
    // range of [1, MAX]
    for(int i=0; i<ans.size(); ++i) {
        string a = ans[i];
        // if the current number is within
        // the required range.
        if(comp(l, a) and comp(a, r)) {
            cnt++;
        } else if(a == l or a == r) {
            cnt++;
        }
    }
    return cnt;
}

int find_count_binary_search(string l, string r) {
    int lidx, ridx;
    lidx = ridx = 0;
    int low = 0;
    int high = ans.size() - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(stoi(ans[mid]) == stoi(l)) {
            lidx = mid;
            break;
        } 
        if(stoi(ans[mid]) < stoi(l)){
            low = mid + 1;
        } else {
            lidx = mid;
            high = mid - 1;
        }
    }
    low = 0;
    high = ans.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(stoi(ans[mid]) == stoi(r)) {
            ridx = mid;
            break;
        } 
        if(stoi(ans[mid]) < stoi(r)){
            ridx = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ridx - lidx + 1;
}

int main() {
    generate();
 
    string l = "1", r = "1000";

    cout << find_count_binary_search(l, r) << endl;
}
