#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;

    for (int i : v) {
        if (pq.empty()) {
            ++ans;
            pq.push(1);
        } else {
            int top = pq.top();
            if (top <= i) {
                pq.pop();
                pq.push(top + 1);
            } else {
                pq.push(1);
                ++ans;
            }
        }
    }

    cout << ans << endl;

    cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

    return 0;
}
