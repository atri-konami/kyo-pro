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

const double fttoin = 12;
const double ydtoft = 3;
const double mitoyd = 1760;

class LengthUnitCalculator
{
public:

    double calc(int amount, string fromUnit, string toUnit)
    {
        double res = 0;

        if ( fromUnit == "ft" ) {
            if ( toUnit == "in" ) {
                res = amount * fttoin;
            } else if ( toUnit == "yd" ) {
                res = amount / ydtoft;
            } else if ( toUnit == "mi" ) {
                res = amount / ydtoft / mitoyd;
            } else {
                res = amount;
            }
        } else if ( fromUnit == "in" ) {
            if ( toUnit == "in" ) {
                res = amount;
            } else if ( toUnit == "yd" ) {
                res = amount / fttoin / ydtoft;
            } else if ( toUnit == "mi" ) {
                res = amount / fttoin / ydtoft / mitoyd;
            } else {
                res = amount / fttoin;
            }
        } else if ( fromUnit == "yd" ) {
            if ( toUnit == "in" ) {
                res = amount * ydtoft * fttoin;
            } else if ( toUnit == "yd" ) {
                res = amount;
            } else if ( toUnit == "mi" ) {
                res = amount / mitoyd;
            } else {
                res = amount * ydtoft;
            }
        } else if ( fromUnit == "mi" ) {
            if ( toUnit == "in" ) {
                res = amount * mitoyd * ydtoft * fttoin;
            } else if ( toUnit == "yd" ) {
                res = amount * mitoyd;
            } else if ( toUnit == "mi" ) {
                res = amount;
            } else {
                res = amount * mitoyd * ydtoft;
            }
        }

        return res;
    }
};
