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

class FarmvilleDiv2
{
public:

    int minTime(vector <int> time, vector <int> cost, int budget)
    {
        int n = time.size();
        int res = 0;

        priority_queue<pii,vector<pii>,greater<pii>> pq;

        for(int i=0;i<n;i++)
        {
            pq.push(mp(cost[i],time[i]));
        }

        while(!pq.empty())
        {
            int c,t;
            tie(c,t) = pq.top();pq.pop();

            while(t>0 && budget>0)
            {
                if ( budget >= c )
                {
                    budget -= c;
                    t--;
                }
                else break;
            }

            res += t;
        }

        return res;
    }
};
