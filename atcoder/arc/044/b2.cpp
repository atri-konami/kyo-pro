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

const ll M = 1000000007;

ll pow2[64];
array<ll,100001> d;

ll pow2func(ll k)
{
    ll res = 1;
    for(int i=0; k>0; i++,k>>=1)
    {
        if ( k&1 )
            res = res * pow2[i] % M;
    }

    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    pow2[0]=2;
    REP(i,1,64)
    {
        pow2[i] = pow2[i-1] * pow2[i-1] % M;
    }

    fill(all(d),0);

    int N;
    cin >> N;


    int a;
    cin >> a;

    if ( a != 0 ){
        cout << 0 << endl;
        return 0;
    }

    d[a]++;

    int mxa = 0;


    rep(i,N-1)
    {
        cin >> a;
        d[a]++;
        mxa = max(mxa,a);
    }

    d[mxa+1] = INT_MAX;

    if ( d[0] != 1 )
    {
        cout << 0 << endl;
        return 0;
    }

    ll res =1;

    for(int i=0; i<=mxa; i++)
    {
        if ( i>0 && d[i] == 0) {
            res = 0;
            break;
        }

        ll c = d[i] * (d[i]-1) / 2;

        res = res * pow2func(c) % M;

        if ( i == mxa ) break;

        ll lc = d[i], cc = d[i+1];

        ll tmp = (pow2func(lc) - 1) % M;

        rep(j,cc) res = res * tmp % M;
    }

    cout << res << endl;
}
