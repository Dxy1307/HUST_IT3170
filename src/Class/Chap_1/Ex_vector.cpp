#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> myVector(5, 100); // tạo vector 5 phần tử: 100 100 100 100 100
    vector<int>::iterator it; // khai báo iterator
    it = myVector.begin();
    // thêm 200 vào vị trí thứ 2
    myVector.insert(it + 1, 200);// 100 200 100 100 100 100
    // thêm 2 giá trị 5 vào đầu vector
    myVector.insert(myVector.begin(), 2, 5);// 5 5 100 200 100 100 100 100

    for(int i = 0; i < myVector.size(); ++i) 
        cout << myVector[i] << " ";

cout << endl;
        
    vector<int> vec1(5, 100); // 100 100 100 100 100
    vector<int> vec2(3, 2); // 2 2 2
    // chèn toàn bộ vec2 vào trước phần tử thứ 2 của vec1
    vec1.insert(vec1.begin() + 1, vec2.begin(), vec2.end());// 100 2 2 2 100 100 100 100

    // create array
    int myArr[3] = {3, 4, 5};
    // chèn 2 phần tử đầu tiên của myArr vào trước phần tử thứ nhất của vector vec1
    vec1.insert(vec1.begin(), myArr, myArr + 2); // 3 4 100 2 2 2 100 100 100 100

    for(int i = 0; i < vec1.size(); ++i)
        cout << vec1[i] << " ";    

cout << endl;

    return 0;    
}
// Dxy