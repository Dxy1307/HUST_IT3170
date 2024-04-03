// Inversion
#include <iostream>
using namespace std;
#define MAX 1000006
int a[MAX], n;
int mod = 1e9 + 7;
int temp[MAX];

int _merge(int left, int right, int mid) {
    int i = left, j = mid + 1, inv_count = 0;
    int k = left;
    while((i <= mid) && (j <= right)) {
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
            inv_count = (inv_count + mid - i + 1) % mod;
        }
    }
    while(i <= mid) temp[k++] = a[i++];
    while(j <= right) temp[k++] = a[j++];
    for(int i = left; i <= right; i++) a[i] = temp[i];
    return inv_count % mod;
}

int mergeSort(int left, int right) {
    int inv_count = 0;
    if(left < right) {
        int mid = (left + right) / 2;
        inv_count = (inv_count + mergeSort(left, mid)) % mod;
        inv_count = (inv_count + mergeSort(mid + 1, right)) % mod;
        inv_count = (inv_count + _merge(left, right, mid)) % mod;
    }
    return inv_count % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];

    cout << mergeSort(1, n);
}
// Dxy