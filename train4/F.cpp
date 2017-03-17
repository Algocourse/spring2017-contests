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

    long long n, k;
    cin >> n >> k;

    vector<long long> d;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i != 0)
            continue;
        long long j = n / i;
        d.push_back(i);
        if (i != j)
            d.push_back(j);
    }

    sort(d.begin(), d.end());

    if ((int) d.size() < k)
        cout << -1 << endl;
    else
        cout << d[k - 1] << endl;


    cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

    return 0;
}
