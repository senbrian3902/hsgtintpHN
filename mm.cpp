#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;

string s;
int imam[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  if (fopen("mm.inp", "r"))
    {
        freopen("mm.inp", "r", stdin);
        freopen("mm.out", "w", stdout);
    }
  cin >> s;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') continue;
    int broj = 0;
    int j = i;
    for (; j < (int)s.size() && s[j] >= '0' && s[j] <= '9'; j++) {
      broj *= 10;
      broj += s[j] - '0';
    }
    imam[broj] = 1;
    i = j - 1;
  }

  int rj = 0;
  for (int i = 0; i < MAXN; i++) {
    rj += imam[i];
  }
  cout << rj << endl;
  return 0;
}

