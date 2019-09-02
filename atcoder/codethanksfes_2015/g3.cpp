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


struct vertex{
    vertex(){}
    vertex(int _n,int _c,ll _t):n(_n),c(_c),t(_t){}

    int n,c;
    ll t;

    bool operator>(const vertex& v) const{ return t > v.t; }
    bool operator<(const vertex& v) const{ return t < v.t; }
};

struct edge{
    edge(){}
    edge(int _to,int _c,int _t):to(_to),c(_c),t(_t){}
    int to,c,t;
};

typedef pair<ll,vertex> P;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    vector<edge> E[40001];
    unordered_map<int,ll> d[40001];

    rep(i,M)
    {
        int a,b,c,t;
        cin >> a >> b >> c >> t;

        E[a].pb(edge(b,c,t));
        E[b].pb(edge(a,c,t));

        d[a][c] = d[b][c] = 1ll<<60;
    }

    d[1][1] = 0;

    priority_queue<vertex,vector<vertex>,greater<vertex>> que;

    que.push(vertex(1,1,0));

    ll mn = 1ll<<60;

    while(!que.empty())
    {
        vertex p = que.top();que.pop();

        ll cost = p.t;
        int pos = p.n, col = p.c;

        if( cost > d[pos][col] ) continue;
        if( pos == N ) { mn = d[pos][col]; break; }

        rep(i,E[pos].size())
        {
            edge e = E[pos][i];

            auto it = d[e.to].find(e.c);

            if ( it == d[e.to].end() || d[e.to][e.c] > d[pos][col] + e.t + abs(e.c - col) ){
                d[e.to][e.c] = d[pos][col] + e.t + abs(e.c-col);
                if ( e.to == N ) mn = min(mn,d[e.to][e.c]);
                que.push(vertex(e.to,e.c,d[e.to][e.c]));
            }
        }
    }

    cout << mn << endl;
}
