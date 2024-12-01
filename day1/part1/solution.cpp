#include <bits/stdc++.h>

typedef std::vector<int> vi;
typedef std::pair<int,int> pi;

using namespace std;

int main() {
    string input = "../input.txt";
    ifstream file(input);

    if (!file.is_open()) {
        cerr << "Couldn't open file " << input << endl;
        return 1;
    }

    vi x_values, y_values;
    int x, y;

    while (file >> x >> y) {
        x_values.push_back(x);
        y_values.push_back(y);
    }

    file.close();

    sort(x_values.begin(), x_values.end());
    sort(y_values.begin(), y_values.end());

    int diff_sum = 0;
    for (int i = 0; i < x_values.size(); i++) {
        diff_sum += abs(x_values[i] - y_values[i]);
    }

    cout << diff_sum;
}