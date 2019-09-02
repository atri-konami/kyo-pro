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

int K,N;
string v[60],w[60];
int len[10];
string s[10];

bool solve()
{
    rep(i,N)
    {
        int l = 0;
        rep(j,v[i].size()) l += len[v[i][j]-'1'];
        if ( w[i].size() != l ) return false;
    }

    rep(i,N)
    {
        int idx=0;
        rep(j,v[i].size())
        {
            int n = v[i][j]-'1';
            s[n] = w[i].substr(idx,len[n]);
            idx+=len[n];
        }
    }

    rep(i,N)
    {
        string t;
        rep(j,v[i].size())
        {
            t += s[v[i][j]-'1'];
        }

        if ( w[i] != t ) return false;
    }

    return true;
}

bool dfs(int k)
{
    if ( k == K )
    {
        return solve();
    }

    bool ok = false;

    for(len[k]=1; len[k]<=3; len[k]++){
        ok = ok || dfs(k+1);
    }

    return ok;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> K >> N;

    rep(i,N){
        cin >> v[i] >> w[i];
    }

    if ( dfs(0) ){
        rep(i,K) cout << s[i] << endl;
    }
}
