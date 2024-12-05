#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using st = size_t;

const ll MOD = 1e9 * 7;
const ll INF = 1e18;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb(vect, val) vect.push_back(val)
#define mp make_pair
#define F first
#define S second

#define FOR(i, a, b) for (size_t i = a; i < b; ++i)
#define REP(i, n) for (size_t i = 0; i < n; ++i)

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<int, int> vii;
typedef std::pair<int, int> pi;

namespace aoc
{
  struct Point_2D
  {
    long long x_;
    long long y_;
  };

  constexpr Point_2D DIRS_2D_8[8] = { { -1, -1 }, { 0, -1 }, { 1, -1 },
                                      { -1,  0 },            { 1,  0 },
                                      { -1,  1 }, { 0,  1 }, { 1,  1 } };
}

void run(const vector<string>& map)
{
  int p1_total = 0;
  constexpr array<char, 4> xmas = { 'X', 'M', 'A', 'S' };
  for (ll y = 0; y < map.size(); ++y) {
    for (ll x = 0; x < map[0].size(); ++x) {
      if (map[y][x] == 'X') {
        for (aoc::Point_2D offset : aoc::DIRS_2D_8) {
          bool pass = true;
          for (int letter = 1; pass && letter < xmas.size(); ++letter) {
            ll new_x = x + (letter * offset.x_);
            ll new_y = y + (letter * offset.y_);
            if (new_x < 0 || new_x >= map[0].size() ||
                new_y < 0 || new_y >= map.size()    ||
                map[new_y][new_x] != xmas[letter]) {
              pass = false;
            }
          }
          if (pass) {
            ++p1_total;
          }
        }
      }
    }
  }
  std::cout << "PART ONE: " << p1_total << '\n';

  int p2_total = 0;
  for (int y = 1; y < map.size() - 1; ++y) {
    for (int x = 1; x < map[0].size() - 1; ++x) {
      if (map[y][x] == 'A') {
        int count = 0;
        constexpr std::array<int, 4> corners = { 0, 2, 5, 7 };
        for (int corner_i = 0, dir = 0;
             count < 2 && corner_i < 4;
             dir = corners[++corner_i]) {
          auto [ x_offset, y_offset ] = aoc::DIRS_2D_8[dir];
          if (map[y +  y_offset][x +  x_offset] == 'M' &&
              map[y + -y_offset][x + -x_offset] == 'S') {
            ++count;
          }
        }
        if (count == 2) {
          ++p2_total;
        }
      }
    }
  }
  std::cout << "PART TWO: " << p2_total << '\n';
}

int main() {
    FAST_IO;
    string path = "../input.txt"; // Adjust if needed
    ifstream file(path);

    if (!file.is_open()) {
        cerr << "Couldn't open file " << path << endl;
        return 1;
    }

    std::vector<string> grid;
    string line;
    while (getline(file, line)) {
        pb(grid, line);
    }

    run(grid);

    return 0;
}
