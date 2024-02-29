// tạo list chứa các phần tử kiểu string bao gồm "AAAA", "BBB", "CC", "D"
// sắp xếp lại các phần tử trong list theo chiều tăng dần độ dài xâu
#include <iostream>
#include <list>
#include <string.h>
using namespace std;

bool compare_string(const string& first, const string& second) {
    if(first.length() < second.length()) 
        return true;
    else return false;
}

int main() {
    string myArr[] = {"AAAA", "BBB", "CC", "D"};
    list<string> myList(myArr, myArr + 4);

    myList.sort(compare_string);

    cout << "myList contains: \n";
    for(list<string>::iterator it = myList.begin(); it != myList.end(); it++)
        cout << *it << " ";

    return 0;
}
// Dxy