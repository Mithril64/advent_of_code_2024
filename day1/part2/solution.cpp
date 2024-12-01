#include <bits/stdc++.h>

typedef std::vector<int> vi;
typedef std::map<int, int> mii;
typedef std::set<int> si;

using namespace std;

int main() {
    string input = "../input.txt";
    ifstream file(input);

    if (!file.is_open()) {
        cerr << "Couldn't open file " << input << endl;
        return 1;
    }

    si x_values;
    mii y_frequencies;
    int x, y;

    while (file >> x >> y) {
        if(y_frequencies.count(y) > 0) {
            y_frequencies[y]++;
        } else {
            y_frequencies.insert({y, 1});
        }
        x_values.insert(x);
    }

    file.close();

    int ans = 0;
    for(auto itr = x_values.begin(); itr != x_values.end(); itr++) {
        if (y_frequencies.count(*itr) > 0) {
            ans += y_frequencies[*itr] * *itr;
        }
    }
    cout << ans;
}