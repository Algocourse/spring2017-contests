#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
using namespace std::chrono;

const int ASIZE = 26;

int main() {
    auto start = high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> cost(ASIZE, 0);
    for (int i = 0; i < ASIZE; ++i)
        cin >> cost[i];

    string s;
    cin >> s;

    vector<map<long long, int>> vmp(ASIZE);

    long long pref = 0;
    long long ans = 0;
    for (char c : s) {
        int id = c - 'a';

        long long cur = pref;
        cur -= cost[id];

        ans += vmp[id][cur];
        ++vmp[id][pref];

        pref += cost[id];
    }

    cout << ans << endl;

    cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

    return 0;
}
