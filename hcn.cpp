//#include </Users/tungfint/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define inf32 0x3f3f3f3f
#define inf64 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end());
#define setinf(d) memset(d, inf32, sizeof d)
#define setneg(d) memset(d, -1, sizeof d)
#define set0(d) memset(d, 0, sizeof d)
#define Log2(x) 63 - __builtin_clzll(x)
#define oo 2e18
#define mod 1000000007
#define FILENAME "hcn"

const int maxn = 10005;

int n, m, k;
vector<int> a[maxn], check;
int cnt[maxn];
bool banned[maxn];
bool del[maxn];
signed main(){
    freopen(FILENAME".inp", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        if(x != 1)
        check.push_back(x - 1);
        check.push_back(x);
        if(x != n)
        check.push_back(x + 1);
    }

    check.push_back(1);
    check.push_back(n);
    sort(all(check));
    Unique(check);

    int ans = 0;
    for(int idx = 0; idx < check.size(); idx++){
        int i = check[idx];
        if(ans > (n - i + 1) * m) continue;
        set<int> s;
        priority_queue<int> q;
        s.insert(0);
        s.insert(m + 1);
        set0(cnt);
        set0(banned);
        for(int idx2 = idx; idx2 < check.size(); idx2++){
            int &j = check[idx2];
            for(int &d : a[j]){
                if(s.count(d)){
                    if(banned[d]) continue;
                    banned[d] = true;
                    auto it = s.lower_bound(d);
                    --cnt[*next(it) - *prev(it) - 1];
                    continue;
                }
                s.insert(d);
                auto it = s.lower_bound(d);
                q.push(*next(it) - *prev(it) - 1);
                ++cnt[*next(it) - *prev(it) - 1];
                if(prev(it) != s.begin() && !banned[*prev(it)]){
                    q.push(d - *prev(prev(it)) - 1);
                    ++cnt[d - *prev(prev(it)) - 1];
                    --cnt[*next(it) - *prev(prev(it)) - 1];
                }
                if(next(next(it)) != s.end() && !banned[*next(it)]){
                    q.push(*next(next(it)) - d - 1);
                    ++cnt[*next(next(it)) - d - 1];
                    --cnt[*next(next(it)) - *prev(it) - 1];
                }
            }
            while(q.size() && !cnt[q.top()]) q.pop();
            if(q.size()) ans = max(ans, q.top() * (j - i + 1));
        }
    }
    
    cout << ans;
}
