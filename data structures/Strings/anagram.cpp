#include<iostream>
using namespace std;

int main(){
    int H{26}={0},i;
    string str1 = "decimal";
    string str2 = "medica";

    for (i=0;i<str1.size();i++)
        H{str1{i}-97}+=1;

    for (i=0;i<str2.size();i++){
        int p = str2{i}- 97;
        H{p}-=1;
        if (H{p}<0){
            cout << "not anagram" << endl;
            break;
        }
    }

    if (str2{i} == '\0')
        cout << "anagram" << endl;

    return 0;
}