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

multiset<int> nenshu,kibou;
int N,M;
int A[150000],B[150000],C[150000],D[150000];

void solve()
{
    cin >> N >> M;

    rep(i,N) {
        int a,b;
        cin >> a >> b;
        nenshu.insert(a);B[i] = b;
    }

    rep(i,M) {
        int c,d;
        cin >> c >> d;
        kibou.insert(d);C[i] = c;
    }

    int res = 0;

    for(auto it1=kibou.begin(); it1 != kibou.end(); it1++) {
        auto it = nenshu.lower_bound(*it1);

        if ( it != nenshu.end() ) {
            res ++;
            nenshu.erase(it);
        }
    }

    cout << res << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
