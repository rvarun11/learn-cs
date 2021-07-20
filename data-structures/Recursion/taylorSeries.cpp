#include<iostream>
using namespace std;
int taylor(int x,int n);

int main(){
    int x = taylor(5,3);
    cout << x << endl;
    return 0;
}

int taylor (int x, int n){
    static int p = 1, f = 1;
    int res;

    if (n==0)
        return 1;
    else{
        p = p * n;
        f = f * n;
        res = taylor(x,n-1) + p/f;
    }
}