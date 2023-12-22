#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define inf32 0x3f3f3f3f
#define inf64 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define setinf(d) memset(d, inf32, sizeof d)
#define setneg(d) memset(d, -1, sizeof d)
#define set0(d) memset(d, 0, sizeof d)
#define Log2(x) 63 - __builtin_clzll(x)
#define oo 2e18
#define mod 1000000007
#define FILENAME "f"
#define int long long

const int maxn = 1e5 + 5;

int n;
int a[maxn], r[maxn], mim[maxn], pre[maxn];
mt19937 d(time(0));
vector<pi> query[maxn];

int f(int l, int r){
    if(l == r) return 1;

    int m = (l + r) >> 1, ans = 0;

    {
        unordered_map<int, int> cnt;
        int mx = -inf32, mn = inf32;
        int p = m + 1, pmx = m + 1, vmx = -inf32;

        for(int i = l; i <= m + 1; i++) query[i].clear();

        for(int i = m + 1; i <= r; i++){
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);

            if(i - m < mx - mn + 1 &&i - (mx - mn) >= l){
                ans += (mim[mx] - mim[mn - 1]) == (pre[i] - pre[i - (mx - mn) - 1]);
            }

            while(p - 1 >= l && a[p - 1] > mn) --p;
            while(pmx - 1 >= l && vmx < mx){
               vmx = max(vmx, a[--pmx]);
            }
            if(vmx < mx) --pmx;

            if(p <= pmx){

                query[p].push_back({pre[i] + mim[mn - 1], 1});
                query[pmx + 1].push_back({pre[i] + mim[mn - 1], -1});
            }

        }

        mx = -inf32;
        for(int i = m; i >= l; i--){
            mx = max(mx, a[i]);
            cnt[mim[mx] + pre[i - 1]]++;
            for(auto &p : query[i]){
                ans += p.second * cnt[p.first];
            }
        }
    }


    {
        unordered_map<int, int> cnt;
        int mx = -inf32, mn = inf32;
        int p = m, pmx = m, vmx = -inf32;

        for(int i = m; i <= r; i++) query[i].clear();

        for(int i = m; i >= l; i--){
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);

            if(m - i + 1 < mx - mn + 1 && i + mx - mn  <= r){
                ans += (mim[mx] - mim[mn - 1]) == (pre[i + (mx - mn + 1) - 1] - pre[i - 1]);
            }

            while(p + 1 <= r && a[p + 1] > mn) ++p;
            while(pmx + 1 <= r && vmx < mx) vmx = max(vmx, a[++pmx]);
            if(vmx < mx) ++pmx;

            if(p >= pmx){
                query[p].push_back({pre[i - 1] - mim[mn - 1], 1});
                query[pmx - 1].push_back({pre[i - 1] - mim[mn - 1], -1});
            }

        }

        mx = -inf32;
        for(int i = m + 1; i <= r; i++){
            mx = max(mx, a[i]);
            cnt[pre[i] - mim[mx]]++;
            for(auto &p : query[i]){
                ans += p.second * cnt[p.first];
            }
        }
    }
    return ans + f(l, m) + f(m + 1, r);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen("dd.inp", "r"))
    {
        freopen("dd.inp", "r", stdin);
        freopen("dd.out", "w", stdout);
    }

    cin >> n;

    for(int i = 1; i <= n; i++){
        r[i] = d();
        mim[i] = mim[i - 1] + r[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + r[a[i]];
    }

    cout << f(1, n);

 //  cout << endl << clock() - start;
}
