// Cộng 2 số nguyên lớn
#include <iostream>
#include <algorithm>
using namespace std;

// Cách 1
string Sum(string a, string b) {
    while(a.length() < b.length()) a = '0' + a;
    while(b.length() < a.length()) b = '0' + b;

    string res;
    int sum, nho = 0;
    int n = a.length();
    for(int i = n - 1; i >= 0; --i) {
        sum = (a[i] - '0') + (b[i] - '0') + nho;
        nho = sum / 10;
        res = char(sum%10 + '0') + res;
    }
    if(nho == 1) res = '1' + res;
    return res;
}

// Cách 2
string SumV2(string a, string b) {
    // Xâu a luôn có độ dài lớn hơn xâu b
    if(a.length() < b.length()) swap(a, b);
    string res = "";
    int n1 = a.length(), n2 = b.length();
    // Đảo ngược 2 xâu
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int nho = 0;
    for(int i = 0; i < n2; ++i) {
        int sum = (a[i] - '0') + (b[i] - '0') + nho;
        res.push_back(sum % 10 + '0');
        nho = sum / 10;
    }
    for(int i = n2; i < n1; ++i) {
        int sum = (a[i] - '0') + nho;
        res.push_back(sum % 10 + '0');
        nho = sum / 10;
    }
    if(nho) res.push_back(nho + '0');
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    string a, b;
    cin >> a >> b;
    cout << Sum(a, b) << endl;
    cout << SumV2(a, b) << endl;
}
// Dxy