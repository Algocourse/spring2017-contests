#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t, s, x;
    cin >> t >> s >> x;

    if (x == t) {
        cout << "YES\n";
    } else if (x < t + s) {
        cout << "NO\n";
    } else {
        x -= t;
        x -= s;

        if (x % s <= 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }


    cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

    return 0;
}
