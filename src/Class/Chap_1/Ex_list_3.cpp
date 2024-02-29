// Cho một list bao gồm các 8 số thập phân: 1.1,2.5,3.1,4.7,1.4,2.4,3.5,4.2. Giả sử các
// số thập phân có phần nguyên giống nhau thì được xem là một số duy nhất. Hãy loại bỏ các
// phần tử sao cho các phần tử giống nhau chỉ xuất hiện 1 lần
#include <iostream>
#include <list>
using namespace std;

bool same_integral_part(double fi, double se) {
    return (int(fi) == int(se));
}

int main() {
    double myArr[] = {1.1, 2.5, 3.1, 4.7, 1.4, 2.4, 3.5, 4.2};
    list<double> myList(myArr, myArr + 8);

    // trước khi dùng hàm unique phải sort
    myList.sort();

    // giữ lại 1 số nếu phần nguyên = nhau
    myList.unique(same_integral_part);
    cout << "myList contains: \n";
    for(list<double>::iterator it = myList.begin(); it != myList.end(); it++)
        cout << *it << " ";

    return 0;
}
// Dxy