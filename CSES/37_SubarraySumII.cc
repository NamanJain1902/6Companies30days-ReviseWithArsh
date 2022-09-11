#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * @author Qi Wang
 * (detemplifying courtesy to Kevin Sheng)
 * 
 * submitted to compare result.
 */
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, X;
	cin >> N >> X;
	vector<int> T(N);
	for (int i = 0; i < N; i++) {
		cin >> T[i];
	}

	long long prefix_sum = 0;
	long long ans = 0;
	map<long long, int> sums;
	sums[0] = 1;
	for (int x : T) {
		prefix_sum += x;
		/*
		 * If there is a subarray with a prefix sum of prefix_sum - X,
		 * we can exclude it from our current subarray to get the desired sum.
		 * Thus, we can add the number of those subarrays to our answer.
		 */
		ans += sums[prefix_sum - X];
		// Increment the amount of prefix sums with a sum of prefix_sum
		sums[prefix_sum]++;
	}
	cout << ans << endl;
}
// #include<bits/stdc++.h>
// using namespace std;


// int main() {
//     int n, m;
//     cin >> n >> m;
//     // int arr[n];
//     int cnt = 0;
//     map<int, int> mp;
//     int prev = 0;
//     for(int i=0; i<n; ++i){
//         int x;
//         cin >> x;
//         prev += x;
//         mp[prev]++;
//     }
//     for(auto x: mp) {
//         if(x.first - m == 0){
//             cnt += x.second;
//         } else
//         cnt += mp[x.first - m];
//     }

//     cout << cnt << endl;

// }



// // int MXC(vector<int> Arr, int n,int k)
// // {
// //     int index = 0;
// //     for (int i = 31; i >= 0; i--) {
// //         int maxInd = index;
// //         int maxEle = INT_MIN;
// //         for (int j = index; j < n; j++) {
// //             if ( (Arr[j] & (1 << i)) != 0 && Arr[j] > maxEle )
// //                 maxEle = Arr[j], maxInd = j;
// //         }
 
// //         if (maxEle == INT_MIN)
// //         continue;

// //         swap(Arr[index], Arr[maxInd]);
// //         maxInd = index;

// //         for (int j=0; j<n; j++) {
// //             if (j != maxInd && (Arr[j] & (1 << i)) != 0)
// //                 Arr[j] = Arr[j] ^ Arr[maxInd];
// //         }
// //         index++;
// //     }
// //     for (int i = 0; i < n; i++)
// //         res ^= Arr[i];
    
// //     cal(0,0);  
// //     return 0;
    
// // }