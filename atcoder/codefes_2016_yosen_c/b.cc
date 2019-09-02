/* vim:set foldmethod=marker: */
#include <bits/stdc++.h>
using namespace std;

//{{{
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
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


int minoverzero(vector<int>& v) {
    int a=10000000;
    int res = -1;
    for(int i=0; i < v.size(); i++){
        if (v[i] > 0 && v[i] < a){
            a = v[i];
            res = i;
        }
    }
    return res;
}

int maxleft(vector<int>& v) {
    int a = -1;
    int res = -1;
    for(int i = v.size()-1; i >= 0; i--) {
        if (a < v[i]) {
            a = v[i];
            res = i;
        }
    }

    return res;
}

void solve() {
    int K, T;
    cin >> K >> T;
    vector<int> a(T);
 
    rep(i, T) cin >> a[i];
 
    int mn = minoverzero(a);
    int mx = maxleft(a);
 
    while (mn != mx && mn != -1 && a[mx] > 0) {
        a[mn]--;
        a[mx]--;
        mn = minoverzero(a);
        mx = maxleft(a);
    }

    if (a[mx] > 0) {
        cout << a[mx] - 1 << endl;
    } else {
        cout << 0 << endl;
    }
}
 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(12);
    solve();
}
