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

struct edge
{
    edge(){}
    edge(int _x,int _y,int _z,int _w):id(_x),to(_y),c(_z),t(_w){}
    int id,to,c,t;
};

typedef pair<ll,int> P;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,M;
    vector<vector<edge>> E;
    vector<ll> d;
    vector<edge> es;

    cin >> N >> M;

    E.resize(N+1);
    d.resize(2*M);
    es.resize(2*M);

    rep(i,M)
    {
        int a,b,c,t;
        cin >> a >> b >> c >> t;

        E[a].pb(edge(i,b,c,t));
        E[b].pb(edge(M+i,a,c,t));

        es[i] = E[a].back();
        es[M+i] = E[b].back();

        d[i] = d[M+i] = 1ll<<60;
    }

    priority_queue<P,vector<P>,greater<P>> pq;

    ll mn = 1ll<<60;

    for(auto x:E[1])
    {
        d[x.id] = x.t + x.c - 1;
        if ( es[x.id].to == N ) mn = min(mn,d[x.id]);
        pq.push(mp(d[x.id],x.id));
    }


    while(!pq.empty())
    {
        P p = pq.top();pq.pop();

        if ( p.first > d[p.second] ) continue;

        rep(i,E[es[p.second].to].size())
        {
            edge e = E[es[p.second].to][i];

            if ( d[e.id] > d[p.second] + e.t + abs(es[p.second].c - e.c) ){
                d[e.id] = d[p.second] + e.t + abs(es[p.second].c - e.c);
                if (e.to == N) mn = min (mn,d[e.id]);
                pq.push(mp(d[e.id],e.id));
            }
        }
    }

    cout << mn << endl;
}
