// Bài tập trang 77
#include <iostream>
#include <map>
using namespace std;

int main() {
    int numTest, count = 0, n, m, x;

    cin >> numTest;
    while(count != numTest) {
        cin >> n >> m;
        map<int, int> r;

        while(n--) {
            cin >> x;
            r[x]++;
        }

        while(m--) {
            cin >> x;
            r[x]--;
        }
        
        int sopheptinh = 0;
        for(map<int, int>::iterator it = r.begin(); it != r.end(); it++)
            sopheptinh += abs(it->second);
        
        cout << sopheptinh << endl;

        return 0;
    }
}
// Dxy