//https://www.interviewbit.com/problems/templates-1/
// https://stackoverflow.com/questions/2953491/finding-the-position-of-the-max-element

#include <iostream>
#include<algorithm>
using namespace std;

// Your code goes here

template<class T>
int index_of_largest(T arr{},int n){
    return distance(arr,max_element(arr,arr+n));
}


int main()  {
    int n;
    
    // cin>>n;
    // int arr_int{n};
    // for(int i = 0; i < n; i++){
    //     cin>>arr_int{i};
    // }
    // int res = index_of_largest<int>(arr_int, n);
    // cout<<res<<endl;
    
    cin>>n;
     double arr_double{n};
     for(int i = 0; i < n; i++){
         cin>>arr_double{i};
    }
    int res = index_of_largest<double>(arr_double, n);
    cout<<res<<endl;
    return 0;
}