/**
* @author NamanJain1902
* On: 20/07/2022 
* At: 06:37:18
*/

#pragma GCC optimize ("O3")
#pragma GCC target ("avx,avx2")

#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>
#include <numeric>
#include <climits>

#include <array>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
 
#include <cstring>
#include <ostream>
#include <type_traits>
#include <utility>
#include <chrono>
#include <random>
 
using namespace std;

#define pr pair<int, int>
#define pb push_back
#define s second
#define f first
#define ll long long
#define int long long int
#define sz(x) ((int)x.size())

const int MAX = 100000 + 5;
const int HMAX = 1000000007;

int binaryExponentiation(int base, int power, int moduloval){int ans = 1;while(power > 0){if(power % 2) ans = (ans * base) % moduloval;base = (base*base)%HMAX;power >>= 1;}return ans;}
void readarr(int *arr, int n){for(int i=0; i<n; ++i){cin >> arr[i];}}
int binpower(int base, int power){int ans = 1;while(power>0){if(power%2)  ans = ans * base;base *= base;power /= 2;}return ans;}


int si=0, sj=0, ei=0, ej=0;
int moves[]={-1, 0, 1, 0, -1};
string dirs = "URDL";
string path;
int n, m;
bool isValidMove(int i, int j) {
    if(i < 0 or i>=n or j < 0 or j >=m) return false;
    return true;
}
void dfs(vector<vector<int>> &visited, int x, int y, string p)
{
    if(x == ei and y == ej) {
        path = p;
        return;
    }

    for(int k = 0; k < 4; ++k){
        int dx = x + moves[k];
        int dy = y + moves[k+1];
        char dir = dirs[k];
        
        if(isValidMove(dx, dy) and !visited[dx][dy]) {
            visited[dx][dy] = true;
            dfs(visited, dx, dy, p + dir);
        }
    }
    // visited[x][y] = true;
    // dfs(v, x - 1, y, path + "U");
    // dfs(v, x, y + 1, path + "R");
    // dfs(v, x + 1, y, path + "D");
    // dfs(v, x, y - 1, path + "L");
}
struct Cell {
    int x;
    int y;
    string dir;

    Cell(int _x, int _y, string _dir) {
        this->x = _x;
        this->y = _y;
        this->dir = _dir;
    }
};
void bfs_GivingTLE_BecauseCopyingStringOnEachPushOPTakesMoreTime(vector<vector<int>> &visited) {
    queue<Cell> q;
    q.emplace(si, sj, "");
    bool ok = false;

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        string ans = q.front().dir;
        q.pop();

        if(x == ei and y == ej) {
            ok = true;
            cout << "YES\n";
            cout << ans.length() << endl;
            cout << ans << endl;
        }
        for(int k = 0; k < 4; ++k) {
            int dx = x + moves[k];
            int dy = y + moves[k+1];

            if(isValidMove(dx, dy) and !visited[dx][dy]) {
                visited[dx][dy] = true;
                q.emplace(dx, dy, ans + dirs[k]);
            }
        }
    }
    if(!ok) cout << "NO\n";
}

// Approach:
// creating a distance map, from current cell to destination cell.
// if a path exists from A to B then we can backtrack to build the path.
struct Point {
    int x;
    int y;
    int dist;

    Point(int _x, int _y, int _dist) {
        this->x = _x;
        this->y = _y;
        this->dist = _dist;
    }
};
vector<vector<int>> d;

void bfs(vector<vector<int>> &visited) {
    queue<Point> q;
    q.emplace(si, sj, 0);
    bool ok = false;

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int dist = q.front().dist;
        d[x][y] = dist;
        q.pop();

        if(x == ei and y == ej) {
            ok = true;
            cout << "YES\n";
            cout << dist << endl;
            string ans;
            while(dist != 0 and x != si and y != sj) {
                if(x > 0 and d[x-1][y] == dist - 1) { // up
                    ans += "D";
                    x--;
                } else if(y < m - 1 and d[x][y+1] == dist - 1) { // right
                    ans += "L";
                    y++;
                } else if(x < n - 1 and d[x+1][y] == dist - 1) { // down
                    ans += "U";
                    x++;
                } else if(y > 0 and d[x][y-1] == dist - 1) { // left
                    ans += "R";
                    y--;
                }
                dist--;
            }
            reverse(ans.begin(), ans.end());
            cout << ans << endl;
        }

        for(int k = 0; k < 4; ++k) {
            int dx = x + moves[k];
            int dy = y + moves[k+1];

            if(isValidMove(dx, dy) and !visited[dx][dy]) {
                visited[dx][dy] = true;
                q.emplace(dx, dy, dist + 1);
            }
        }
    }
    if(!ok) cout << "NO\n";
}
void solve(){
    cin >> n >> m;
    vector<vector<int>> visited(n, vector<int>(m));
    // vector<vector<char>> v(n, vector<char>(m));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            char ch;
            cin >> ch;
            if(ch == '#') visited[i][j] = 2;
            else{ 
                visited[i][j] = 0;
                if(ch == 'A'){
                    si = i; sj = j;
                } else if(ch == 'B') {
                    ei = i; ej = j;
                }
            }
        }
    }

    d.resize(n, vector<int>(m, -1)); // -1 => inf
    // dfs(visited, si, sj, "");
    bfs(visited);

    for(auto x: d){
        for(auto y: x){
            cout << y<< " ";
        }cout<<endl;
    }
    // if(path.size() > 0){
    //     cout << "YES" << endl;
    //     cout << path.length() << endl;
    //     cout << path << endl;
    // } else {
    //     cout << "NO";
    // }
    // cout << endl;
}

signed main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t=1;
//   int t;
//   cin >> t;
  for(int i=1; i<=t; ++i){
    solve();
  }
}




///////////////////////////

#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<pii> vii; 
typedef vector<pll> vll; 
typedef vector<ll> vl; 
typedef vector<vl> vvl; 

double EPS=1e-9; 
int INF=1000000005; 
ll INFF=1000000000000000005ll; 
double PI=acos(-1); 
int dirx[8]={ -1, 0, 0, 1, -1, -1, 1, 1 }; 
int diry[8]={ 0, 1, -1, 0, -1, 1, -1, 1 }; 
const ll MOD = 1000000007;

#define DEBUG fprintf(stderr, "====TESTING====\n") 
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl 
#define OUT(x) cout << x << endl 
#define debug(...) fprintf(stderr, __VA_ARGS__) 
#define READ(b) for(auto &(a):b) cin >> a;
#define FOR(a, b, c) for (int(a)=(b); (a) < (c); ++(a)) 
#define FORN(a, b, c) for (int(a)=(b); (a) <= (c); ++(a)) 
#define FORD(a, b, c) for (int(a)=(b); (a) >= (c); --(a)) 
#define FORSQ(a, b, c) for (int(a)=(b); (a) * (a) <= (c); ++(a)) 
#define FORC(a, b, c) for (char(a)=(b); (a) <= (c); ++(a)) 
#define EACH(a, b) for (auto&(a) : (b)) 
#define REP(i, n) FOR(i, 0, n) 
#define REPN(i, n) FORN(i, 1, n) 
#define MAX(a, b) a=max(a, b) 
#define MIN(a, b) a=min(a, b) 
#define SQR(x) ((ll)(x) * (x)) 
#define RESET(a, b) memset(a, b, sizeof(a)) 
#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back 
#define ALL(v) v.begin(), v.end() 
#define ALLA(arr, sz) arr, arr + sz 
#define SIZE(v) (int)v.size() 
#define SORT(v) sort(ALL(v)) 
#define REVERSE(v) reverse(ALL(v)) 
#define SORTA(arr, sz) sort(ALLA(arr, sz)) 
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz)) 
#define PERMUTE next_permutation 
#define TC(t) while (t--) 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

struct Point{
	int x, y, dist;
};

int main()  
{ 
    FAST_INP;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // #endif
    int n, m, sx, sy, dx, dy;
    cin >> n >> m;
    vector<vector<char>> g(n,vector<char>(m));
	vvi d(n,vi(m,-1));
	// bfs approach to find the shortest path
    REP(i,n) {
    	REP(j,m) {
    		cin >> g[i][j];
	    	if(g[i][j]=='A') sx=i, sy=j;
	    	if(g[i][j]=='B') dx=i, dy=j;
		}
	}
	g[sx][sy]='#';
	queue<Point> q;
	q.push({sx,sy,0});
	int row[4]={-1,0,0,1}, col[4]={0,-1,1,0};
	char dir[4]={'U','L','R','D'};
	function<bool(int,int)> ok = [&](int i, int j){
	  if(i<0||i>n-1||j<0||j>m-1||g[i][j]=='#') return false;
	  return true;
	};
	while(!q.empty()){
		Point p = q.front();
		q.pop();
		int xx = p.x, yy = p.y, dist=p.dist;
		d[xx][yy]=dist;
		if(xx==dx&&yy==dy){
			OUT("YES");
			OUT(dist);
			// backtracking to build the ans 
			// as copying string in each step is time consuming
			// and it would cause TLE for 999x999 maze
			string ans;
			while(xx != sx || yy != sy){
				if(xx>0 && d[xx-1][yy]==dist-1){
					ans.pb('D');
					xx--;
				} else if(xx<n-1 && d[xx+1][yy]==dist-1){
					ans.pb('U');
					xx++;
				} else if(yy>0 && d[xx][yy-1]==dist-1){
					ans.pb('R');
					yy--;
				} else {
					ans.pb('L');
					yy++;
				}
				dist--;
			}
			REVERSE(ans);
			OUT(ans);

            for(auto x: d){
                for(auto y: x){
                    cout << y<< " ";
                }cout<<endl;
            }
			return 0;
		}
		REP(i,4){
			int x=xx+row[i], y=yy+col[i];
			if(ok(x,y)){
				g[x][y]='#';
				q.push(Point{x,y,dist+1});
			} 
		}
	}
	OUT("NO");
    return 0; 
} 

