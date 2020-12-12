// CodeChef December 20 Challenge Problem - Even Pair Sum.
// https://www.codechef.com/DEC20B/problems/VACCINE1

#include<bits/stdc++.h>
using namespace std;

int leastDays(int d1,int v1,int d2,int v2,int p){
    int d=1,produced=0;
    while(produced<=p){
        if (d>=d1)
            produced+=v1;
        if (d>=d2)
            produced+=v2;
        if (produced>=p)
            break;
        d++;
    }
    return d;
}

int main(){
    int D1,V1,D2,V2,P;
    cin>>D1>>V1>>D2>>V2>>P;
    cout << leastDays(D1,V1,D2,V2,P) << "\n";
    return 0;
}