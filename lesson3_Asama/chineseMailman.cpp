#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)n; i++)
#define INF 1e9

const int MAX = 10;
int n;
int d[MAX][MAX];
int dp[(1 << MAX)][MAX];

int rec(int S, int v) {
    if(dp[S][v] >= 0) return dp[S][v];
    if(S == (1 << n) - 1 && v == 0) return dp[S][v] = 0;
    int tmp = INF;
    rep(u,n) {
      if(!((S >> u) & 1)) tmp = min(tmp, rec(S | (1 << u), u) + d[v][u]);
    }
    return dp[S][v] = tmp;
}

int main() {
    cin >> n;
    rep(i, n) {
      rep(j, n) {
        if (i == j) d[i][j] = INF;
        else cin >> d[i][j];
      }
    }
    fill((int *)dp, (int *)(dp + (1 << MAX)), -1);
    cout << rec(0, 0) << endl;
    return 0;
}
