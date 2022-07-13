#include <bits/stdc++.h>

using namespace std;

struct Cow {
  int i;
  int x, y;
  int stop;
};

int main(int argc, char **argv) {
  int N;
  cin >> N;
  vector<Cow> northCows, eastCows;
  for (int i = 0; i < N; ++i) {
    char dir;
    int x, y;
    cin >> dir >> x >> y;
    if (dir == 'E') {
      eastCows.push_back(Cow{i, x, y, INT_MAX});
    } else {
      northCows.push_back(Cow{i, x, y, INT_MAX});
    }
  }

  // sort both by closest to origin
  sort(northCows.begin(), northCows.end(),
            [](auto a, auto b) { return a.x < b.x; });
  sort(eastCows.begin(), eastCows.end(),
            [](auto a, auto b) { return a.y < b.y; });

  // find intersections
  for (Cow &east : eastCows) {
    for (Cow &north : northCows) {
      
      // if the cow has already stopped then we dont need to consider it
      if (east.stop != INT_MAX || north.stop != INT_MAX) continue;

      // if the cows paths are not crossing
      if (east.x >= north.x || north.y >= east.y)
        continue;

      // if they cross when both get to the same point at the same time then
      // theres nothing we need to check
      if (north.x - east.x == east.y - north.y)
        continue;

      // east crosses the crossing point first
      if (north.x - east.x < east.y - north.y) {
        // eastward cow stops the northward cow
        north.stop = east.y;
      } else {
        // eastward cow stops the northward cow
        east.stop = north.x;
      }
    }
  }

  vector<string> res(N);

  for (int i = 0; i < northCows.size(); ++i) {
    if (northCows[i].stop == INT_MAX)
      res[northCows[i].i] = "Infinity";
    else
      res[northCows[i].i] = to_string(northCows[i].stop - northCows[i].y);
  }

  for (int i = 0; i < eastCows.size(); ++i) {
    if (eastCows[i].stop == INT_MAX)
      res[eastCows[i].i] = "Infinity";
    else
      res[eastCows[i].i] = to_string(eastCows[i].stop - eastCows[i].x);
  }

  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] << "\n";
  }

  return 0;
}
