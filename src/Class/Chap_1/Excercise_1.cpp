// Bài tập 1 trang 69
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> a;

int main() {
    cin >> n;
    long long p, r;
    for(int i = 0; i < n; ++i) {
        cin >> p >> r;
        a.push_back(make_pair(r, p));
    }

    sort(a.begin(), a.end());
    priority_queue<int, vector<int>, greater<int>> Q;

    int t = 0; // thời điểm hiện tại
    int i = 0, res = 0;
    while(i < n || !Q.empty()) {
        if(Q.empty()) {
            t = a[i].first;
            Q.push(a[i].second);
            i++;
        } else {
            if(i < n) {
                // tính lượng time tính từ thời điểm hiện tại t
                // đến khi có thể bắt đầu thực hiện công việc i
                int remain = a[i].first - t;
                if(remain < Q.top()) {
                    // thực hiện công việc hiện tại cho đến thời điểm có thể bắt đầu thực hiện việc i
                    int u = Q.top();
                    Q.pop();
                    Q.push(u - remain);// cập nhật lại thời gian còn lại để hoàn thành cv hiện tại                    
                    Q.push(a[i].second); // bổ sung thời gian thực hiện công việc i vào Q
                    t = a[i].first;
                    i++;                    
                } else {
                    t += Q.top(); // thực hiện cv hiện tại đến khi hoàn thành nó
                    res += t;
                    Q.pop();
                }
            } else {
                t += Q.top();
                res += t;
                Q.pop();
            }
        }
    }

    printf("%.2f", 1.0*res/n);

    return 0;
}
// Dxy