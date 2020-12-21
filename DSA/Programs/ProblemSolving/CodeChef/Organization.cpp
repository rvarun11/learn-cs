// https://www.codechef.com/UWCOI21/problems/UWCOI21B
// https://discuss.codechef.com/t/uwcoi21c-organisation-editorial/82417
#include <bits/stdc++.h> 
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> color;
    for (int i=0;i<n+1;i++){
        int x;
        cin>>x;
        color.push_back(x);
    }
    int td=n*k;
    for(int i=0;i<n;i++){
        int ic=0,lc,rc=0;
        lc = *min_element(color.begin(),color.end());
        if (lc<4){
            ic+=lc;
            rc=4-ic;
        }

    }

    return 0;
}