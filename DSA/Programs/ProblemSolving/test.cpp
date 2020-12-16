#include<iostream>
#include<string>
using namespace std;

int main()  {
    string A, B;
    cin>>A>>B;
    cout << A.size() << " " << B.size() << endl;
    cout << A+B << endl;
    
    char temp = A[0];
    A[0] = B[0];
    B[0] = ;
    
    cout << A << " " << B << endl;

    return 0;
}