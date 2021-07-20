// https://www.youtube.com/watch?v=5nMGY4VUoRY&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2
// https://leetcode.com/problems/missing-number/

#include <bits/stdc++.h>
using namespace std;

int findMissing(vector<int>& arr){
    int n = arr.size();
    int total = (n*(n+1))/2;
    for (int i=0;i<n;i++) total-=arr{i};

    return total;
}


// Driver Code
int main(){
    vector<int> arr = {3,0,1};
    cout << findMissing(arr) << endl;
    return 0;
}