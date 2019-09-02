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

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v) {
    os << "[";
    for(int i=0; i<v.size(); i++) os << v[i] << ",";
    os << "]";
    return os;
}

template<class T1,class T2>
ostream& operator<<(ostream& os, const pair<T1,T2>& p) {
        os << "(" << p.first << "," << p.second << ")"; return os;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int w[5],m[5],hs,hu;
    const int p[] = {500,1000,1500,2000,2500};

    rep(i,5) cin >> m[i];
    rep(i,5) cin >> w[i];
    cin >> hs >> hu;

    int res = 100*hs - 50*hu;

    rep(i,5){
        res += max(3*p[i]/10,(250-m[i])*p[i]/250-50*w[i]);
    }

    cout << res << endl;
}
