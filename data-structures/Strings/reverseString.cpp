#include<iostream>
#include<string>
using namespace std;

int main(){
    string str = "iii";
    string rev;
    for (int i=str.size()-1;i>=0;i--)
        rev += str{i};
    
    int x = str.compare(rev);
    if (x==0)
        cout << str +  " equals " + rev << endl;
    else
        cout << str + " not equals " + rev << endl;

    cout << x << endl;
    return 0;
}