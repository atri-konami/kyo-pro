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

vector<string> ss;
int d[50][50];
int r,c;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

inline bool in(int y,int x) {
    return 0 <= y && y < r && 0 <= x && x < c;
}

int bfs(pii p)
{
    queue<pii> q;

    rep(i,4) {
        int ddx=x+dx[i],ddy=y+dy[i];
        if ( in ( ddy,ddx ) && ss[y][x] != '#' && d[ddy][ddx] == -1 ) {
            q.push(mp(ddy,ddx));
        }
    }

    if ( q.empty() ) return 1;



}

class BoardEscapeDiv2
{
public:

    string findWinner(vector <string> s, int k)
    {
        int dep;
        pii p;
        memset(d,-1,sizeof(d));
        r = s.size(),c = s[0].size();
        ss = s;

        rep(i,s.size()) rep(j,s[i].size()) {
            if ( s[i][j] == 'T' ) p = mp(i,j);
        }

        if ( (dep=bfs(p)) == -2 ) { return "Bob"; }
        else if ( dep == -1 ) {
            return (k&1 ? "Alice" : "Bob");
        }
        else {
            if ( dep == 1 ) return "Alice";
            else if ( dep == 2 ) return "Bob";
            else return (k&1 ? "Alice" : "Bob");
        }
    }
};
