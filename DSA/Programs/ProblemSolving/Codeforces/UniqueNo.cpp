#include<iostream>
using namespace std;

int getSum(int n){
    int sum=0;
    while (n!=0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int find(int x){
    if (x<10)
        return x;
    if (x%10==0)
        return -1;

    

    return num;
}
int main(){
    int x=5;
    cout << find(x) << endl;
    return 0;
}