// tạo một deque có 5 phần tử đều có giá trị là 100. Tạo một mảng int có 3
// phần tử lần lượt là 200, 300, 400
#include <iostream>
#include <queue>
using namespace std;

int main() {
    deque<int> myDeque(5, 100);
    int myArr[] = {200, 300, 400};

    myDeque.insert(myDeque.begin(), myArr, myArr + 2);
    cout << "Deque contains: \n";
    for(int i = 0; i < myDeque.size(); ++i)
        cout << myDeque[i] << " ";

    cout << endl;
    
    myDeque.insert(myDeque.begin() + 1, myArr, myArr + 2);
    cout << "Deque contains: \n";
    for(int i = 0; i < myDeque.size(); ++i)
        cout << myDeque[i] << " ";
    
    return 0;
}