#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pi;

void displaypq(priority_queue<pi, vector<pi>, greater<pi>> pq) {
    while(!pq.empty()) {
        pair<int, int> top = pq.top();
        cout << "(" << top.first << ", " << top.second << ") \t";
        pq.pop();
    }

    cout << "\n";
}

int main() {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push(make_pair(30, 100));
    pq.push(make_pair(10, 200));
    pq.push(make_pair(20, 100));
    displaypq(pq);
    pq.push(make_pair(10, 100));
    cout << "\nPriority queue after inserting pair (10, 100):\n "; displaypq(pq);
    cout << "pq.size(): " << pq.size() << endl;
    pair<int, int> top = pq.top();
    cout << "pq.top(): (" << top.first << ", " << top.second << ")" << endl;
    cout << "pq.pop(): "; pq.pop(); displaypq(pq);
    
    return 0;
}
// Dxy