#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> x,d;

bool ok(double t){
    d[0]=0;
    
    for(int i=1;i<=m;i++){
        int l=x[i-1]-d[i-1]-1,r=0;
        while(true){
            if(min(l*2+r,l+r*2) > t || (i!=m && x[i] <= x[i-1]+r)){
                if(r==0){
                    return false;
                }else{
                    r--;
                    break;
                }
            }else{
                r++;
            }
        }
        d[i]=x[i-1]+r;
    }

    return d[m]>=n;
}

int main(){
    cin>>n>>m;
    d.resize(m+1);
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        x.push_back(t);
    }

    double lb=0,ub=3*n;

    for(int i=0;i<1000;i++){
        double mid = (lb+ub)/2;

        if(ok(mid)){
            ub=mid;
        }else{
            lb=mid;
        }
    }

    cout << round(lb) << endl;
}
