#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

const int ASIZE = 26;

int main() {
    auto start = high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, p;
    cin >> s >> p;

    vector<int> in_p(ASIZE, 0);
    for (char c : p)
        ++in_p[c - 'a'];

    vector<int> in_s(ASIZE, 0);
    size_t l = 0, r = -1;
    while (r + 1 < s.length() && r - l + 1 < p.length()) {
        ++r;
        if (s[r] != '?')
            ++in_s[s[r] - 'a'];
    }

    int ans = 0;
    while (r < s.length()) {
        bool ok = r - l + 1 == p.length();
        for (int i = 0; i < ASIZE; ++i)
            if (in_s[i] > in_p[i])
                ok = false;
        if (ok)
            ++ans;

        if (s[l] != '?')
            --in_s[s[l] - 'a'];
        ++l;
        if (r + 1 < s.length())
            ++in_s[s[r + 1] - 'a'];
        ++r;
    }

    cout << ans << endl;

    cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

    return 0;
}
