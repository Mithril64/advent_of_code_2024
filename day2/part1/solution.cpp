#include <bits/stdc++.h>
#include <sstream>

typedef std::vector<int> vi;

using namespace std;

bool is_safe_report(const vi& report) {
   if (report.size() < 2) return true;
   bool increasing = true, decreasing = true; 

   for (int i = 1; i < report.size(); i++) {
        int diff = report[i] - report[i - 1];

        if (abs(diff) < 1 || abs(diff) > 3) return false;

        if (diff > 0) decreasing = false;
        if (diff < 0) increasing = false;
   }

   return increasing || decreasing;
}

int main() {
    vector<vi> data;
    string input = "../input.txt";
    ifstream file(input);

    if (!file.is_open()) {
        cerr << "Couldn't open file " << input << endl;
        return 1;
    }

    string line;
    int safe_reports = 0;

    while (getline(file, line)) {
        istringstream iss(line);
        vi row;
        int num;
        while (iss >> num) {
            row.push_back(num);
        }
        data.push_back(row);    
    }
    
    file.close();
    
    for (const auto& d : data) {
        if (is_safe_report(d)) {
            ++safe_reports;
        }
    }
    cout << safe_reports;
    return 0;
}