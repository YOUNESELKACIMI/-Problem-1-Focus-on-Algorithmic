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


int helper(vi &low, vi &high,int depth, int choice)
{
    if(low.size() < depth) return 0;

    int low_choice = helper(low, high, depth + 1, low[depth]) + choice;
    int zero_choice = helper(low, high, depth + 1, 0) + choice;
    int high_choice = 0;
    if(choice == 0)
    high_choice = helper(low, high, depth + 1, high[depth]) + choice;
    return max({low_choice, zero_choice, high_choice});
}
int solve(vi &low, vi &high)
{
    return max(helper(low, high, 1, 0), helper(low, high, 1, low[0]));
}
signed main()
{
    vi low = {10, 1, 10, 10};
    vi high = {5, 50, 5, 1};

    int ans = solve(low, high);
    cout << ans << "\n";
}