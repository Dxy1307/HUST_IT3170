// Giá trị nhỏ nhất trong khoảng
#include <iostream>
#include <vector>
using namespace std;
const int MaxN = 1 + 1e5;

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(const vector<int> &arr) {
        int n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void build(const vector<int> &arr, int index, int l, int r) {
        if(l == r)
            tree[index] = arr[l];
        else {
            int m = (l + r) / 2;
            build(arr, 2 * index + 1, l, m);
            build(arr, 2 * index + 2, m + 1, r);
            tree[index] = min(tree[2 * index + 1], tree[2 * index + 2]);
        }
    }

    int query(int index, int l, int r, int dl, int dr) {
        if(dl > dr)
            return MaxN;
        if(l == dl && r == dr)
            return tree[index];
        int m = (l + r) / 2;
        return min(query(2 * index + 1, l, m, dl, min(m, dr)), query(2 * index + 2, m + 1, r, max(dl, m + 1), dr));
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    SegmentTree st(arr);

    int m;
    cin >> m;

    int Q = 0;
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        Q += st.query(0, 0, n - 1, a, b);
    }

    cout << Q << endl;

    return 0;
}
// Dxy