#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M=1000000007;

int main(){
    int n;
    vector<int> v;

    ll pow2[64];

    pow2[0]=2;

    for(int i=1;i<64;i++){
        pow2[i] = pow2[i-1]*pow2[i-1]%M;
    }

    cin>>n;
    v.resize(n);

    for(auto &x:v) cin>>x;

    sort(v.begin(),v.end());
    
    if(v[0]!=0 || (v.size()>1 && v[0]==v[1])){
        cout << 0 << endl;
        return 0;
    }

    int c=0,last_c=1,t=1;
    ll res=1;

    for(int i=1;i<n;i++){
        int p=v[i];

        if(t==p){
            c++;
        }else{
            if(t+1 != p){
                cout << 0 << endl;
                return 0;
            }

            ll t1=1,t2=last_c;
            for(int j=0;t2>0;j++,t2>>=1){
                if(t2 & 1){
                    t1 = t1*pow2[j]%M;
                }
            }
            t1--;
            for(int j=0;j<c;j++) res = res*t1%M;

            ll tmp=1;
            last_c=c;
            c=c*(c-1)%M/2;

            for(int j=0;c>0;j++,c>>=1){
                if(c & 1){
                    tmp = tmp*pow2[j]%M;
                }
            }
            res=res*tmp%M;

            t=p;
            c=1;
        }
    }

    ll t1=1,t2=last_c;
    for(int j=0;t2>0;j++,t2>>=1){
        if(t2 & 1){
            t1 = t1*pow2[j]%M;
        }
    }
    t1--;
    for(int j=0;j<c;j++) res = res*t1%M;

    ll tmp=1;
    c=c*(c-1)%M/2;

    for(int j=0;c>0;j++,c>>=1){
        if(c & 1){
            tmp = tmp*pow2[j]%M;
        }
    }

    res=res*tmp%M;

    cout << res << endl;
}
