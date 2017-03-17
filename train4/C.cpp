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

    int n, m;
    cin >> n >> m;
    vector<string> vs(n);
    for (int i = 0; i < n; ++i)
        cin >> vs[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            vs[i][j] = vs[i][j] == '-' ? '-' : ((i + j) % 2 == 0 ? 'B' : 'W');
    for (int i = 0; i < n; ++i)
        cout << vs[i] << endl;

    cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

    return 0;
}
