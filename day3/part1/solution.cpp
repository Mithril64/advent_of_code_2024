#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using ll = long long;
using ull = unsigned long long;
using ld = long double;

const ll MOD = 1e9 * 7;
const ll INF = 1e18;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back()
#define mp make_pair()
#define F first
#define S second

#define FOR(i, a, b) for (size_t i = a; i < b; ++i)
#define REP(i, n) for (size_t i = 0; i < n; ++i)

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<int, int> vii;

int main() {
    FAST_IO;
    string path = "../input.txt"; // Adjust if needed
    ifstream file(path);

    if (!file.is_open()) {
        cerr << "Couldn't open file " << path << endl;
        return 1;
    }

    regex exp(R"(mul\((\d{1,3}),(\d{1,3})\))");
    smatch res;
    string original;
    string line;
    while(getline(file, line)) {
        original += line;
    }

    auto matches_begin = sregex_iterator(all(original), exp);
    auto matches_end = sregex_iterator();
    int ans = 0;
    
    for (auto it = matches_begin; it != matches_end; ++it) {
        smatch match = *it;
        string first_number = match[1];
        string second_number = match[2];

        ans += stoi(first_number) * stoi(second_number);
    }

    cout << ans;

    return 0;
}
