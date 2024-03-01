#include <iostream>
#include <queue>
#include <utility>
using namespace std;

void displaypq(priority_queue <pair<int,int>> pq) {
    while(!pq.empty()) {
        pair<int,int> top = pq.top();
        cout << "(" << top.first << ", " << top.second << ") \t";
        pq.pop();
    }
    cout << "\n";
}

int main() {
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(10, 200));
    pq.push(make_pair(20, 100));
    displaypq(pq);
    pq.push(make_pair(15, 400));
    cout << "\nPriority queue after inserting pair (15, 400): \n";
    displaypq(pq);
    cout << "pq.size(): " << pq.size() << endl;
    pair<int, int> top = pq.top();
    cout << "pq.top(): (" << top.first << ", " << top.second << ")" << endl;
    cout << "pq.pop(): "; pq.pop(); displaypq(pq);

    return 0;    
}
// Dxy