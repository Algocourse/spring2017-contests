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

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int w, h;
        cin >> w >> h;
        long long tmp = max(a[0], a[w - 1]);
        cout << tmp << '\n';
        a[0] = tmp + h;
    }

    cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

    return 0;
}
