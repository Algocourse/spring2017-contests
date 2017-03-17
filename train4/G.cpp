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
    long long l = 0, r = n, ans = n;
    while (l <= r) {
        int m = (l + r) / 2;

        long long lines = 0;
        long long divisor = 1;
        while (m / divisor > 0) {
            lines += m / divisor;
            divisor *= k;
        }

        if (lines < n) {
            l = m + 1;
        } else {
            r = m - 1;
            ans = m;
        }
    }

    cout << ans << endl;


    cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

    return 0;
}
