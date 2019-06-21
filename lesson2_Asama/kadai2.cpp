#include <bits/stdc++.h>
using namespace std;

static const int MAX = 10000;
static const int INFTY = (1<<21);
static const int WHITE = 0; // 未到達
static const int GRAY = 1; // 到達
static const int BLACK = 2; // 探索済み

int n;

vector<pair<int, int>> adj[MAX]; // 重み付き有向グラフの隣接リスト表現

void dijkstra() {
  priority_queue<pair<int, int>> PQ;
  int color[MAX];
  int d[MAX]; // startからの最短距離
  int p[MAX]; // 最短距離での親ノード
  for (int i = 0; i < n; i++) {
    d[i] = INFTY;
    color[i] = 0;
    p[i] = -2;
  }

  d[0] = 0;
  p[0] = -1; // startの親ノード番号は−1とする
  PQ.push(make_pair(0, 0));
  color[0] = GRAY;

  while (!PQ.empty()) {
    pair<int, int> f = PQ.top();
    PQ.pop();
    int u = f.second;
    color[u] = BLACK;

    for (int j = 0; j < adj[u].size(); j++) {
      int v = adj[u][j].first;
      if (color[v] == BLACK) continue;
      if (d[v] > d[u] + adj[u][j].second) {
        d[v] = d[u] + adj[u][j].second;
        p[v] = u;
        // priority_queueはデフォルトで大きい値を優先するため-1をかける
        PQ.push(make_pair(d[v] * (-1), v));
        color[v] = GRAY;
      }
    }
  }

  vector<int> shortest;

  // terminal nodeへの最短ルートをshortestに逆順に格納
  int tmpParent = p[n - 1];
  shortest.push_back(n - 1); // teminal node の番号を格納
  while (tmpParent != -1) {
    shortest.push_back(tmpParent);
    tmpParent = p[tmpParent];
  }

  reverse(shortest.begin(), shortest.end());


  // temrminal nodeへの最短ルートを表示
  cout << "最短ルート" << endl;
  for (int i = 0; i < shortest.size(); i++) {
    if (i < shortest.size() - 1) {
      cout << shortest[i] + 1 << " -> ";
    } else {
      cout << shortest[i] + 1 << endl;
    }
  }

  // コストを表示
  cout << "最短ルートでのコスト" << endl;
  cout << d[n - 1] << endl;
};

int main() {
  int k, u, v, c;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v >> c;
      adj[u].push_back(make_pair(v,c));
    }
  }

  dijkstra();
};
