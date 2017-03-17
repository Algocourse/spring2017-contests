#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a;
    a.reserve(n);
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        if (tmp & 1)
            a.push_back(tmp);
        else
            ans += tmp;
    }

    sort(a.begin(), a.end());
    while (a.size() >= 2) {
        ans += a.back();
        a.pop_back();
        ans += a.back();
        a.pop_back();
    }

    cout << ans << endl;

    return 0;
}
