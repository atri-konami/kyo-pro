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

    int N;
    cin >> N;

    vector<int> v(N);
    for(auto& x:v) cin >> x;


    int maxs=INT_MIN;

    rep(i,N){
        int from,to,s,t;
        int tmps,maxt=INT_MIN;

        rep(j,N){
            if ( i == j ) continue;

            from=i,to=j,s=0,t=0;

            if( from > to ) swap(from,to);

            REP(k,from,to+1){
                if((k-from)&1){
                    t+=v[k];
                }else{
                    s+=v[k];
                }
            }

            if( t > maxt ){
                maxt = t;
                tmps = s;
            }
        }

        if (tmps > maxs){
            maxs = tmps;
        }
    }

    cout << maxs << endl;
}
