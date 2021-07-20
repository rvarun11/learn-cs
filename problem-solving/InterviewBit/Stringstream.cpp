// https://www.interviewbit.com/problems/stringstream/
// https://www.cplusplus.com/reference/ios/ios/good/

#include<iostream>
#include<sstream>
using namespace std;

int main(){
    string A;
    cin >> A;
    stringstream ss(A);
    // good() tells the state of the state of the stream.
    while (ss.good()){
        string sub;
        getline(ss,sub,',');
        cout << sub << endl;
    }
    return 0;
}