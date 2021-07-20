// https://www.codechef.com/DEC20B/problems/VACCINE2

#include<bits/stdc++.h>
#define L long long int

using namespace std;

int vaccineDays(int n,int d){
    L ages{n},r1=0,r2=0;
    for (int i=0;i<n;i++){
        cin>>ages{i};
        if (ages{i}>=80 || ages{i}<=9)
            r1++;
        else
            r2++;
        }
    return ceil((double)r1/(double)d)+ceil((double)r2/(double)d);
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    L t;
    cin >> t;
    while(t--){
        L n,d;
        cin>>n>>d;
        cout << vaccineDays(n,d) << "\n";
    }
    return 0;
}