#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define REP(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define RREP(i,a,b) for(int i=(int)(a); i>=b; i--)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) RREP(i,n,0)
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

#define dump(x) (cerr << #x << "=" << x << endl)
template<class T> ostream& osContainer(ostream& os,T c) { os<<'[';for(typename T::iterator it=c.begin();it!=c.end();it++)os<<*it<<',';os<<']';return os; }
template<class T> ostream& operator<<(ostream& os,const vector<T>& v) { return osContainer(os,v); }
template<class T> ostream& operator<<(ostream& os,const set<T>& s) { return osContainer(os,s); }
template<class T> ostream& operator<<(ostream& os,const multiset<T>& s) { return osContainer(os,s); }
template<class T,class S> ostream& operator<<(ostream& os,const map<T,S>& m) { return osContainer(os,m); }
template<class T,class S> ostream& operator<<(ostream& os,const multimap<T,S>& m) { return osContainer(os,m); }
template<class T1,class T2>
ostream& operator<<(ostream& os, const pair<T1,T2>& p){ os << '(' << p.first << ',' << p.second << ')'; return os; }

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int H, W;
const int mod = 1000000007;
inline bool in(int h, int w) {
    return 0 <= w && w < W && 0 <= h && h < H;
}

int field[1000][1000];
int ret[1000][1000];

int solve(int h, int w) {
    int now = field[h][w];
    int res = 1;
    rep(i, 4) {
        int ww = w + dx[i], hh = h + dy[i];
        if (in(hh, ww) && now < field[hh][ww]) {
            res += ret[hh][ww] < 0 ? solve(hh, ww) % mod : ret[hh][ww];
            res %= mod;
        }
    }
    return ret[h][w] = res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(12);

    memset(ret, -1, sizeof(ret));

    cin >> H >> W;

    rep(i,H) rep(j,W) {
        cin >> field[i][j];
    }

    rep(i,H) rep(j,W) {
        solve(i, j);
    }

    int res = 0;
    rep(i,H) rep(j,W) {
        res += ret[i][j];
        res %= mod;
    }

    cout << res << endl;
}
