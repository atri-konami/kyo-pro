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

class RelationClassifier
{
public:

    string isBijection(vector <int> domain, vector <int> range)
    {

        unordered_map<int,int> dom,ran;

        for(int i=0; i<domain.size(); i++){
            auto it1 = dom.find(domain[i]);
            auto it2 = ran.find(range[i]);

            if ( it1 == dom.end() && it2 == ran.end() ) {
                dom[domain[i]] = range[i];
                ran[range[i]] = domain[i];
            } else {
                if ( it1 != dom.end() && it2 != ran.end() ){
                    if ( it1->first != it2->second ) return "Not";
                } else {
                    return "Not";
                }
            } 
        }

        return "Bijection";
    }
};
