#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()  {
    int n;
    cin>>n;
    vector<int> vect;
    for (int i=0;i<n;i++){
        int y;
        cin>>y;
        vect.push_back(y);
    }
    int x;
    cin>>x;
    vect.erase(vect.begin()+x);
    sort(vect.begin(),vect.end());
    for (int i=0;i<n-1;i++){
        cout << vect.at(i) << endl;
    }
    return 0;
}