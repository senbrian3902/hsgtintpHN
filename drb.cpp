#include <bits/stdc++.h>
using namespace std;
#define FILENAME "DRB"

int s1, v1, s2, v2;

int solve(){
	if ((s1 < s2 && v1 <= v2) || (s2 < s1 && v2 <= v1)) return -1;
	return abs(s1 - s2) / abs(v1 - v2);
}

signed main(){
	freopen(FILENAME".inp", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> s1 >> v1 >> s2 >> v2;
    cout << solve();

}
