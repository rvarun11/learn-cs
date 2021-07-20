#include<iostream>
#include<string>
using namespace std;

void TOH(int n, int A, int B, int C);

int main(){
    TOH(3,1,2,3);
    return 0;
}

void TOH (int n, int A, int B, int C){
    // A,B & C are the three towers
    if (n>0){
        TOH(n-1,A,C,B);
        cout << "from " << A << " to " << C <<endl;
        TOH(n-1,B,A,C);
    }
}
