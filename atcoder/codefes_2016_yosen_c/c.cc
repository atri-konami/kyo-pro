/* vim:set foldmethod=marker: */
#include <bits/stdc++.h>
using namespace std;

//{{{
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
template<class T> ostream& osContainer(ostream& os,T c) { os<<'[';for(decltype(c.begin()) it=c.begin();it!=c.end();it++)os<<*it<<',';os<<']';return os; }
template<class T> ostream& operator<<(ostream& os,const vector<T>& v) { return osContainer(os,v); }
template<class T> ostream& operator<<(ostream& os,const set<T>& s) { return osContainer(os,s); }
template<class T> ostream& operator<<(ostream& os,const multiset<T>& s) { return osContainer(os,s); }
template<class T,class S> ostream& operator<<(ostream& os,const map<T,S>& m) { return osContainer(os,m); }
template<class T,class S> ostream& operator<<(ostream& os,const multimap<T,S>& m) { return osContainer(os,m); }
template<class T1,class T2>
ostream& operator<<(ostream& os, const pair<T1,T2>& p){ os << '(' << p.first << ',' << p.second << ')'; return os; }

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
//}}}

vector<ll> T, A;
ll H[100001];
const int mod = 1e9+7;

void solve() {
    int N;
    ll conb=1;
    cin >> N;
    rep(i, N) {
        ll t; cin >> t;
        T.push_back(t);
    }

    rep(i, N) {
        ll t; cin >> t;
        A.push_back(t);
    }

    if (N == 1) {
        if (T[0] == A[0]) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return;
    }

    ll max_t = T[0], max_a = A[N-1];
    REP(i, 1, N) {
        int t = T[i];
        if (T[i] > max_t) {
            H[i] = T[i];
            max_t = T[i];
        } else {
            H[i] = (-1) * T[i];
        }
    }

    RREP(i, N-2, 1) {
        int a = A[i];
        if (A[i] > max_a) {
            if (H[i] < 0) {
                ll h = -H[i];
                if (A[i] > h) {
                    cout << 0 << endl;
                    return;
                }
            } else {
                if (A[i] != H[i]) {
                    cout << 0 << endl;
                    return;
                }
            }
            max_a = A[i];
        } else {
            if (H[i] < 0) {
                ll h = -H[i];
                H[i] = -min(h, max_a);
                conb = conb * (-H[i]) % mod;
            } else {
                if (H[i] > max_a) {
                    cout << 0 <<endl;
                    return;
                }
            }
        }
    }

    cout << conb << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(12);
    solve();
}
