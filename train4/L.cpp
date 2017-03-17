#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

const int ASIZE = 26;

struct node_t {
    int l = -1, r = -1;
    vector<int> cnt = vector<int>(ASIZE, 0);
    char val = 0;
};

struct segment_tree_t {
    vector<node_t> tree;
    int root = 0;
    int n;

    segment_tree_t(const string& s) {
        tree.resize(s.length() * 2);
        n = s.length() - 1;
        build(root, 0, n, s);
    }

    void build(int v, int l, int r, const string& s) {
        if (l == r) {
            tree[v].val = s[l];
            tree[v].cnt[s[l] - 'a'] = 1;
            return;
        }

        int m = (l + r) / 2;

        tree[v].l = tree.size();
        tree.emplace_back();
        build(tree[v].l, l, m, s);
        tree[v].r = tree.size();
        tree.emplace_back();
        build(tree[v].r, m + 1, r, s);
        update(v);
    }

    void show() {
        show(root, 0, n);
        cout << endl;
    }

    void update(int v) {
        for (int i = 0; i < ASIZE; ++i)
            tree[v].cnt[i] = tree[tree[v].l].cnt[i] + tree[tree[v].r].cnt[i];
    }

    void show(int v, int l, int r) {
        if (l == r) {
            if (tree[v].val)
                cout << tree[v].val;
            return;
        }

        int m = (l + r) / 2;
        show(tree[v].l, l, m);
        show(tree[v].r, m + 1, r);
    }

    void remove(int sid, int id) {
        remove(root, 0, n, sid, id);
    }

    void remove(int v, int l, int r, int sid, int id) {
        if (l == r) {
            tree[v].val = 0;
            tree[v].cnt[sid] = 0;
            return;
        }

        int m = (l + r) / 2;

        if (tree[tree[v].l].cnt[sid] < id)
            remove(tree[v].r, m + 1, r, sid, id - tree[tree[v].l].cnt[sid]);
        else
            remove(tree[v].l, l, m, sid, id);

        update(v);
    }
};

int main() {
    auto start = high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    string s = "", buf;
    cin >> k >> buf;
    for (int i = 0; i < k; ++i)
        s += buf;

    segment_tree_t st(s);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int id;
        char c;
        cin >> id >> c;
        st.remove(c - 'a', id);
    }

    st.show();

    cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

    return 0;
}
