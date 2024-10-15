#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define _vec(x)               \
    {                         \
        for (auto i : x)      \
        {                     \
            cout << i << " "; \
        }                     \
        cout << "\n";         \
    }
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int MAX = 1e6 + 1;
const int M = 1e9 + 7;

int solve(vi &low, vi &high)
{
    int ans = 0;
    int n = low.size();
    vector<vi> dp(n, vi(2));

    dp[0][0] = low[0]; //low risk
    dp[0][1] = 0; //high risk
    for(int i = 1 ; i < n ; i++)
    {
        dp[i][0] = dp[i - 1][0]  + low[i];
        if(i == 1){
            dp[i][1] = max(dp[i][0] , high[1]);
        }
        else{
            dp[i][1] = high[i] + max(dp[i - 2][0], dp[i - 2][1]);
            dp[i][1] = max(dp[i][1], low[i] + max(dp[i - 1][0] , dp[i - 1][1]));
        }
    }
    for(int i = 0 ; i < n ; i++)_vec(dp[i]);
    return dp[n - 1][1];
}
signed main()
{
    vi low = {10, 1, 10, 10};
    vi high = {5, 50, 5, 1};

    // vi low = {70 , 3};
    // vi high = {1, 100};

    // vi low = {10, 20 , 30};
    // vi high = {1,  2 , 3};
    int ans = solve(low, high);
    cout << ans << "\n";
}