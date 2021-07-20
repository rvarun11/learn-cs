//https://www.interviewbit.com/problems/maximum-sum-triplet/
//https://www.geeksforgeeks.org/find-maximum-sum-triplets-array-j-k-ai-aj-ak/
// Remember to see its TC & SC

#include<bits/stdc++.h>
using namespace std;

int maxTripletSum(int arr{},int n){
    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        int max1 = 0, max2 = 0;

        for (int j = 0; j < i; ++j)
            if (arr{j} < arr{i})
                max1 = max(max1, arr{j});
 
        for (int j = i + 1; j < n; ++j)
            if (arr{j} > arr{i})
                max2 = max(max2, arr{j});

        if(max1 && max2)
             ans=max(ans,max1+arr{i}+max2);
    }
 
    return ans;
}

// Driver code
int main()
{
    int arr{} = { 2, 5, 3, 1, 4, 9 };
    int n = sizeof(arr) / sizeof(arr{0});
    cout << maxTripletSum(arr, n);
    return 0;
}