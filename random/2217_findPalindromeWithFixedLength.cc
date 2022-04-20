#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<ll> result;
        ll start = intLength % 2 == 0 ? pow(10, intLength/2 - 1) : pow(10, intLength/2);
        for(int q: queries) { 
            string s = to_string(start + q - 1);
            string palindrome = s;
            reverse(s.begin(), s.end());
            if(intLength % 2 == 0) {
                palindrome += s;
            } else {
                palindrome += s.substr(1, s.size() - 1);
            }
			
			// len of palindrome should be intLength, otherwise -1
            if (palindrome.size() == intLength)
                result.push_back(stoll(palindrome));
            else
                result.push_back(-1);
        }
        
        return result;
    }
};

class Solution1 {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        // range of possible numbers will be
        // long long start = (1 << (intLength - 1)) * 1LL;
        // long long end   = (1 << intLength) * 1LL - 1;
        long long start=1, end=1;
        int k = intLength - 1;
        while(k--){
            start = start * 10; 
        }
        k = intLength;
        while(k--){
            end = end * 10;
        }
        end -= 1;
        cout << start << " " << end << endl;
        bool oddL = intLength & 1;
        vector<long long> ret;
                           
        for(long long val = start; val <= end; val++){
            string num = to_string(val);
            string left, middle, right;
            for(int i=0; i<(int)(num.length() / 2); ++i) {
                left += num[i];
            }
            for(int i=left.length(); i>=0; --i) {
                right += left[i];
            }

            string ans;
            long long numeric;
            if(oddL) {
                for(int i=0; i<=9; ++i) {
                    middle = to_string(i);
                    ans = left + middle + right;
                    numeric = stoll(ans);
            cout << "Left: " << left << "\tmiddle: " << middle << "\tright: " << right << "\tans: "<<ans << "\tnumeric: "<< numeric<<endl;        
                    
                    ret.push_back(stoll(ans));
                }
                val += start;
                val--;
            } else {
                ans = left + right;
                
                numeric = stoll(ans);
            cout << "Left: " << left << "\tright: " << right << "\tans: "<<ans << "\tnumeric: "<< numeric<<endl;
                ret.push_back(numeric);

                val += stoi(left);
                val--;
            }
        }

        vector<long long> res;
        for(auto x: queries){
            if(x > res.size() or x < 0){
                res.push_back(-1 * 1LL);
            } else{
                res.push_back(ret[x]);
            }
        }                  
        return res;
    }
};

int main(){
    Solution1 sol;
    vector<int> queries = {1, 2, 3, 4, 5, 90};
    int intLength = 3;
    vector<long long> ret = sol.kthPalindrome(queries, intLength);
    for(auto x: ret)  {
        cout << x  << ' ';
    }
    puts("");
    return 0;
}