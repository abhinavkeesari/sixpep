#include <bits/stdc++.h>
using namespace std;
 
// Find maximum profit earned from at most `k` stock transactions.
int findMaxProfit(vector<int> const &price, int k)
{
    
    int n = price.size();
 
    // base case
    if (n <= 1) {
        return 0;
    }
 
    // profit[i][j] stores the maximum profit gained by doing
    int profit[k+1][n+1];
 
  
    for (int i = 0; i <= k; i++)
    {
        // initialize `prev` diff to `-INFINITY`
        int prev_diff = INT_MIN;
 
        for (int j = 0; j < n; j++)
        {
            // profit is 0 when:
            // i = 0, i.e., for 0
            // j = 0, i.e., no transaction is being performed
 
            if (i == 0 || j == 0) {
                profit[i][j] = 0;
            }
            else {
                prev_diff = max(prev_diff, profit[i-1][j-1] - price[j-1]);
                profit[i][j] = max(profit[i][j-1], price[j] + prev_diff);
            }
        }
    }
 
    return profit[k][n - 1];
}
 
int main()
{
    vector<int> share_prices = { 100, 30, 15, 10, 8, 25, 80 };//change the dataset for your convenience
    int k;
    cin>>k;
 
    cout << "The maximum possible profit is " << findMaxProfit(share_prices, k);
 
    return 0;
}
