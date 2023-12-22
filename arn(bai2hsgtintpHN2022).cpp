#include <bits/stdc++.h>
using namespace std;
#define FILENAME "ARN"

string s, x;

int solve(){
	int res = 0, pos = 0;
	while (1){
		pos = s.find(x, pos);
		if (pos >= s.size() || pos < 0) break;
		res++;
		pos += x.size();
	}
		
	return res;
}

signed main(){
	freopen(FILENAME".inp", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> s >> x;
   	cout << solve();

}
