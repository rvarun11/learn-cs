//https://cses.fi/problemset/task/1163

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;

// const lli mod = 1e9 + 7;

int main(){
    int x,n,point,l,r;
    cin>>x>>n;
    set<int> locations = {0,x};
    multiset<int> distances;
    
    for (int i=0;i<n;i++){
        cin>>point;
        
        auto it = locations.upper_bound(point);
        l = *prev(it);
        r = *it;

        
        locations.insert(point);

        auto e = distances.find(r-l);
        if (e!=distances.end())
            distances.erase(e);
        
        distances.insert(point-l);
        distances.insert(r-point);

        cout<<*distances.rbegin()<<" ";
    }
    return 0;
}

/*
Let their be a set, locations, initialized to {0,x} which will store locations of all the points, and a 
multiset distances which will store distances between all point.

For each input do the following:
    i.   Find elements to the left and right of that point.
    ii.  Erase the range (right-left) if it exists. {so that if when point is added between that range, that range doesnt exist anymore}
    iii. Insert the distances (point - left) and (right - point) to distances.
    iv.  Print the right most element in distances.
*/
