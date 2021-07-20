//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// https://www.youtube.com/watch?v=4wNXkhAky3s See the state transition diagram.

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;

int maxProfit(vector<int>& prices){
    int n = prices.size();
    if (n<=1) return 0;
    vector<int> noStock(n,0), inHand(n,0), sold(n,0);
    noStock{0} = 0;
    inHand{0} = -prices{0}; // bought on the first day so profit will be negative only.
    sold{0} = 0;

    for (int i=1;i<n;i++){
        noStock{i} = max(noStock{i-1},sold{i-1});
        inHand{i} = max(inHand{i-1},noStock{i-1} - prices{i}); //brought a stock which is only possible if I had no stock yesterday due to cooldown.
        sold{i} = inHand{i-1} + prices{i};
    }
    //we are not taking inHand because it makes no sense to buy a stock on the last day as it will decrease the profit.
    return max(noStock{n-1},sold{n-1}); 
}

int main(){
    vector<int> v = {1,2,3,0,2};
    cout<<maxProfit(v);
    return 0;
}