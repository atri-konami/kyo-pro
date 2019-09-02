#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define REP(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define RREP(i,a,b) for(int i=(int)(a); i>=b; i--)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) RREP(i,n,0)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

#define dump(x) (cerr << #x << "=" << x << endl)

template<class T>
ostream& operator<<(ostream& os,const vector<T> v) {
    os << "[";
    for(int i=0; i<v.size(); i++){
        os << v[i] << ",";
    } 
    os << "]";
    return os;
}

template<class T1,class T2>
ostream& operator<<(ostream& os, const pair<T1,T2> p) {
        os << "(" << p.first << "," << p.second << ")"; return os;
}


struct edge{
    edge(int a,int b,int d):to(a),c(b),t(d){}
    int to,c,t;
};

typedef pair<ll,ll> P;

int main(){
    //cin.tie(0);
    //ios::sync_with_stdio(false);

    int N,M;
    vector<vector<edge>> E;
    //cin >> N >> M;
    scanf("%d%d",&N,&M);

    map<ll,ll> d;
    E.resize(N+1);

    rep(i,M){
        int a,b,c,t;
        scanf("%d%d%d%d",&a,&b,&c,&t);
        //cin >> a >> b >> c >> t;
        E[a].pb(edge(b,c,t));
        E[b].pb(edge(a,c,t));
        d.emplace(((ll)a<<32)+c,LONG_LONG_MAX);
        d.emplace(((ll)b<<32)+c,LONG_LONG_MAX);
    }

    d[(1ll<<32) + 1] = 0;

    priority_queue<P,vector<P>,greater<P>> que;

    que.push(P(0,(1ll<<32)+1));

    ll mn = LONG_LONG_MAX;

    while(!que.empty())
    {
        P p = que.top();que.pop();

        ll cost = p.first;
        int pos = p.second>>32,
            col = p.second - ((ll)pos<<32);

        ll idx = (ll(pos)<<32) + col;

        if ( cost > d[idx] ) continue;

        for(int i=0;i<E[pos].size();i++)
        {
            edge e = E[pos][i];
            ll toidx = (ll(e.to)<<32) + e.c;

            //if ( (e.to != 1 || e.c != 1) && d[toidx] == 0 ) d[toidx] = LONG_LONG_MAX;

            if ( d[toidx] > d[idx] + e.t + abs(col-e.c) )
            {
                d[toidx] = d[idx] + e.t + abs(col-e.c);
                if(e.to == N) mn = min(mn,d[toidx]);
                que.push(P(d[toidx],toidx));
            }
        }
    }

/*
    for(int i=0; i<E[N].size(); i++)
    {
        int c = E[N][i].c;
        mn = min(mn,d[(ll(N)<<32) + c]);
    }
*/

    printf("%lld\n",mn);
    //cout << mn << endl;
}
