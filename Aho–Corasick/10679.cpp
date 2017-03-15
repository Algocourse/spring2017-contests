#include <iostream>
#include <cassert>
#include <queue>

using namespace std;

const int ASIZE = 122 - 65 + 1;
const int START = 65;
const int LIM = 1000 * 1000;

struct node {
    int sufflink = -1;
    int p = 0;
    int child[ASIZE];
    int nxt[ASIZE];
    vector<int> used;

    node() {
        for (int i = 0; i < ASIZE; ++i)
            nxt[i] = child[i] = -1;
    }

    void clear() {
        sufflink = -1;
        p = 0;
        used.clear();
        for (int i = 0; i < ASIZE; ++i)
            nxt[i] = child[i] = -1;
    }
};

struct trie_t {
    node data[LIM];
    int size = 1;
    int root = 0;

    void clear() {
        size = 1;
        root = 0;
        data[root].clear();
        data[root].p = root;
    }

    trie_t() {
        data[root].p = root;
    }

    void add(const string& s, int id) {
        int state = root;
        for (char c : s) {
            int to = (c - START);
            if (data[state].child[to] == -1) {
                data[state].child[to] = size;
                data[size].clear();
                data[size].p = state;
                ++size;
            }
            state = data[state].child[to];
        }
        data[state].used.push_back(id);
    }

    void init_links() {
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == root) {
                data[u].sufflink = root;
                for (int i = 0; i < ASIZE; ++i)
                    data[u].nxt[i] = data[u].child[i] == -1 ? root : data[u].child[i];
            } else {
                int p = data[u].p;
                int c = -1;
                for (int i = 0; i < ASIZE; ++i)
                    if (data[p].child[i] == u)
                        c = i;
                assert(c != -1);

                int tmp = data[p].sufflink;
                data[u].sufflink = p == root ? root : data[tmp].nxt[c];

                for (int i = 0; i < ASIZE; ++i) {
                    if (data[u].child[i] != -1)
                        data[u].nxt[i] = data[u].child[i];
                    else
                        data[u].nxt[i] = data[data[u].sufflink].nxt[i];
                }
            }

            for (int i = 0; i < ASIZE; ++i)
                if (data[u].child[i] != -1)
                    q.push(data[u].child[i]);
        }
    }

    vector<int> check_fast(const string& s) {
        vector<int> res;

        int state = root;
        for (int i : data[state].used)
            res.push_back(i);
        data[state].used.clear();
        for (char c : s) {
            int to = (c - START);
            state = data[state].nxt[to];

            for (int i : data[state].used)
                res.push_back(i);
            data[state].used.clear();
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    trie_t trie;

    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        trie.clear();

        string text;
        cin >> text;

        int n;
        cin >> n;

        vector<bool> used(n, false);

        string buf;
        for (int i = 0; i < n; ++i) {
            cin >> buf;
            trie.add(buf, i);
        }

        trie.init_links();

        vector<int> res = trie.check_fast(text);
        for (int i : res)
            used[i] = true;

        for (int i = 0; i < n; ++i)
            cout << (used[i] ? 'y' : 'n') << '\n';
    }

    return 0;
}
