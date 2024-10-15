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
#define mean(a, b) ((a + b) / 2)

vector<pi> when_to_buy(vi &prices)
{

    int n = prices.size();
    int low = 0;
    int high = 0;
    vector<pi> ans;
    bool found = 0;
    for (int i = 1; i < n; i++)
    {

        // when to buy (local minimum)
        found = 0;
        if (prices[i] < prices[i - 1] && i < n - 1 && prices[i] < prices[i + 1])
            low = i;

        // when to sell (local maximum)
        if (prices[i] > prices[i - 1] && ((i < n - 1 && prices[i] > prices[i + 1]) || (i == n - 1)))
        {
            high = i;
            found = 1;
        }
        if (found)
            ans.PB({low + 1, high + 1});
    }
    return ans;
}

signed main()
{
    vi prices = {45, 20, 30, 35, 32, 30, 89, 40, 45, 52};
    // vi prices = {100, 90, 80, 85, 70, 60, 65, 55, 50, 75};
    // vi prices = {1,2,3,4,5};
    // vi prices = {5,4,3,2,1};
    vector<pi> ans = when_to_buy(prices);

    for (auto a : ans)
    {
        cout << "buy on day " << a.F << " (" << prices[a.F - 1] << ") " << ", sell on day " << a.S << " (" << prices[a.S - 1] << ")\n";
    }
}