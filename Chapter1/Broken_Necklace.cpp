/*
ID: true.xe1
TASK: beads
LANG: C++                 
*/

#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

#define TASK_NAME "beads"

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n;
    string b;
    cin >> n >> b;
    b+=b;
    int maxb = 0;
    int cnt = 0;
    char last = 'x';
    int diffc = -1;
    int wc = 0;
    /* idek why these edge cases kept messing up answers?????? usaco official solution is o(n^2) meanwhile mine is o(n) with no dp???*/
    if(b[0]=='w') diffc=0;
    if(b.substr(0,2)=="bw" ||b.substr(0,2)=="rw"){
        diffc=0;
    }
    /*       */
    for(int i=0; i<sza(b); i++){
        if(b[i]!=last && b[i]!='w'){
            //dbg(diffc, b[i]);
            diffc++;
            last = b[i];
            if(diffc > 1){
                diffc = 0;
                maxb = max(cnt, maxb);
                //dbg(wc);
                cnt = wc;
                //wc=0;
            }
        }
        if(b[i]=='w')wc++;
        else wc = 0;
        cnt++;
        //dbg(cnt, b[i]);
    }
    cout << max(maxb, cnt/2) << endl;
    //dbg(maxb, cnt);
}

int main() {
    ios_base::sync_with_stdio(0);
    auto USACO_FILE = [&](int t){
        return t==1 ? (TASK_NAME ".out") : (TASK_NAME ".in");
    };
    cin.tie(0); cout.tie(0);
    // if (fopen("ride.in", "r")) {
	// 	freopen("ride.in", "r", stdin);
	// 	freopen("ride.out", "w", stdout);
	// }
    // ofstream fout ("test.out");
    // ifstream fin ("test.in");

    if (fopen(USACO_FILE(0), "r")) {
		freopen(USACO_FILE(0), "r", stdin);
		freopen(USACO_FILE(1), "w", stdout);
	}
    ofstream fout (USACO_FILE(1));
    ifstream fin (USACO_FILE(0));
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}