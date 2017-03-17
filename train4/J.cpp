#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

const unsigned long long INF = 1e+6 + 1;

int main() {
    auto start = high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long A, B, n;
    cin >> A >> B >> n;
    for (int i = 0; i < n; ++i) {
        unsigned long long l, m, t;
        cin >> l >> t >> m;
        --l;

        unsigned long long can_eat = t * m;
        long long bl = l, br = bl + INF, ba = -2;

        while (bl <= br) {
            unsigned long long bm = (bl + br) / 2;
            unsigned long long mh = A + bm * B;
            unsigned long long need_eat = (A + B * l) * (bm - l + 1) + (bm - l + 1) * B * (bm - l) / 2;

            if (mh <= t && need_eat <= can_eat) {
                ba = bm;
                bl = bm + 1;
            } else {
                br = bm - 1;
            }
        }

        cout << ba + 1 << '\n';
    }


    cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

    return 0;
}
