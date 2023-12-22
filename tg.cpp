#include <bits/stdc++.h>
using namespace std;

string fix(int x)
{
    if (x < 10)
    {
        return string{'0'} + to_string(x);
    }
    else
    {
        return to_string(x);
    }
}
void solve()
{
    int X;
    cin >> X;
    int H = X < 60 ? 8 : 9;
    int M = X % 60;
    cout << 0 << H << ':' << fix(M) << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen("tg.inp", "r"))
    {
        freopen("tg.inp", "r", stdin);
        freopen("tg.out", "w", stdout);
    }
    int Te = 1;
    cin >> Te;
    while (Te--)
    {
        solve();
    }
    
}
