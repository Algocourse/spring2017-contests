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
    string s;
    cin >> n >> m >> s;
    vector<char> to(255);
    vector<char> from(255);
    for (char a = 'a'; a <= 'z'; ++a)
        to[a] = from[a] = a;

    for (int i = 0; i < m; ++i) {
        char c1, c2;
        cin >> c1 >> c2;

        char or1 = from[c1];
        char or2 = from[c2];
        to[or1] = c2;
        to[or2] = c1;

        from[c1] = or2;
        from[c2] = or1;
    }

    for (char c : s)
        cout << to[c];
    cout << endl;

    cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

    return 0;
}
