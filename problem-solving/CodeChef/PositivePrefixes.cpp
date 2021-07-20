// CodeChef December 20 Challenge Problem - Positive Prefixes
// https://www.codechef.com/DEC20B/problems/POSPREFS
// INCOMPLETE - Not able to solve.

#include<bits/stdc++.h>
#include<vector>
using namespace std;


int main(){
    int t=1,n=10,k=3;
    cin>>t;
    while(t--){
        cin>>n>>k; 
        if (n==k){
            for(int i=0;i<n;i++)
                cout << i+1 << " ";
        }
        else{
            int a=n/2,b;
            vector<int> arr;
            // Creating a list of numbers with even nos as +ve &  odd nos as -ve
            for (int i=0;i<n;i++){
                if ((i+1)%2!=0)
                    arr.push_back((-1)*(i+1));
                else
                    arr.push_back(i+1);
            }
            //Logic
            if (a<k){
                b=k-a;
                for (int i=n-1;i>=0;i--){
                    if (b==0)
                        break;
                    if (i%2==0){
                        b--;
                        arr.at(i)=arr.at(i)*(-1);
                    }
                }
            }
            if (a>k){
                b=a-k;
                for (int i=n-1;i>=0;i--){
                    if (b==0)
                        break;
                    if (i%2!=0){
                        b--;
                        arr.at(i)=arr.at(i)*(-1);
                    }
                }
            }
            for (int i=0;i<n;i++)
                cout << arr{i} << " ";
            cout << endl;
        }
    }
    return 0;
}