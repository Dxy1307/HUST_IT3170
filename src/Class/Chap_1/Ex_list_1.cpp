#include <iostream>
#include <list>
using namespace std;

bool single_digit(const int& value) {
    return (value < 10);
}

struct is_odd {
    bool operator() (const int& value) {
        return (value%2) == 1;
    }
};

int main() {
    int myArr[] = {17, 1, 10, 2, 20, 3, 30, 4, 15, 40};
    list<int> myList(myArr, myArr + 10);// 17 1 10 2 20 3 30 4 15 40

    // loại bỏ các phần tử có 1 chữ số ra khỏi list
    myList.remove_if(single_digit); // 17 10 20 30 15 40
    cout << "myList sau khi xoa cac so co 1 chu so: \n";
    for (list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        cout << *it << " ";
    
    // loại bỏ các phần tử lẻ ra khỏi list
    myList.remove_if(is_odd());// 10 20 30 40
    cout << endl << "myList sau khi xoa cac so le: \n";
    for(list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        cout << *it << " ";

    return 0;
}
// Dxy