/*
TASK: gift1
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
    int np;
    vector<string> names;
    unordered_map<string, int> balances;
    cin >> np;
    for(int i=0; i<np; i++){
        string name;
        cin >> name;
        balances.insert(balances.end(), {name, 0});
        names.push_back(name);
        //balances.insert({name, 0});
    }
    for(int j=0; j<np; j++){
        string giver;
        cin >> giver;
        int amount;
        int receivingNo;
        cin >> amount >> receivingNo;
        if(receivingNo > 0){ // FIXED LOGIC ERROR - DIVISION BY 0 IS UNDEFINED hence program kept borking
            balances[giver] += (amount % receivingNo) - amount;
            for(int k=0; k<receivingNo; k++){
                string receiver;
                cin >> receiver;
                balances[receiver] += amount/receivingNo;
            }
        }
    }
    for(auto name : names){
        cout << name << " " << balances[name] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("gift1.in", "r")) {
		freopen("gift1.in", "r", stdin);
		freopen("gift1.out", "w", stdout);
	}
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}