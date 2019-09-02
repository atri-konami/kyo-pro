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

int N,X;
ull res = 0;
ull x[100000];
map<ull,ull> m;
bool checked[100000];
vector<pii> E[100000];

void dfs(int n,ull c)
{
    checked[n] = true;

    rep(i,E[n].size()){
        pii p = E[n][i];
        int to = p.first,cost = p.second;

        if ( checked[to] ) continue;

        x[to] = c^(ull)cost;

        auto it = m.find((ull)X^x[to]);

        if ( it != m.end() )
        {
            res += it->second;
        }

        m[x[to]]++;

        dfs(to,x[to]);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    memset(x,0,sizeof(x));
    memset(checked,0,sizeof(checked));

    cin >> N >> X;

    rep(i,N-1){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;

        E[a].pb(mp(b,c));
        E[b].pb(mp(a,c));
    }

    m[0]++;
    dfs(0,0);

    cout << res << endl;
}
