#include<bits/stdc++.h>

using namespace std;
const int maxN=1010;
const int chu_vi=999999;

int n, k,kq=1000000;
int a[maxN];

void docdl(){
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    cin>>k;
}

int kt(int x){
    int best=n;
    int duongkinh=x*2;
    int xp=1;
    while (xp<=n && a[xp]<=a[1]+duongkinh){
        int cnt=1;
        int kt=a[xp];
        int i=xp+1;
        while(i<=n && a[i]<=a[xp]+chu_vi-duongkinh){
            if (a[i]>kt){
                cnt++;
                kt=a[i]+duongkinh;
            }
            i++;
        }
        best=min(best,cnt);
        xp++;
    }
    return best;

}

void xuli(){
    int l=-1;
    int r=1000000;
    while (r>l+1){
        int x=(l+r)/2;
        if (kt(x)>k) {l=x;} else r=x;
    }
    cout<<r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen("tps.inp", "r"))
    {
        freopen("tps.inp", "r", stdin);
        freopen("tps.out", "w", stdout);
    }
    docdl();
    xuli();
//    ghikq();

}
