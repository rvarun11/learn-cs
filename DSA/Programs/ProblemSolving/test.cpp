
#include <iostream>
using namespace std;

// Your code goes here
template < class type>
int index_of_largest(type arr[],int n){
    int max_ind=0;
    type max = arr[0];
    for(int i=0;i<n;i++){
      if( arr[i] > max){
          max = arr[i];
          max_ind = 1;
      } 
        max_ind+=1;  
    }
    return max_ind;
}


int main()  {
    int n;
    // cin>>n;
    // int arr_int[n];
    // for(int i = 0; i < n; i++){
    //        cin>>arr_int[i];
    //    }
    //  int res = index_of_largest<int>(arr_int, n);
    //    cout<<res<<endl;
    cin>>n;
    double arr_double[n];
    for(int i = 0; i < n; i++){
          cin>>arr_double[i];
      }
     int res1 = index_of_largest<double>(arr_double, n);
    cout<<res1<<endl;
    return 0;
}

/*
5
4 2 10 13 2
4
2.4 5.2 3.1 1.5
6
4.1 2.1 10.1 13.1 2.1 3.1
*/