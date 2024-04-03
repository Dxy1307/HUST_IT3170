// Cut Material
#include <iostream>

using namespace std;
int h, w;
int n;
int sub[11][2];

bool canCut(int usedH, int usedW, int i) {
	if (i == n) {
	    return usedH == h && usedW == w;
	}

    // cắt 1 hình theo chiều rộng của hình chính, và theo chiều rộng của hình con
	if (sub[i][0] <= w - usedW) {
	    if (canCut(usedH, usedW + sub[i][0], i + 1)) {
	      	return true;
	    }
	}

    // cắt 1 hình theo chiều cao của hình chính, và theo chiều rộng của hình con
    if (sub[i][0] <= h - usedH) {
    	if (canCut(usedH + sub[i][0], usedW, i + 1)) {
      		return true;
    	}
  	}

    // cắt 1 hình theo chiều rộng của hình chính, và theo chiều cao của hình con
  	if ( sub[i][1] <= w - usedW) {
	    if (canCut(usedH, usedW +  sub[i][1], i + 1)) {
	      	return true;
	    }
	}
    
    // cắt 1 hình theo chiều cao của hình chính, và theo chiều cao của hình con
	if (sub[i][1] <= h - usedH) {
	    if (canCut(usedH + sub[i][1], usedW, i + 1)) {
	      	return true;
	    }
	}

  	return false;
}

int main() {
    cin >> h >> w;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> sub[i][0]  >> sub[i][1];
    }

    if (canCut(0, 0, 0)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
// Dxy