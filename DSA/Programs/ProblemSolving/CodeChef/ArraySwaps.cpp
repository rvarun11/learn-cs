//
#include <bits/stdc++.h> 
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr,brr;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    for (int i=0;i<m;i++){
        int x;
        cin>>x;
        brr.push_back(x);
    }
    sort(brr.begin(),brr.end());
    int c=0;
    while(brr.empty()){
        int x = brr.front();
        brr.erase(brr.begin());
        arr.insert(arr.begin(),x); 
        int i=0;
        while (i!=arr.size()){
            int y = arr[i];
            if (y>=arr[i+1])
                break;
            arr[i] = arr[i+1];
            arr[i+1] = y;
            c++;
            i++;
        }
    }
    cout << c << endl;
    return 0;
}