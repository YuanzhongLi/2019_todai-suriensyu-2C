#include <bits/stdc++.h>
using namespace std;
int maxw = 10;

int main() {
  float w[4];
  float v[4];
  w[0] = 2;
  w[1] = 6;
  w[2] = 7;
  w[3] = 6;
  v[0] = 1;
  v[1] = 5;
  v[2] = 6;
  v[3] = 8;

  vector<pair<float, int>> r(4);
  for (int i = 0; i < 4; i++) {
    r[i].first = v[0] / w[0];
    r[i].second = i;
  }

  sort(r.begin(), r.end());
  reverse(r.begin(), r.end());

  int wsum = 0;
  int f = 0;
  vector<int> ans(4, 0);

  for (int i = 0; i < 4; i++) {
    if (wsum + w[r[i].second] < 10) {
      wsum += w[r[i].second];
      f += v[r[i].second];
      ans[i] = 1;
    }
  }
  cout << "(";
  for (int i = 0; i < 4; i++) {
    if (i < 3) {
      cout << ans[i] << ", ";
    } else {
      cout << ans[i];
    }
  }
  cout << ")" << endl;
}
