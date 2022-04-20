#include<bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int, vector<int>> pq;

    pq.push(20);
    pq.push(10);
    pq.push(50);
    pq.push(25);

    cout << pq.top() << endl;
    pq.pop();

    cout << pq.top() << endl;
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> pqm;
    pqm.push(20);
    pqm.push(22);
    pqm.push(5);

    cout << pqm.top() << endl;
    pqm.pop();
    cout << pqm.top() << endl;
    puts("");
}
