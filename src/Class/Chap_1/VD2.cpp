// Bài toán Integer Inquiry
#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char s[102];
    int sum[102] = {0}, i, j, length;
    while (gets(s)) {
        if(!strcmp(s, "0")) break;
        length = strlen(s);
        for(i = 0, j = length - 1; i < length; ++i, --j)
            sum[i] += s[j] - '0';
    }
    // Xử lý nhớ
    for(i = 0; i < 102; ++i) {
        if(sum[i] >= 10) {
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
        }
    }
    // In kết quả
    i = 101;
    while(sum[i] == 0 && i >= 0) --i;
    if(i == -1) printf("0");
    else {
        for(; i >= 0; --i) 
            printf("%d", sum[i]);
    }
    return 0;
}
// Dxy