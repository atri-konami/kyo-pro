#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;

    cin >> N >> M;

    vector<int> cls(N,0);
    vector<pair<int,int>> range(M);

    for(int i=0;i<M;i++){
        int s,t;
        cin>>s>>t;
        range[i] = make_pair(s-1,t-1);

        cls[s-1]++;cls[t]--;
    }

    for(int i=0;i<N;i++){
        cls[i+1] = cls[i+1] + cls[i];
    }

    //for(int i=0;i<N;i++){
    //    cout << cls[i] << ", ";
    //}
    //cout << endl;

    int res=0;
    vector<int> resv;

    int length = floor(sqrt(N));
    vector<int> bucket( N/length + (N%length>0) );

    for(int i=0;i<bucket.size();i++){
        if(length*(i+1) > N){
            bucket[i] = *min_element(cls.begin()+i,cls.end());
        }else{
            bucket[i] = *min_element(cls.begin()+i*length,cls.begin()+(i+1)*length);
        }
    }

    //for(int i=0;i<bucket.size(); i++){
    //    cout << bucket[i] << ", ";
    //}
    //cout << endl;


    for(int i=0;i<M;i++){
        int s = range[i].first,t = range[i].second;
        int b_s = s/length,b_t = t/length;
        int minnum = INT_MAX;

        if(b_s == b_t){
            for(int j=s;j<=t;j++){
                minnum = *min_element(cls.begin()+s,cls.begin()+t+1);
            }
        }else{
            for(int j=s%length;j<length;j++){
                minnum = min(minnum,cls[j+b_s*length]);
            }

            for(int j=0;j<=t%length;j++){
                minnum = min(minnum,cls[j+b_t*length]);
            }

            for(int j=b_s+1;j<b_t;j++){
                minnum = min(minnum,bucket[j]);
            }
        }

        if(minnum > 1){
            res++;
            resv.push_back(i+1);
        }
    }

    cout << res <<endl;

    for(auto p:resv){
        cout << p << endl;
    }

    return 0;
}
