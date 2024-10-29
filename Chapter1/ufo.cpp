/*
PROG: ride
LANG: C++                 
*/

// PASS

#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    string group;
    string comet;
    int comet_val=1;
    int group_val=1;
    cin >> group >> comet;
    for(int i=0; i<group.length(); i++){
        group_val *= (group[i] - 'A' + 1);
    }
    for(int j=0; j<comet.length(); j++){
        comet_val *= (comet[j] - 'A' + 1);
    }
    if(group_val%47 == comet_val%47){
        cout << "GO\n";
    } else {
        cout << "STAY\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("ride.in", "r")) {
		freopen("ride.in", "r", stdin);
		freopen("ride.out", "w", stdout);
	}
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}