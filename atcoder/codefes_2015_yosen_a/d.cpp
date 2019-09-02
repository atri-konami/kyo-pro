#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> x,d;

bool ok(int t){
    long long lb,ub,l;
    d[0]=0;
    
    for(int i=1;i<=m;i++){
        l=x[i-1]-d[i-1]-1;
        if(l>t) return false;

        if (i==m){
            return min(l*2+(n-x[i-1]),l+2*(n-x[i-1])) <= t;
        }else{
            lb=0,ub=2*n;

            while(lb+1<ub){
                long long mid=(lb+ub)/2;
                if(min(l*2+mid,l+2*mid)<=t && x[i-1]+mid < x[i]){
                    lb=mid;
                }else{
                    ub=mid;
                }
            }

            if((d[i] = x[i-1]+lb)>=n) return true;
        }
    }                                 
}

int main(){
    cin>>n>>m;
    d.resize(m+5);

    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        x.push_back(t);
    }

    long long lb=-1,ub=2*n;

    while(lb+1<ub){
        long long mid = (lb+ub)/2;
        if(ok(mid)){
            ub=mid;
        }else{
            lb=mid;
        }
    }

    cout << ub << endl;
}
