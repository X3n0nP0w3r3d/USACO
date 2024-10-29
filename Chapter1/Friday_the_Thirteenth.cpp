/*
TASK: friday
LANG: C++                 
*/

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
    int START_YEAR = 1900;
    int daycount = 13;
    int monthcount = 1;
    int n; // number of years after Jan 1st 1900 (MONDAY)
    cin >> n;
    // EVERY YEAR EVENLY DIVISIBLE BY 4 IS A LEAP YEAR EXCEPT CENTURY YEARS(1700,1800,1900)
    // CENTURY YEARS DIVISBLE EVENLY BY 400 ARE LEAP YEARS (2000, 2400)
    // n will not exceed 400
    // OUTPUT IS THE AMOUNT OF TIMES 13th LANDS ON A SPECIFIC DAY
    // FORMAT: SATURDAY, SUNDAY, MONDAY, TUESDAY...
    vector<int> days(7, 0);
    for(int i=START_YEAR; i<START_YEAR+n; i++){
        for(int month = 1; month<=12; month++){
            days[daycount%7]++;
            switch(month){
                case 2:
                    daycount += 28 + (i%4==0 && i%100 || i%400==0 && i%100==0 ? 1 : 0);
                    break;
                case 6:
                case 9:
                case 4:
                case 11:
                    daycount+= 30;
                    break;
                default:
                    daycount+= 31;
            }
        }
    };
    cout << days[6] << " ";
    for(int i=0; i<6; i++){
        cout << days[i] << (i!=5 ? " " : "");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("friday.in", "r")) {
		freopen("friday.in", "r", stdin);
		freopen("friday.out", "w", stdout);
	}
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";

        solve();
    }
    return 0;
}