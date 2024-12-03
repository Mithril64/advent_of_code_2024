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

    regex mul_exp(R"(mul\((\d{1,3}),(\d{1,3})\))");
    regex do_exp(R"(do\(\))");
    regex dont_exp(R"(don't\(\))");

    smatch res;
    string original;
    string line;
    while (getline(file, line)) {
        original += line;
    }

    auto mul_matches_begin = sregex_iterator(all(original), mul_exp);
    auto mul_matches_end = sregex_iterator();

    auto do_matches = sregex_iterator(all(original), do_exp);
    auto dont_matches = sregex_iterator(all(original), dont_exp);

    bool is_enabled = true;

    vector<pair<size_t, bool>> commands;
    for (auto it = do_matches; it != sregex_iterator(); ++it) {
        commands.emplace_back(it->position(), true);
    }
    for (auto it = dont_matches; it != sregex_iterator(); ++it) {
        commands.emplace_back(it->position(), false);
    }
    
    sort(all(commands));

    int ans = 0;
    size_t last_command_pos = 0;

    for (auto it = mul_matches_begin; it != mul_matches_end; ++it) {
        smatch match = *it;

        while (!commands.empty() && commands.front().first < it->position()) {
            is_enabled = commands.front().second;
            commands.erase(commands.begin());
            
        }

        if (is_enabled) {
            string first_number = match[1];
            string second_number = match[2];

            ans += stoi(first_number) * stoi(second_number);
        }
    }
    cout << ans;

    return 0;
}
