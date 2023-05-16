#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// need to pass by reference
ll cost(vector<ll>& h, ll i, ll j)
{
    return abs(h[i]-h[j]); 
}

void solve()
{
    //fast_cin();
    ll N;
    cin >> N;
    vector<ll> arr_h;
    for(ll i = 0; i < N; i++)
    {
        int h;
        cin >> h;
        arr_h.emplace_back(h);
    }

    vector<ll> dp(N, 0);
    dp[0] = 0;
    for(int i = 1; i < N; i++)
    {
        if(i-2 >= 0)
        {
            //dp[i] = min(dp[i-1]+abs(arr_h[i]-arr_h[i-1]), dp[i-2]+abs(arr_h[i]-arr_h[i-2]));
            dp[i] = min(dp[i-1]+cost(arr_h, i, i-1), dp[i-2]+cost(arr_h, i, i-2));
        }
        else if(i == 1)
        {
            dp[i] = dp[i-1]+abs(arr_h[i]-arr_h[i-1]);
        }
    }

    //printf("%lld", dp[N-1]);
    cout << dp[N-1] << endl;

}


int main()
{

    #ifndef ONLINE_JUDGE
    freopen("ia.txt", "r", stdin);
    freopen("oa.txt", "w", stdout);
    #endif
    
    //fast_cin();

    solve();

    return 0;
}
