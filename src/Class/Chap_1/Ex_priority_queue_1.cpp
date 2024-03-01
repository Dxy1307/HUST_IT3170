#include <iostream>
#include <queue>
using namespace std;

void displaypq(priority_queue <int> pq) {
    while(!pq.empty()) {
        cout << pq.top() << " \t";
        pq.pop();
    }

    cout << "\n";
}

int main() {
    priority_queue <int> mypq;
    mypq.push(1);
    mypq.push(3);
    displaypq(mypq);
    mypq.push(60);
    cout << "\nPriority queue after inserting value 60: ";
    displaypq(mypq);
    mypq.push(5);
    cout << "\nPriority queue after inserting value 5: ";
    displaypq(mypq);
    cout << "mypq.size(): " << mypq.size() << endl;
    cout << "mypq.top(): " << mypq.top() << endl;
    cout << "mypq.pop(): ";
    mypq.pop(); 
    displaypq(mypq);

    return 0;
}
// Dxy