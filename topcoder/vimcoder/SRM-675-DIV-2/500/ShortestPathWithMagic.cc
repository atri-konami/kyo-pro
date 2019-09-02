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

class ShortestPathWithMagic
{
public:

    double res = 1e6;
    size_t sz;
    int max_k;
    double d[50][50];

    void dfs(int n,int dk,double cost,unordered_set<int> s)
    {
        if ( n == 1 ) {
            res = min ( res, cost );
            return;
        }

        rep(i,sz){
            if ( i == n ) continue;
            if ( s.find(i) != s.end() ) continue;

            s.insert(i);
            dfs(i,dk,cost+d[n][i],s);

            if ( dk < max_k ) {
                dfs ( i,dk+1,cost+d[n][i]/2,s);
            }
            s.erase(i);
        }
    }

    double getTime(vector <string> dist, int k)
    {
        sz = dist.size();
        max_k = k;
        rep(i,dist.size()){
            string s = dist[i];
            rep(j,s.size()){
                d[i][j] = dist[i][j] - '0';
            }
        }

        unordered_set<int> s;s.insert(0);

        dfs(0,0,0,s);

        return res;
    }
};
