#include<bits/stdc++.h>
#define int     long long
using namespace std;

#undef int
int main() {
#define int     long long
    if (fopen("vni.inp", "r")) {
        freopen("vni.inp", "r", stdin);
        freopen("vni.out", "w", stdout);
    }

    int numTest = 1;

    while (numTest--) {
        int n;
        cin >> n;

        vector<int> c(n+1, 0);
        vector<int> s(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
            s[i] = s[i-1] + c[i];
        }

        auto getSum = [&] (int l, int r) -> int {
            return s[r] - s[l-1];
        };

        vector<int> V;
        /* prepare */ {
            stack<int> st;
            for (int i = 1; i <= n; ++i) {
                while (st.size() && c[st.top()] < c[i]) {
                    st.pop();
                }
                st.push(i);
            }

            while (st.size()) {
                V.push_back(st.top());
                st.pop();
            }
            reverse(V.begin(), V.end());
        }

        vector<int> partialRes((int) V.size() + 1, 0);
        for (int i = (int) V.size()-1; i >= 0; --i) {
            int val;
            if (i == 0) {
                int num = V[i];
                val = c[V[i]] * num - getSum(1, V[i]);
            }
            else {
                int num = V[i] - V[i-1];
                val = c[V[i]] * num - getSum(V[i-1]+1, V[i]);
            }
            partialRes[i] = partialRes[i+1] + val;
        }

        int Q;
        cin >> Q;

        for (int iTest = 1; iTest <= Q; ++iTest) {
            int t;
            cin >> t;

            int p = lower_bound(V.begin(), V.end(), t) - V.begin();
            int tUp = V[p];
            int res = partialRes[p+1] + (tUp - t + 1) * c[tUp] - getSum(t, tUp);
            cout << res << '\n';
        }
    }
}
