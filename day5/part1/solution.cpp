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
#define pb push_back
#define mp make_pair()
#define F first
#define S second

#define FOR(i, a, b) for (size_t i = a; i < b; ++i)
#define REP(i, n) for (size_t i = 0; i < n; ++i)

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<int, int> vii;
typedef std::pair<int,int> pi;

void getInput(vector<pi>& firstPart, vvi& secondPart, const string& path) {
    ifstream file(path);
    string line;
    while(getline(file, line)) {
        if(line.empty()) continue;
        if (line.find('|') != string::npos) {
            istringstream iss(line);
            string x,y;
            getline(iss, x, '|');
            getline(iss, y, '|');
            firstPart.emplace_back(stoi(x), stoi(y));
        } else {
            break;
        }
    }

    do {
        if (line.empty()) continue;
        istringstream iss(line);
        string number;
        vi subvector;

        while (getline(iss, number, ',')) {
            subvector.pb(stoi(number));
        } 

        if (!subvector.empty()) {
            secondPart.pb(subvector);
        }
    } while (getline(file, line));

    file.close();
}

// vi sortFirstPart(const vector<pi>& firstPart) {
//    unordered_map<int, vi> graph; 
//    unordered_map<int, int> inDegree;

//     for (auto& p : firstPart) {
//         int x = p.first, y = p.second;
//         graph[x].pb(y);
//         inDegree[y]++;
//         if (inDegree.find(x) == inDegree.end()) {
//             inDegree[x] = 0;
//         }
//     }

//     queue<int> q;
//     vi result;

//     for (auto& [node, degree] : inDegree) {
//         if (degree == 0) {
//             q.push(node);
//         }
//     }

//     while (!q.empty()) {
//         int node = q.front();
//         q.pop();
//         result.pb(node);

//         for (int neighbour : graph[node]) {
//             inDegree[neighbour]--;
//             if (inDegree[neighbour] == 0) {
//                 q.push(neighbour);
//             }
//         }
//     }
    
//     return result;
// }

bool isSubvectorSolved(const vector<pi>& firstPart, const vi& subvector) {
    // Create a map to store which pages must come before others
    unordered_map<int, unordered_set<int>> mustComeBefore;
    
    // Populate the constraints based on the first part (ordering rules)
    for (const auto& rule : firstPart) {
        mustComeBefore[rule.second].insert(rule.first);
    }

    // Check every pair of pages in the subvector
    for (size_t i = 0; i < subvector.size(); ++i) {
        for (size_t j = i + 1; j < subvector.size(); ++j) {
            // If there's a rule that x must come before y
            if (mustComeBefore[subvector[j]].count(subvector[i]) == 0 &&
                mustComeBefore[subvector[i]].count(subvector[j]) > 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    FAST_IO;
    string path = "../input.txt"; // Adjust if needed
    ifstream file(path);

    if (!file.is_open()) {
        cerr << "Couldn't open file " << path << endl;
        return 1;
    }

    vector<pi> firstPart;
    vvi secondPart;
    string line;

    getInput(firstPart, secondPart, path);
    vi sortedValues = sortFirstPart(firstPart);
    st sum = 0;

    for (auto& subVect : secondPart) {
        if (isSubvectorSolved(firstPart, subVect)) {
            sum += subVect[subVect.size() / 2];
        }
    }

    cout << sum;
    return 0;
}
