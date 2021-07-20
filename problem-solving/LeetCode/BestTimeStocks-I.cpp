//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;

int maxProfit(vector<int>& prices){
    if (prices.size()==1)
        return 0;
    
    int min_price = INT_MAX;
    int max_profit = 0;

    for (auto curr: prices){
        min_price = min(min_price,curr);
        max_profit = max(max_profit,curr-min_price);
    }
    return max_profit;
}