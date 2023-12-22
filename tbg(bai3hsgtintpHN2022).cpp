#include<bits/stdc++.h>
#define int long long
using namespace std;

#undef int
int main() {
#define int long long
    if (fopen("tbg.inp", "r")) {
        freopen("tbg.inp", "r", stdin);
        freopen("tbg.out", "w", stdout);
    }

    int x, y, z;
    cin >> x >> y >> z;
    assert(x > y);

    auto check = [&] (int mid) -> bool {
        int s = mid * y;
        for (int i = 1; i <= z; ++i) {
            s += y;
            if (s < x * i) {
                return false;
            }
        }
        return true;
    };

        // cerr << "??? " << check(3) << '\n';
        // exit(0);

    int l = 1, r = x * z;
    int res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << res << '\n';
}
