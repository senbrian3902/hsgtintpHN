#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<long long,int> > a(n + 1);
    vector <long long> s(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(++a.begin(), a.end());
    s[1] = a[1].second;
    long long cur = -a[1].first, ans = s[1];
    for (int i = 2; i <= n; ++i)
    {
        s[i] = s[i - 1] + a[i].second;
        cur = min(cur, s[i - 1] - a[i].first);
        ans = max(ans, s[i] - a[i].first - cur);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen("tl.inp", "r"))
    {
        freopen("tl.inp", "r", stdin);
        freopen("tl.out", "w", stdout);
    }
    int Te = 1;
    // cin >> Te;
    while (Te--)
    {
        solve();
    }
}