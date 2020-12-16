// CodeChef December 20 Challenge Problem - Even Pair Sum.
// https://www.codechef.com/DEC20B/problems/EVENPSUM
// https://www.geeksforgeeks.org/count-odd-and-even-numbers-in-a-range-from-l-to-r/

#include<bits/stdc++.h>
using namespace std;
#define L long long int

L evenSum(L a,L b){

    L evenA,evenB,oddA,oddB;
    oddA = (a-1)/2 + 1;
    oddB = (b-1)/2 + 1;
    evenA = a-oddA;
    evenB = b-oddB;

    return (evenA*evenB + oddA*oddB);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        L a,b;
        cin>>a>>b;
            cout << evenSum(a,b) << "\n";
    }

    return 0;
}