//Viết chương trình cho người dùng nhập vào kích thước stack và nhập
// vào giá trị các phần tử. Sau đó, loại bỏ đi một nửa các phần tử ở đỉnh stack.
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> myStack;
    int n;
    cout << "Size: "; cin >> n;

    int temp;
    for(int i = 0; i < n; ++i) {
        cin >> temp;
        myStack.push(temp);
    }

    for(int i = 0; i < n/2; ++i)
        myStack.pop();

    n = myStack.size();
    for(int i = 0; i < n; ++i) {
        temp = myStack.top();
        myStack.pop();
        cout << temp << " ";
    }
    
    return 0;
}
// Dxy