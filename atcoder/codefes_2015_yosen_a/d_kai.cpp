#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> x,d;

bool ok(int t){
    int lb,ub,l,r;
    d[0]=0;
    
    for(int i=1;i<=m;i++){
        if(x[i-1]<d[i-1]+1){
            d[i] = max(d[i-1],x[i-1]+t);
        }else{
            l=x[i-1]-d[i-1]-1;
            if(l>t) return false;
            r=max(t-l*2,(t-l)/2);
            d[i]=x[i-1]+r;
        }

        if(d[i]>=n) return true;
    }
    return false;
}

int main(){
    cin>>n>>m;
    d.resize(m+1);

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
